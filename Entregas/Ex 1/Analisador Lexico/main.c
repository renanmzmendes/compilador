#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Token.h"

#define MAX 30

#define TRUE 0
#define FALSE 1

int main()
{
       
    int linha=0,coluna=1;
    char ch='\0';
	Token *novoToken;
	novoToken = (Token *) malloc(sizeof(Token));

	FILE *entrada;
    entrada = fopen("in.txt", "r");
    //verificando se arquivo existe
    if(entrada==NULL)
    {
     printf("arquivo nao encontrado\n\n");
     return FALSE;
    }
	
	printf("Linha  Coluna     Token     Tipo\n");
// Lendo o Arquivo pegando todos os Tokens até terminar o arquivo o ch deve iniciar com NULL
	while (novoToken->tipo != EoF){//	ch!='\377') {
		novoToken = getNextToken(&*entrada, &ch, &linha, &coluna);
	}
	
	return TRUE;
}
