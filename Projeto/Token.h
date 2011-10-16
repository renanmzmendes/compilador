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
	ERRO,
	RESERVED_KEYWORD
}tipoToken;

typedef struct token {
	tipoToken tipo;
	char valor[256];
	int linha;
	int coluna;
} Token;





void imprimirToken(Token *aux);
void ImprimeTipo(tipoToken Tipo);
void criarTabela_De_Caracteres_Especiais();
void criarTabela_De_Palavras_Reservadas();
Token *criarToken(char *Lexema, int terminal, int linha, int coluna);
tipoToken definirTipo(char *Lexema,int terminal);

