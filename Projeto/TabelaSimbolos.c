/*
 *  TabelaSimbolos.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 03/12/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#include "TabelaSimbolos.h"
#include <string.h>


void initEscopo(Escopo* e){
	e->numInternos = 0;
	e->numSimbolos = 0;
}


void insereEscopoInterno(Escopo* e, Escopo* interno){
	e->numInternos++;
	e->internos[e->numInternos] = interno;
}

//
//
///Escopo com no máximo MAX_SIMBOLOS
//typedef struct {
//	Simbolo s[MAX_SIMBOLOS];
//	struct Escopo* anterior;
//	struct Escopo* internos[MAX_ESCOPOS];
//	int numSimbolos;
//	int numInternos
//



void adicionarSimbolo(Tipo t, char* nome, char* label, Escopo* e){
	e->numSimbolos++;	
	e->simbolos[e->numSimbolos].tipo = t;
	e->simbolos[e->numSimbolos].nome = nome;
	e->simbolos[e->numSimbolos].label = label;
}


int existeSimbolo(char* nome, Escopo* e){
	for (int i=0; i <= e->numSimbolos; i++) {
		if (!strcmp(e->simbolos[i].nome, nome)) {
			return 1;
		}
	}
	return 0;
}

