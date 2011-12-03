/*
 *  TabelaSimbolos.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 03/12/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#define MAX_ESCOPOS 50

typedef enum {INT, CHAR, FLOAT, BOOLEAN} Tipo;

typedef struct {
	Tipo t;
	char* nome;
	char* label;
}  TabelaSimbolos;

typedef struct  {
	char* label;
	int valor;
} TabelaConstantes;

typedef struct {
	TabelaSimbolos ts;
	struct Escopo* escopos[MAX_ESCOPOS];
} Escopo;

void adicionarSimbolo(Tipo t, char* nome, char* label, Escopo* escopo);
int existeSimbolo(char* nome, Escopo* escopo);

