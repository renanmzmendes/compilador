/*
 *  Token.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 24/09/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#define FIM_Token -1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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

Token *criarToken(char *Lexema, tipoToken tipo, int linha, int coluna){
	Token *aux;
	aux = (Token *) malloc(sizeof(Token));
	
	aux->valor = Lexema;
	aux->tipo = tipo;
	aux->linha = linha;
	aux->coluna = coluna;
	
	if (*Lexema == '\n')
		printf("%5d %5d            \\n : ", aux->linha, aux->coluna);
	else 
		printf("%5d %5d  %12s : ", aux->linha, aux->coluna, aux->valor);
	ImprimeTipo(tipo);
	printf("\n");
	
	return (aux);
}

Token *getNextToken(FILE *inputFile, char *ch, int *linha, int *coluna){
	if (*ch == '\0') {
		*ch = fgetc(inputFile);
	}
	int current_state = 0;
	char BufferLexema[256] = {};
	tipoToken Tipo;
	
	// descartando os espaços e tabs
	while (*ch == ' ' || *ch == '\t') {
		*ch = getc(inputFile);
		(*coluna)++;
	}
	
	// descartando comentários
	if (*ch == '#') {
		while (*ch != '\n') {
			*ch = getc(inputFile);
		}
		*ch = getc(inputFile);
		(*linha)++;
		(*coluna)=0;
	}
	
	//Grava o caractere lido no Buffer do Lexema
	//
	// da maneira como foi feito, sempre que a 
	// função getNextToken for criada o *ch estará 
	// apontando para o primeiro caractere a ser considerado
	BufferLexema[strlen(BufferLexema)] = *ch;
	while (1) {
		switch (current_state) {
			case FIM_Token:
				return criarToken(BufferLexema, Tipo,(*linha), (*coluna) - (int)strlen(BufferLexema));
			break;
		case 0:
				if(*ch == '\n'){
					(*linha)++;
					(*coluna)=0;
					Tipo = NEWLINE;
					current_state = FIM_Token;
					*ch = getc(inputFile);
				}
				else if (*ch == '+'){
					Tipo = PLUS;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '-'){
					Tipo = MINUS;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '*'){
					Tipo = MULT;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '/'){
					Tipo = DIV;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '%'){
					Tipo = MOD;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '('){
					Tipo = LEFTPAR;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== ')'){
					Tipo = RIGHTPAR;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '&'){
					Tipo = AND;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				else if (*ch== '|' ){
					Tipo = OR;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
			else if (*ch== '=')
				current_state = 1;
			else if (*ch== '<')
				current_state = 2;
			else if (*ch== '>')
				current_state = 3;
			else if (*ch== '!')
				current_state = 4;
			else if (*ch >= 'a' && *ch<= 'z' || *ch >= 'A' && *ch<= 'Z')
				current_state = 5;
			else if (*ch== '"')
				current_state = 6;
			else if ((int)*ch==0)
				current_state = 7;
			else if (isdigit(*ch) && (int)*ch!=0)
				current_state = 8;
			else if (*ch== '.')
				current_state = 9;
			else if	(*ch == '\377'){
				Tipo = EoF;
				current_state = FIM_Token;
			}
			else{ 
				Tipo=ERRO;
				current_state = FIM_Token;
				*ch = getc(inputFile);
				(*coluna)++;
			}
			break;
		case 1:
			if (*ch== '='){
				Tipo = EQ;
				current_state = FIM_Token;
				*ch = getc(inputFile);
				(*coluna)++;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = ATTR;
				current_state = FIM_Token;
			}
			break;
		case 2:
			if (*ch== '='){
				Tipo = LTE;
				current_state = FIM_Token;
				*ch = getc(inputFile);
				(*coluna)++;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = LT;
				current_state = FIM_Token;
			}			
			break;
		case 3:
			if (*ch== '='){
				Tipo = GTE;
				current_state = FIM_Token;
				*ch = getc(inputFile);
				(*coluna)++;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = GT;
				current_state = FIM_Token;
			}	
			break;
		case 4:
			if (*ch== '='){
				Tipo = NEQ;
				current_state = FIM_Token;
				*ch = getc(inputFile);
				(*coluna)++;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = NOT;
				current_state = FIM_Token;
			}
			break;
		case 5:
			if (*ch >= 'a' && *ch<= 'z' || *ch >= 'A' && *ch<= 'Z' || isdigit(*ch)){
				current_state = 5;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = ID;
				current_state = FIM_Token;
			}
			break;
		case 6:
			if (*ch != '"'){
				current_state = 6;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = STRING;
				current_state = FIM_Token;
			}
			break;
		case 7:
			if (*ch == '.'){
				current_state = 9;
			}
			else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				current_state = FIM_Token;
				Tipo = NUM;
			}
			break;
		case 8:
			if (isdigit(*ch)) {
				current_state = 8;
			}else if (*ch == '.') {
				current_state = 9;
			}else {
				BufferLexema[strlen(BufferLexema)-1] = '\0';
				Tipo = NUM;
				current_state = FIM_Token;
			}
			break;
		case 9:
				if (isdigit(*ch))
					current_state = 10;
				else{ 
					Tipo=ERRO;
					current_state = FIM_Token;
					*ch = getc(inputFile);
					(*coluna)++;
				}
				break;
		case 10:
				if (isdigit(*ch)) {
					current_state = 10;
				} else {
					BufferLexema[strlen(BufferLexema)-1] = '\0';
					Tipo = NUM;
					current_state = FIM_Token;
				}
				break;
			default:
				printf("Erro desconhecido");
				//return criarToken(ERRO, Tipo, (*linha), (*coluna)); tentativa de tratar erro
		}
		//lê proximo se não for pra ir pro FIM
		// se for pra ir pro fim então quer dizer que 
		// o primeiro caractere do próximo token já foi lido
		if (current_state != FIM_Token) 
		{
			*ch = getc(inputFile);
			BufferLexema[strlen(BufferLexema)] = *ch;
			(*coluna)++;
		}
}
}