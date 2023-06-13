#ifndef CONVERTE_EXP_H
#define CONVERTE_EXP_H

#include "../include/armazenaExp.h"

/**
 * @brief Converte uma expressão Infixa para Posfixa.
 * 
 * @param exp - expressão passada como parâmetro
 * @param p - pilha criada passada como parãmetro
 * @return * char* 
 */
char *infixaParaPosfixa(char *exp, pilha *p);

/**
 * @brief Converte uma expressão Posfixa para Infixa.
 * 
 * @param exp - expressão passada como parâmetro
 * @return * char* 
 */
char *posfixaParaInfixa(char *exp, pilha *p);

/**
 * @brief Verifica se o ponteiro passado como parâmetro é um operando.
 * 
 * @param operando 
 * @return * int 
 */
int ehOperando(char *operando);

#endif