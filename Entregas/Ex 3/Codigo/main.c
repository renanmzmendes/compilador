#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"
#include "Sintatico.h"
#include "ConstantesSintatico.h"
#include "TabelasSintatico.h"

#define MAX 30
#define MAX_SIZE 50

int main() {	
	Token *token;
	token = (Token*) malloc(sizeof(Token));

	FILE *entrada;
    entrada = fopen("./in.txt", "r");
    //verificando se arquivo existe
    if(entrada == NULL) {
        printf("arquivo nao encontrado\n\n");
        return 0;
    }
	
	InicializaLexico();
	//ImprimirTabelaLexico(); //se quiser ver a tabela de estados
	
	//printf("Linha  Coluna     Token     Tipo\n");
    //Lendo o Arquivo pegando todos os Tokens até terminar o arquivo o ch deve iniciar com NULL
    StackInit(&pilha, MAX_SIZE);
    Estado estadoCorrente = PROGRAM_INICIAL;
    token = getNextToken(entrada);
	while (token->tipo != EoF) {
        
        transicao trans;
        chamadaSubmaquina chamada;
        
        if(!procuraTransicao(estadoCorrente, token, &trans)) {
            
            if(!procuraChamadaSubmaquina(estadoCorrente, token, &chamada)) {
                if(estadoFinal(estadoCorrente)) {
                    estadoCorrente = desempilha();
                    
                    semantico_tbd();
                } else {
                    printf("Erro no reconhecimento de sintaxe, linha %d", token->linha);
                    getchar();
                    exit(0);
                }
            } else {
                estadoCorrente = chamada.estadoDestino;
                empilha(chamada.estadoRetorno);
                                
                semantico_tbd();
            }
            
        } else {
            estadoCorrente = trans.estadoDestino;            
            token = getNextToken(entrada);
            
            semantico_tbd();
        }
	}	
	
    free(token);
	return 1;
}
