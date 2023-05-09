#ifndef RESOLVE_EXP_H
#define RESOLVE_EXP_H

#include "armazenaExp.h"

/**
 * @brief Realiza a operação desejada de uma expressão Posfixa, de acordo com o operador passado como parâmetro
 * 
 * @param numero1
 * @param numero2
 * @param operador 
 * @return * float 
 */
float operacaoPosfixa(float numero1, float numero2, char operador);

/**
 * @brief Resolve uma expressão em seu formato Posfixa
 * 
 * @param exp - expressão a ser resolvida
 * @param p - pilha a ser utilizada
 * @return * float 
 */

float resolvePosfixa(char *exp, pilha *p);

#endif