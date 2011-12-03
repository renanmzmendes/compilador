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
	numInternos++;
	e.internos[e->numInternos] = interno;
}


void adicionarSimbolo(Tipo t, char* nome, char* label, Escopo* e){
	e->numSimbolos++;	
	e->s[e->numSimbolos].tipo = t;
	strcpy(e->s[e->numSimbolos].nome, nome);
	strcpy(e->s[e->numSimbolos].label,label);
}


int existeSimbolo(char* nome, Escopo* e){
	for (int i=0; i <= e->numSimbolos; i++) {
		if (!strcmp(e->s[i].nome, nome)) {
			return 1;
		}
	}
	return 0;
}

