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

#define TRUE 0
#define FALSE 1

//sem indices, só as palavras
const char* Tabela_Palavras_Reservadas[] = {
	"if",
	"else",
	"end",
	"while",
	"int",
	"float",
	"bool",
	"char",
	"true",
	"false"
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
			tipo = NEWLINE;
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
	for (i = 0; i < sizeof(Tabela_Palavras_Reservadas)/sizeof(Tabela_Palavras_Reservadas[0]); i++) {
		if (strcmp(Lexema, Tabela_Palavras_Reservadas[i]))
			return FALSE;
	}
	return TRUE;	
}

// imprime
void imprimirToken(Token *aux){
	if (aux->tipo == NEWLINE)
		printf("%5d %5d            \\n : ", aux->linha, aux->coluna);
	else 
		printf("%5d %5d  %12s : ", aux->linha, aux->coluna, aux->valor);
	ImprimeTipo(aux->tipo);
	printf("\n");
}

// pra ajudar o imprimir token
void ImprimeTipo(tipoToken Tipo){
	switch (Tipo) {
		case DIV:
			printf("DIV");
			break;
		case MULT:
			printf("MULT");
			break;
		case MINUS:
			printf("MINUS");
			break;
		case PLUS:
			printf("PLUS");
			break;
		case NEWLINE:
			printf("NEWLINE");
			break;
		case NUM:
			printf("NUM");
			break;
		case STRING:
			printf("STRING");
			break;
		case ID:
			printf("ID");
			break;
		case NOT:
			printf("NOT");
			break;
		case NEQ:
			printf("NEQ");
			break;
		case GT:
			printf("GT");
			break;
		case GTE:
			printf("GTE");
			break;
		case LT:
			printf("LT");
			break;
		case LTE:
			printf("LTE");
			break;
		case ATTR:
			printf("ATTR");
			break;
		case EQ:
			printf("EQ");
			break;
		case OR:
			printf("OR");
			break;
		case AND:
			printf("AND");
			break;
		case RIGHTPAR:
			printf("RIGHTPAR");
			break;
		case LEFTPAR:
			printf("LEFTPAR");
			break;
		case MOD:
			printf("MOD");
		case EoF:
			printf("EoF");
			break;
		case RESERVED_KEYWORD:
			printf("RESERVED_KEYWORD");
			break;
		case SPECIAL_CHARACTER:
			printf("SPECIAL_CHARACTER");
			break;
		case ERRO:
			printf("ERRO");
			break;
		default:
			break;
	}
}

//essa tabela serveria para o caso de ter que diferenciar os caracteres especiais.
// NÀO ESTA IMPLEMENTADA
void criarTabela_De_Caracteres_Especiais(){}

