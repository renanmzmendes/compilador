/*
 *  Token.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Token.h"


void ImprimeTipo(tipoToken Tipo){
switch (Tipo) {
	case DIV:
		printf("DIV");
		break;
	case MULT:
		printf("MULT");
		break;
	case MINUS:
		printf("MINUS");
		break;
	case PLUS:
		printf("PLUS");
		break;
	case NEWLINE:
		printf("NEWLINE");
		break;
	case NUM:
		printf("NUM");
		break;
	case STRING:
		printf("STRING");
		break;
	case ID:
		printf("ID");
		break;
	case NOT:
		printf("NOT");
		break;
	case NEQ:
		printf("NEQ");
		break;
	case GT:
		printf("GT");
		break;
	case GTE:
		printf("GTE");
		break;
	case LT:
		printf("LT");
		break;
	case LTE:
		printf("LTE");
		break;
	case ATTR:
		printf("ATTR");
		break;
	case EQ:
		printf("EQ");
		break;
	case OR:
		printf("OR");
		break;
	case AND:
		printf("AND");
		break;
	case RIGHTPAR:
		printf("RIGHTPAR");
		break;
	case LEFTPAR:
		printf("LEFTPAR");
		break;
	case MOD:
		printf("MOD");
	case EoF:
		printf("EoF");
		break;
	case ERRO:
		printf("ERRO");
		break;
	default:
		break;
}
}

tipoToken definirTipo(char *Lexema,int terminal){
	tipoToken tipo;
	switch (terminal) {
		case -1:
			tipo = ERRO;
			break;
		case -2:
//			if (ehPalavraReservada(Lexema))
//				tipo = RESERVED_KEYWORD;
//			else 
				tipo = ID;
			break;
		case -3:
			tipo = NUM;
			break;
		case -4:
			tipo = STRING;
			break;
		case -5:
			tipo = NEWLINE;
			break;
		case -6:
			tipo = DIV;
			break;
		case -7:
			tipo = DIV;
			break;
		case -8:
			tipo = DIV;
			break;
		case -9:
			tipo = EoF;
			break;
		default:
			break;
	}
	return tipo;
}

Token *criarToken(char *Lexema, int terminal, int linha, int coluna){
	Token *aux;
	aux = (Token *) malloc(sizeof(Token));
	
	strcpy(aux->valor, Lexema);
	aux->tipo = definirTipo(Lexema, terminal);
	aux->linha = linha;
	aux->coluna = coluna;
	
	return (aux);
}

void imprimirToken(Token *aux){
	if (aux->tipo == NEWLINE)
		printf("%5d %5d            \\n : ", aux->linha, aux->coluna);
	else 
		printf("%5d %5d  %12s : ", aux->linha, aux->coluna, aux->valor);
	ImprimeTipo(aux->tipo);
	printf("\n");
}
void criarTabela_De_Caracteres_Especiais(){}
void criarTabela_De_Palavras_Reservadas(){}
