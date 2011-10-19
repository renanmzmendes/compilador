/*
 *  Lexico.h
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 15/10/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#include "Token.h"

void InicializaLexico();
void criarTabelaDeEstados();

Token *getNextToken(FILE *);
void ImprimirTabelaLexico();

