//
//  TabelasSintatico.h
//  Compilador
//
//  Created by Renan Mendes on 10/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Token.h"
#include "ConstantesSintatico.h"

typedef struct {
	int estadoOrigem;
	tipoToken valorToken;
	int estadoDestino;
    
} transicao;

static transicao transicoes[] = {
    // ATR_OU_CHAMADA
    {ATR_OU_CHAMADA_INICIAL, ID, ATR_OU_CHAMADA_1},
    
    // BOOLEAN
    {BOOLEAN_INICIAL, FALSEK, BOOLEAN_1_AC},
    {BOOLEAN_INICIAL, TRUEK, BOOLEAN_1_AC},
    
    // COMANDO_COND
    {COMANDO_COND_INICIAL, IF, COMANDO_COND_1},
    {COMANDO_COND_1, LEFTPAR, COMANDO_COND_2},
    {COMANDO_COND_3, RIGHTPAR, COMANDO_COND_4},
    {COMANDO_COND_4, NEWLINE, COMANDO_COND_5},
    {COMANDO_COND_5, ELSE, COMANDO_COND_7},
    {COMANDO_COND_5, ELSIF, COMANDO_COND_6},
    {COMANDO_COND_5, END, COMANDO_COND_8_AC},
    {COMANDO_COND_6, LEFTPAR, COMANDO_COND_10},
    {COMANDO_COND_11, RIGHTPAR, COMANDO_COND_12},
    {COMANDO_COND_12, NEWLINE, COMANDO_COND_13},
    {COMANDO_COND_13, ELSE, COMANDO_COND_7},
    {COMANDO_COND_13, END, COMANDO_COND_8_AC},
    {COMANDO_COND_13, ELSIF, COMANDO_COND_6},
    {COMANDO_COND_7, NEWLINE, COMANDO_COND_9},
    {COMANDO_COND_9, END, COMANDO_COND_8_AC},
    
    // COMANDO_ENTR
    {COMANDO_ENTR_INICIAL, INPUT, COMANDO_ENTR_1},
    
    // COMANDO_ITER
    {COMANDO_ITER_INICIAL, WHILE, COMANDO_ITER_1},
    {COMANDO_ITER_1, LEFTPAR, COMANDO_ITER_2},
    {COMANDO_ITER_3, RIGHTPAR, COMANDO_ITER_4},
    {COMANDO_ITER_4, NEWLINE, COMANDO_ITER_5},
    {COMANDO_ITER_6, NEWLINE, COMANDO_ITER_7},
    {COMANDO_ITER_7, END, COMANDO_ITER_8_AC},
    
    // COMANDO_RETORNO
    {COMANDO_RETORNO_INICIAL, RETURN, COMANDO_RETORNO_1},
    
    // COMANDO_SAIDA
    {COMANDO_SAIDA_INICIAL, OUTPUT, COMANDO_SAIDA_1},
    
    // COMANDO (só tem chamada de submáquina)
    
    // COMPARACAO
    {COMPARACAO_1, GT, COMPARACAO_2},
    {COMPARACAO_1, GTE, COMPARACAO_2},
    {COMPARACAO_1, EQ, COMPARACAO_2},
    {COMPARACAO_1, LT, COMPARACAO_2},
    {COMPARACAO_1, LTE, COMPARACAO_2},
    {COMPARACAO_1, NEQ, COMPARACAO_2},
    
    // CONDICAO
    {CONDICAO_1_AC, OR, CONDICAO_2},
    
    // DECL_FUNCAO
    {DECL_FUNCAO_3, NEWLINE, DECL_FUNCAO_4},
    {DECL_FUNCAO_4, END, DECL_FUNCAO_5_AC},
    
    // DECL_OU_COMANDO (só tem chamada de submáquina)
    
    // DECL_PARAMS
    {DECL_PARAMS_2_AC, COMMA, DECL_FUNCAO_INICIAL},
    
    // DECL_SIMP_VAR (só tem chamada de submáquina)
    
    // EXPR
    {EXPR_1_AC, PLUS, EXPR_INICIAL},
    {EXPR_1_AC, MINUS, EXPR_INICIAL},
    
    // FATOR_COND
    {FATOR_COND_INICIAL, NOT, FATOR_COND_1},
    {FATOR_COND_1, LEFTPAR, FATOR_COND_3},
    {FATOR_COND_4, RIGHTPAR, FATOR_COND_2_AC},
    
    // FATOR
    {FATOR_INICIAL, LEFTPAR, FATOR_2},
    {FATOR_3, RIGHTPAR, FATOR_1_AC},
    
    // ID (só tem chamada de submáquina)
    
    // LISTA_EXPR
    {LISTA_EXPR_1_AC, COMMA, LISTA_EXPR_INICIAL},
    
    // LISTA_MEM
    {LISTA_MEM_1_AC, COMMA, LISTA_MEM_INICIAL},
    
    // NUM_REAL (não precisa fazer transição pra essa submáquina pq virá como NUM do léxico)
    // NUM (vai ser o próprio Token passado pelo léxico)
    
    // PARAM (só tem chamada de submáquina)
    
    // PROGRAM
    {PROGRAM_1, NEWLINE, PROGRAM_INICIAL},
    {PROGRAM_INICIAL, INT, PROGRAM_2},
    {PROGRAM_2, MAIN, PROGRAM_3},
    {PROGRAM_3, LEFTPAR, PROGRAM_4},
    {PROGRAM_4, RIGHTPAR, PROGRAM_5},
    {PROGRAM_5, NEWLINE, PROGRAM_6},
    {PROGRAM_6, END, PROGRAM_7_AC},
    
    // REST_CHAMADA_FUNCAO
    {REST_CHAMADA_FUNCAO_INICIAL, LEFTPAR, REST_CHAMADA_FUNCAO_1},
    {REST_CHAMADA_FUNCAO_2, COMMA, REST_CHAMADA_FUNCAO_1},
    {REST_CHAMADA_FUNCAO_2, RIGHTPAR, REST_CHAMADA_FUNCAO_3_AC},
    
    // REST_COMANDO_ATR
    {REST_COMANDO_ATR_INICIAL, EQ, REST_COMANDO_ATR_1},
    
    // TERMO_COND
    {TERMO_COND_1_AC, AND, TERMO_COND_INICIAL},
    
    // TERMO
    {TERMO_1_AC, MULT, TERMO_INICIAL},
    {TERMO_1_AC, DIV, TERMO_INICIAL},
    {TERMO_1_AC, MOD, TERMO_INICIAL},
    
    // TIPO
    {TIPO_INICIAL, VOID, TIPO_1_AC},
    {TIPO_INICIAL, BOOLEAN, TIPO_1_AC},
    {TIPO_INICIAL, CHAR, TIPO_1_AC},
    {TIPO_INICIAL, FLOAT, TIPO_1_AC},
    {TIPO_INICIAL, INT, TIPO_1_AC}
};

