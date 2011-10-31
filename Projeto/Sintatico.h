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

void empilha(int estado, int submaquina);
void desempilha(); // sempre desempilha um estado e uma submáquina, não?

int submaquinaValida(int estado, tipoToken token);
int reconhece();

stackT pilha;

void procuraTransicao(int estadoCorrente, Token* token, transicao* trans);
void procuraChamadaSubmaquina(int estadoCorrente, Token* token, chamadaSubmaquina* chamada);

#endif