/*
 *  Lexico.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 15/10/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#ifndef LEXICO_H
#define LEXICO_H

#include "stdio.h"
#include "Token.h"

void InicializaLexico();
void criarTabelaDeEstados();

Token *getNextToken(FILE *);
void ImprimirTabelaLexico();

#endif

