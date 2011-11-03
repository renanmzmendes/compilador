//
//  Sintatico.h
//  Compilador
//
//  Created by Renan Mendes on 10/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef SINTATICO_H
#define SINTATICO_H

#include "stack.h"
#include "Token.h"
#include "TabelasSintatico.h"

stackT pilha;

void empilha(Estado estadoRetorno);
int desempilha();

int procuraTransicao(Estado estadoCorrente, Token* token, transicao* trans);
int procuraChamadaSubmaquina(Estado estadoCorrente, Token* token, chamadaSubmaquina* chamada);

int estadoFinal(Estado estado);

void semantico_tbd();

#endif