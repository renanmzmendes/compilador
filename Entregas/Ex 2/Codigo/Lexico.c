/*
 *  Lexico.c
 *  Compilador
 *
 *  Created by Tiago Schelp Lopes on 15/10/11.
 *  Copyright 2011 USP. All rights reserved.
 *
 */

#define Erro_Lexico -1
#define Terminal_IDENT -2
#define Terminal_NUM -3
#define Terminal_STRING -4 
#define Terminal_PONTUACAO -5 
#define Terminal_CARACTER_ESPECIAL -6
#define Terminal_CARACTER_ESPECIAL_1_Digitos -7
#define Terminal_CARACTER_ESPECIAL_2_Digitos -8
#define Fim_de_Arquivo -9

#define NumEstados 8
#define QTDE_Palavras_Reservadas 10

static int linha;
static int coluna;
static char ch='\0';
static int TabelaLexica[NumEstados][256];

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Lexico.h"

void InicializaLexico(){
	linha = 0;
	coluna = 0;
	criarTabela_De_Caracteres_Especiais();
	criarTabelaDeEstados();
}

void criarTabelaDeEstados(){
	int estado;
	int valorASCII;
	estado=0;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if(valorASCII >= 'a' && valorASCII<= 'z' || valorASCII >= 'A' && valorASCII<= 'Z'){
			TabelaLexica[estado][valorASCII] = 1;	
		}
		else if (valorASCII == '0'){
			TabelaLexica[estado][valorASCII] = 3;	
		}
		else if (valorASCII== '.'){
			TabelaLexica[estado][valorASCII] = 4;	
		}
		else if (valorASCII >= '1' && valorASCII <= '9'){
			TabelaLexica[estado][valorASCII] = 2;
		}
		else if (valorASCII== '"'){
			TabelaLexica[estado][valorASCII] = 6;
		}
		else if (valorASCII== '\n' || valorASCII== '.' || valorASCII== ','){
			TabelaLexica[estado][valorASCII] = Terminal_PONTUACAO;
		}
		else if (valorASCII== '=' || valorASCII== '>' || valorASCII== '<' || valorASCII== '!'){
			TabelaLexica[estado][valorASCII] = 7;
		}
		else if (valorASCII== '+' || valorASCII== '-' || valorASCII== '*' || valorASCII== '/' || 
				 valorASCII== '%' || valorASCII== '(' || valorASCII== ')' || valorASCII== '&' ||
				 valorASCII== '|' || valorASCII== '[' || valorASCII== ']' ){
			TabelaLexica[estado][valorASCII] = Terminal_CARACTER_ESPECIAL;
		}
		else if (valorASCII== '\377'){
			TabelaLexica[estado][valorASCII] = Fim_de_Arquivo;
		}
		
		else{ 
			TabelaLexica[estado][valorASCII] = Erro_Lexico ;
		}
	}
	
	estado=1;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII >= 'a' && valorASCII<= 'z' || 
			valorASCII >= 'A' && valorASCII<= 'Z' || 
			valorASCII >= '0' && valorASCII <= '9'){
			TabelaLexica[estado][valorASCII] = 1;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_IDENT ;
		}		
	}
	
	estado=2;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII >= '0' && valorASCII <= '9'){
			TabelaLexica[estado][valorASCII] = 2;
		}
		else if(valorASCII == '.') {
			TabelaLexica[estado][valorASCII] = 4;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_NUM ;
		}		
	}
	
	estado=3;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII == '.' ){
			TabelaLexica[estado][valorASCII] = 4;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_NUM ;
		}		
	}
	
	estado=4;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII >= '0' && valorASCII <= '9'){
			TabelaLexica[estado][valorASCII] = 5;
		}
		else {
			TabelaLexica[estado][valorASCII] = Erro_Lexico;
		}		
	}
	
	estado=5;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII >= '0' && valorASCII <= '9'){
			TabelaLexica[estado][valorASCII] = 5;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_NUM ;
		}		
	}
	
	estado=6;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII != '"' ){
			TabelaLexica[estado][valorASCII] = 6;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_STRING ;
		}		
	}
	
	estado=7;
	for (valorASCII=0; valorASCII<=255; valorASCII++) {
		if (valorASCII == '=' ){
			TabelaLexica[estado][valorASCII] = Terminal_CARACTER_ESPECIAL_2_Digitos;
		}
		else {
			TabelaLexica[estado][valorASCII] = Terminal_CARACTER_ESPECIAL_1_Digitos ;
		}		
	}	
}

Token *getNextToken(FILE *inputFile){
	if (ch == '\0') {// se é primeira chamada Lê o primeiro caractere do arquivo de entrada
		ch = fgetc(inputFile);
		coluna++;
	}
	int estado_Atual = 0;
	char BufferLexema[256] = {};
	
	// descartando os espaços e tabs
	while (ch == ' ' || ch == '\t') {
		ch = getc(inputFile);
		coluna++;
	}
	// descartando comentários
	if (ch == '#') {
		while (ch != '\n') {
			ch = getc(inputFile);
		}
		ch = getc(inputFile);
		linha++;
		coluna=0;
	}
	
	//Grava o caractere lido no Buffer do Lexema e calcula o próximo estado
	// sempre que a função getNextToken for chamada o ch estará 
	// apontando para o primeiro caractere do próximo token
	// Percorre os estados até encontrar estado Terminal
	BufferLexema[strlen(BufferLexema)] = ch;
	estado_Atual = TabelaLexica[estado_Atual][ch];
	while (estado_Atual >= 0) {
		ch = getc(inputFile);
		coluna++;
		if (ch == '\377') {
			estado_Atual = Fim_de_Arquivo;
		}
		else {
			BufferLexema[strlen(BufferLexema)] = ch;
			estado_Atual = TabelaLexica[estado_Atual][ch];
		}
	} 
	
	// após encontrar estado terminal ajusta o BufferLexema e o caracter lido de 
	// acordo com o terminal alcançado. Em alguns casos o último caracter lido é
	// o ultimo caracter do token atual, em outros casos o último caractere lido é
	// o primeiro caractere do próximo token.
	if (estado_Atual == Terminal_IDENT || estado_Atual == Terminal_NUM || 
		estado_Atual == Terminal_CARACTER_ESPECIAL_1_Digitos) {
		BufferLexema[strlen(BufferLexema)-1] = '\0';
	}
	else if(estado_Atual == Terminal_STRING ||  
			estado_Atual == Terminal_CARACTER_ESPECIAL_2_Digitos ||
			estado_Atual == Terminal_CARACTER_ESPECIAL ||
			estado_Atual == Erro_Lexico){
		ch = getc(inputFile);
		coluna++;
	}
	else if(estado_Atual == Terminal_PONTUACAO) {
		ch = getc(inputFile);
		coluna=0;
		linha++;
	}	
	
	return criarToken(BufferLexema, estado_Atual, linha, coluna - strlen(BufferLexema));
}

void ImprimirTabelaLexico(){
	printf("\n\nESTADO   CARACTERE   PROXIMO ESTADO");
    int i;
	for (i=0; i<=7; i++) {
        int j;
		for (j=0; j<=255; j++) {
			printf("%6d   %5c     : %3d\n",i,j,TabelaLexica[i][j]);
		}
		printf("\n\n");
	}
}