#define NUMTRANSICOES (sizeof(transicoes)/sizeof(*transicoes))

typedef struct {
    int estadoOrigem;
    int estadoDestino; // na submáquina de destino, claro
    int estadoRetorno;
} chamadaSubmaquina;

static chamadaSubmaquina chamadas[] = {
    // ATR_OU_CHAMADA
    {ATR_OU_CHAMADA_INICIAL, ID_INICIAL, ATR_OU_CHAMADA_1},
    {ATR_OU_CHAMADA_1, REST_CHAMADA_FUNCAO_INICIAL, ATR_OU_CHAMADA_2_AC},
    {ATR_OU_CHAMADA_1, REST_COMANDO_ATR_INICIAL, ATR_OU_CHAMADA_2_AC},
    
    // BOOLEAN (não tem chamada de submáquina)
    
    // COMANDO_COND
    {COMANDO_COND_2, CONDICAO_INICIAL, COMANDO_COND_3},
    {COMANDO_COND_5, DECL_OU_COMANDO_INICIAL, COMANDO_COND_4},
    {COMANDO_COND_9, DECL_OU_COMANDO_INICIAL, COMANDO_COND_7},
    {COMANDO_COND_10, CONDICAO_INICIAL, COMANDO_COND_11},
    {COMANDO_COND_13, DECL_OU_COMANDO_INICIAL, COMANDO_COND_12},
    
    // COMANDO_ITER
    {COMANDO_ITER_2, CONDICAO_INICIAL, COMANDO_ITER_3},
    {COMANDO_ITER_5, DECL_OU_COMANDO_INICIAL, COMANDO_ITER_6},
    
    // COMANDO_RETORNO
    {COMANDO_RETORNO_1, EXPR_INICIAL, COMANDO_RETORNO_2_AC},
    
    // COMANDO_SAIDA
    {COMANDO_SAIDA_1, LISTA_EXPR_INICIAL, COMANDO_SAIDA_2_AC},
    
    // COMANDO
    {COMANDO_INICIAL, COMANDO_ENTR_INICIAL, COMANDO_1_AC},
    {COMANDO_INICIAL, COMANDO_SAIDA_INICIAL, COMANDO_1_AC},
    {COMANDO_INICIAL, COMANDO_RETORNO_INICIAL, COMANDO_1_AC},
    {COMANDO_INICIAL, COMANDO_ITER_INICIAL, COMANDO_1_AC},
    {COMANDO_INICIAL, COMANDO_COND_INICIAL, COMANDO_1_AC},
    {COMANDO_INICIAL, ATR_OU_CHAMADA_INICIAL, COMANDO_1_AC},
    
    // COMPARACAO
    {COMPARACAO_INICIAL, EXPR_INICIAL, COMPARACAO_1},
    {COMPARACAO_2, EXPR_INICIAL, COMPARACAO_3_AC},
    
    // CONDICAO
    {CONDICAO_INICIAL, TERMO_COND_INICIAL, CONDICAO_1_AC},
    {CONDICAO_2, TERMO_COND_INICIAL, CONDICAO_1_AC},
    
    // DECL_FUNCAO
    {DECL_FUNCAO_INICIAL, TIPO_INICIAL, DECL_FUNCAO_1},
    {DECL_FUNCAO_1, ID_INICIAL, DECL_FUNCAO_2},
    {DECL_FUNCAO_2, DECL_PARAMS_INICIAL, DECL_FUNCAO_3},
    {DECL_FUNCAO_4, DECL_OU_COMANDO_INICIAL, DECL_FUNCAO_3},
    
    // DECL_OU_COMANDO
    {DECL_OU_COMANDO_INICIAL, COMANDO_INICIAL, DECL_OU_COMANDO_1_AC},
    {DECL_OU_COMANDO_INICIAL, DECL_SIMP_VAR_INICIAL, DECL_OU_COMANDO_1_AC},
    
    // DECL_PARAMS
    {DECL_PARAMS_INICIAL, TIPO_INICIAL, DECL_PARAMS_1},
    {DECL_PARAMS_1, ID_INICIAL, DECL_PARAMS_2_AC},
    
    // DECL_SIMP_VAR
    {DECL_SIMP_VAR_INICIAL, TIPO_INICIAL, DECL_SIMP_VAR_1},
    {DECL_SIMP_VAR_1, ID_INICIAL, DECL_SIMP_VAR_2_AC},
    
    // EXPR
    {EXPR_INICIAL, TERMO_INICIAL, EXPR_1_AC},
    
    // FATOR_COND
    {FATOR_COND_INICIAL, COMPARACAO_INICIAL, FATOR_COND_2_AC},
    {FATOR_COND_INICIAL, BOOLEAN_INICIAL, FATOR_COND_2_AC},
    {FATOR_COND_INICIAL, ID_INICIAL, FATOR_COND_2_AC},
    
    // FATOR
    {FATOR_INICIAL, NUM_INICIAL, FATOR_1_AC},
    {FATOR_INICIAL, ID_INICIAL, FATOR_1_AC},
    {FATOR_2, EXPR_INICIAL, FATOR_3},
    
    // ID (não precisa explicitar chamada de submáquina, pois o token passado já será o ID)
    
    // LISTA_EXPR
    {LISTA_EXPR_INICIAL, EXPR_INICIAL, LISTA_EXPR_1_AC},
    
    // LISTA_MEM
    {LISTA_MEM_INICIAL, ID_INICIAL, LISTA_MEM_1_AC},
    
    // NUM_REAL (também nao é necessário explicitar)
    // NUM (é o próprio token)
    
    // PARAM
    {PARAM_INICIAL, CONDICAO_INICIAL, PARAM_1_AC},
    {PARAM_INICIAL, EXPR_INICIAL, PARAM_1_AC},

    // PROGRAM
    {PROGRAM_INICIAL, DECL_FUNCAO_INICIAL, PROGRAM_1},
    {PROGRAM_5, DECL_OU_COMANDO_INICIAL, PROGRAM_6},
    
    // REST_CHAMADA_FUNCAO
    {REST_CHAMADA_FUNCAO_1, PARAM_INICIAL, REST_CHAMADA_FUNCAO_2},
    
    // REST_COMANDO_ATR
    {REST_COMANDO_ATR_1, EXPR_INICIAL, REST_COMANDO_ATR_2_AC},
    
    // TERMO_COND
    {TERMO_COND_INICIAL, FATOR_COND_INICIAL, TERMO_COND_1_AC},
    
    // TERMO
    {TERMO_INICIAL, FATOR_INICIAL, TERMO_1_AC}
    
    // TIPO (não possui chamadas de submáquinas)
};

#define NUMCHAMADAS (sizeof(chamadas)/sizeof(*chamadas))

