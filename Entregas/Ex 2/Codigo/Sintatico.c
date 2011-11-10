//
//  Sintatico.c
//  Compilador
//
//  Created by Renan Mendes on 10/30/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Sintatico.h"
#include "TabelasSintatico.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

void empilha(Estado estadoRetorno) {
    StackPush(&pilha, estadoRetorno);
}

int desempilha() {
    return StackPop(&pilha);
}

int procuraTransicao(Estado estadoCorrente, Token* token, transicao* trans) {
    int i;
    for(i = 0; i < NUMTRANSICOES; ++i) {
        if(transicoes[i].estadoOrigem == estadoCorrente) {
            if(transicoes[i].tipo == token->tipo && (!strcmp(transicoes[i].token, token->valor) || !strcmp("", transicoes[i].token)) || transicoes[i].tipo == NDEF) {
                *trans = transicoes[i];
                return 1;
            }
        }
    }
    
    return 0;
}

int procuraChamadaSubmaquina(Estado estadoCorrente, Token* token, chamadaSubmaquina* chamada) {
    int i;
    for(i = 0; i < NUMCHAMADAS; ++i) {
        if(chamadas[i].estadoOrigem == estadoCorrente) {
            if(chamadas[i].tipo == token->tipo && (!strcmp(chamadas[i].token, token->valor) || !strcmp("", chamadas[i].token)) || chamadas[i].tipo == NDEF) {
                *chamada = chamadas[i];
                return 1;
            }
        }
    }
    
    return 0;
}

int estadoFinal(Estado estado) {
    if(estado == ATR_OU_CHAMADA_2_AC
       || estado == BOOLEAN_1_AC
       || estado == COMANDO_COND_7_AC
       || estado == COMANDO_ENTR_2_AC
       || estado == COMANDO_ITER_6_AC
       || estado == COMANDO_RETORNO_2_AC
       || estado == COMANDO_SAIDA_2_AC
       || estado == COMANDO_1_AC
       || estado == COMPARACAO_3_AC
       || estado == CONDICAO_1_AC
       || estado == DECL_FUNCAO_7_AC
       || estado == DECL_OU_COMANDO_2_AC
       || estado == DECL_PARAMS_2_AC
       || estado == DECL_SIMP_VAR_2_AC
       || estado == EXPR_1_AC
       || estado == FATOR_COND_2_AC
       || estado == FATOR_1_AC
       || estado == ID_1_AC
       || estado == LISTA_EXPR_1_AC
       || estado == LISTA_MEM_1_AC
       || estado == NUM_REAL_3_AC
       || estado == NUM_1_AC
       || estado == PARAM_1_AC
       || estado == PROGRAM_6_AC
       || estado == REST_CHAMADA_FUNCAO_3_AC
       || estado == REST_COMANDO_ATR_2_AC
       || estado == TERMO_COND_1_AC
       || estado == TERMO_1_AC
       || estado == TIPO_1_AC) {
        return 1;
    }
    
    return 0;
}

void semantico_tbd() {
    printf("TODO\n");
}
