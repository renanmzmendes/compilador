#include <stdio.h>
#include <stdlib.h>
#include "Lexico.h"

#define MAX 30

#define TRUE 0
#define FALSE 1

int main()
{	
	Token *novoToken;
	novoToken = (Token *) malloc(sizeof(Token));

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
	
	printf("Linha  Coluna     Token     Tipo\n");
    //Lendo o Arquivo pegando todos os Tokens até terminar o arquivo o ch deve iniciar com NULL
	do {
		novoToken = getNextToken(&*entrada);
		imprimirToken(novoToken);
	} while (novoToken->tipo != EoF);
	
	
	return TRUE;
}
