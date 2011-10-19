/*
 *  Token.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */


// quase todos não são usados, mas vou deixar para o caso de agente resolver usar um dia,
// os não usados tao abaixo de EoF.
typedef enum tiposToken {
	NEWLINE,
	NUM,
	STRING,
	ID,
	RESERVED_KEYWORD,
	SPECIAL_CHARACTER,
	ERRO,
	EoF,
	DIV,
	MULT,
	MINUS,
	PLUS,
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
	MOD
}tipoToken;

typedef struct token {
	tipoToken tipo;
	char valor[256];
	int linha;
	int coluna;
} Token;



Token *criarToken(char *Lexema, int terminal, int linha, int coluna);

//auxiliares na criação do token
tipoToken definirTipo(char *Lexema,int terminal);
int ehPalavraReservada(char *Lexema);

//pra visualizar 
void imprimirToken(Token *aux);
void ImprimeTipo(tipoToken Tipo);

//nem ta usando ainda
void criarTabela_De_Caracteres_Especiais();
