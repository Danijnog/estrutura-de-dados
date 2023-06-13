#include "../include/resolveExp.h"
#include "../include/msgAssert.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

float operacaoPosfixa(float operando1, float operando2, char operador) {
    switch(operador)
    {
        case '+':
            return operando1 + operando2;
            break;
        
        case '-':
            return operando1 - operando2;
            break;
        
        case '/':
            return operando1 / operando2;
            break;
        
        case '*':
            return operando1 * operando2;
            break;
        
        default:
            return 0.0;
    }
}

float resolvePosfixa(char *exp, pilha *p) {
    int tamanhoExp = strlen(exp);
    float operando1;
    float operando2;
    float resultado = 0.0;
    char *token = strtok(exp, " ");

    /* Alocando memória com o objetivo de converter 'p->itens' para um float ao invés de um char, devido a erros de precisão */
    float *itens =  calloc(tamanhoExp, sizeof(pilha));
    if(itens == NULL)
        erroAssert(0, "Erro na alocação dinâmica de memória!\n");
    
    *itens = atof(p->itens); /* função para converter 'p->itens' para um ponteiro de float 'itens' */
    while(token != NULL)
    {
        if(token[0] == '+' || token[0] == '-' || token[0] == '/' || token[0] == '*')
        {
            operando1 = itens[p->topo]; /* desempilho o primeiro valor */
            p->tamanho--;
            p->topo--;

            operando2 = itens[p->topo]; /* desempilho o segundo valor */
            p->tamanho--;
            p->topo--;
            
            resultado = operacaoPosfixa(operando2, operando1, token[0]); /* realiza a operação com os dois valores desempilhados */

            p->topo++;
            itens[p->topo] = resultado; /* empilha o resultado */
            p->tamanho++;
        }

        else 
        {
            resultado = atof(token); /* converte a string token para um float */
            p->topo++;
            itens[p->topo] = resultado; /* empilha o resultado */
            p->tamanho++;
        }
        token = strtok(NULL, " ");
    }
    operando1 = itens[p->topo]; /* desempilhamos o ultimo número da pilha */
    resultado = operando1;
    p->tamanho--;
    p->topo--;

    free(itens);
    return resultado;
}