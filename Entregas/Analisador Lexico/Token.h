/*
 *  Token.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

typedef enum tiposToken {
	DIV,
	MULT,
	MINUS,
	PLUS,
	NEWLINE,
	NUM,
	STRING,
	ID,
	NOT,
	NEQ,
	GT,
	GTE,
	LT,
	LTE,
	ATTR,
	EQ,
	OR,
	AND,
	RIGHTPAR,
	LEFTPAR,
	MOD,
	EoF,
	ERRO
}tipoToken;

typedef struct token {
	
	tipoToken tipo;
	char *valor;
	int linha;
	int coluna;
} Token;

void ImprimeTipo(tipoToken Tipo);

Token *criarToken(char *Lexema, tipoToken tipo, int linha, int coluna);

Token *getNextToken(FILE *, char *ch, int *linha,int *coluna);
