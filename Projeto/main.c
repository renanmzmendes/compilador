#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"
#include "Sintatico.h"
#include "ConstantesSintatico.h"
#include "TabelasSintatico.h"

#define MAX 30
#define MAX_SIZE 50

#define TRUE 0
#define FALSE 1

int main()
{	
	Token *token;
	token = (Token*) malloc(sizeof(Token));

	FILE *entrada;
    entrada = fopen("./in.txt", "r");
    //verificando se arquivo existe
    if(entrada==NULL)
    {
     printf("arquivo nao encontrado\n\n");
     return FALSE;
    }
	
	InicializaLexico();
	//ImprimirTabelaLexico(); //se quiser ver a tabela de estados
	
	//printf("Linha  Coluna     Token     Tipo\n");
    //Lendo o Arquivo pegando todos os Tokens até terminar o arquivo o ch deve iniciar com NULL
    StackInit(&pilha, MAX_SIZE);
    int estadoCorrente = PROGRAM_INICIAL;

	do {
        token = getNextToken(entrada);
        
        transicao* trans = 0;
        chamadaSubmaquina* chamada = 0;
        
        procuraTransicao(estadoCorrente, token, trans);
        if(trans == 0) {
            procuraChamadaSubmaquina(estadoCorrente, token, chamada);
            
            if(chamada == 0) {
                printf("Erro no reconhecimento de sintaxe, linha %d", token->linha);
                getchar();
                exit(-1);
            }
            
            while(!aceita(estadoCorrente)) {
                
            }
            
            
        } else {
            
        }
        
        free(trans);
        free(chamada);
	} while (token->tipo != EoF);
	
	
    free(token);
	return TRUE;
}
