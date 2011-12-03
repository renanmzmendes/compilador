/*
 *  Token.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Token.h"

#define TRUE 1
#define FALSE 0

//sem indices, só as palavras
const char* Tabela_Palavras_Reservadas[] = {
	"if",
	"else",
    "elsif",
	"end",
	"while",
	"int",
	"float",
	"boolean",
	"char",
    "void",
	"true",
	"false",
    "return",
    "input",
    "output",
    "main",
    "struct"
};

//cria o tal do token
Token *criarToken(char *Lexema, int terminal, int linha, int coluna){
	Token *aux;
	aux = (Token *) malloc(sizeof(Token));
	
	strcpy(aux->valor, Lexema);
	aux->tipo = definirTipo(Lexema, terminal);
	aux->linha = linha;
	aux->coluna = coluna;
	
	return (aux);
}

// define o tipo do token de acordo com o terminal e o 
// Lexema(para o caso de identificador e se precisar da pra implementar o SPECIAL_CHARACTER)
tipoToken definirTipo(char *Lexema,int terminal){
	tipoToken tipo;
	switch (terminal) {
		case -1:
			tipo = ERRO;
			break;
		case -2:
			if (ehPalavraReservada(Lexema))
				tipo = RESERVED_KEYWORD;
			else 
				tipo = ID;
			break;
		case -3:
			tipo = NUM;
			break;
		case -4:
			tipo = STRING;
			break;
		case -5:
			tipo = PONTUACAO;
			break;
		case -6:
			tipo = SPECIAL_CHARACTER;
			break;
		case -7:
			tipo = SPECIAL_CHARACTER;
			break;
		case -8:
			tipo = SPECIAL_CHARACTER;
			break;
		case -9:
			tipo = EoF;
			break;
		default:
			break;
	}
	return tipo;
}

// para o caso de IDENTIFICADOR verifica se é uma palavra reservada
int ehPalavraReservada(char *Lexema){
	int i;
	for (i = 0; i < sizeof(Tabela_Palavras_Reservadas)/sizeof(*Tabela_Palavras_Reservadas); i++) {
		if (!strcmp(Lexema, Tabela_Palavras_Reservadas[i]))
			return TRUE;
	}
	return FALSE;	
}

// imprime
/*void imprimirToken(Token *aux){
	if (aux->tipo == PONTUACAO)
		printf("%5d %5d            \\n : ", aux->linha, aux->coluna);
	else 
		printf("%5d %5d  %12s : ", aux->linha, aux->coluna, aux->valor);
	ImprimeTipo(aux->tipo);
	printf("\n");
}*/


//essa tabela serveria para o caso de ter que diferenciar os caracteres especiais.
// NÀO ESTA IMPLEMENTADA
void criarTabela_De_Caracteres_Especiais(){}

