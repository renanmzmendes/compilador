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
    entrada = fopen("/Users/renanmzmendes/compilador/Projeto/in.txt", "r");
    //verificando se arquivo existe
    if(entrada == NULL) {
        printf("arquivo nao encontrado\n\n");
        return -1;
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
        
        // Procura transição
        if(!procuraTransicao(estadoCorrente, token, &trans)) {
            
            // Se não encontrar transição procura chamada de submáquina
            if(!procuraChamadaSubmaquina(estadoCorrente, token, &chamada)) {
                // Caso não encontra chamada de submáquina, verifica se é estado final,
                // se for aceita, senão dá erro
                if(estadoFinal(estadoCorrente)) {
                    estadoCorrente = desempilha();
                    
                    semantico_tbd();
                } else {
                    printf("Erro no reconhecimento de sintaxe, linha %d", token->linha);
                    getchar();
                    exit(-1);
                }
            } else { // Se acha chamada de submáquina
                estadoCorrente = chamada.estadoDestino;
                empilha(chamada.estadoRetorno);
                                
                semantico_tbd();
            }
            
        } else { // Se encontrar transição
            estadoCorrente = trans.estadoDestino;            
            token = getNextToken(entrada);
            
            semantico_tbd();
        }
	}	
	
    free(token);
	return 0;
}
