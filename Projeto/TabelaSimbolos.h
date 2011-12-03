/*
 *  TabelaSimbolos.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 03/12/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#define MAX_ESCOPOS 50
#define MAX_SIMBOLOS 50

typedef enum {INT, CHAR, FLOAT, BOOLEAN} Tipo;

//global
typedef struct  {
	char* label;
	int valor;
} TabelaConstantes;


typedef struct {
	Tipo tipo;
	char* nome;
	char* label;
}  Simbolo;

//Escopo com no máximo MAX_SIMBOLOS
typedef struct {
	Simbolo s[MAX_SIMBOLOS];
	struct Escopo* anterior;
	struct Escopo* internos[MAX_ESCOPOS];
	int numSimbolos;
	int numInternos;
} Escopo;

void initEscopo(Escopo* e);
void adicionarSimbolo(Tipo t, char* nome, char* label, Escopo* e);
int existeSimbolo(char* nome, Escopo* e);
