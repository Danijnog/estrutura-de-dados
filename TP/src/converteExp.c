#include "../include/converteExp.h"
#include "../include/armazenaExp.h"
#include "../include/msgAssert.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char *infixaParaPosfixa(char *exp, pilha *p) {
    int tamanhoExp = strlen(exp);
    int i = 0; //percorrer a infixa
    int j = 0; //percorrer a posfixa
    p->topo = 0;

    /* É necessário alocar tamanhoExp + 2 por causa da string terminar em '\0'  e
    devido a manipulação que fiz no final da função em adicionar um espaço entre o ultimo numero e o ultimo caracter*/
    char *posfixa = calloc((tamanhoExp + 2), sizeof(char)); 
    if(posfixa == NULL)
        erroAssert(0, "Erro na alocação de memória!\n");

    for(i = 0; exp[i] != '\0'; i++)
    {
        switch(exp[i])
        {       
            char auxTopo;
            case '(': /* comeco do bloco */
                empilha(p, &exp[i]);
                break;
            
            case ')': /* fim do bloco */
                auxTopo = desempilha(p);

                while(auxTopo != '(')
                {
                    posfixa[j] = auxTopo; /* enquanto nao é um fim de bloco, atribui o auxTopo na posfixa */ 
                    j++;
                    auxTopo = desempilha(p); /* continua desempilhando até chegar no fim do bloco */
                }
                break;
            
            case '+': /* tanto o operador '+' quanto o '-' caem na mesma lógica, então podemos fazer um case desse formato */
            case '-':
                while(p->topo > 0 && p->itens[p->topo] != '(') /* enquanto não chegar em um ínicio de bloco */
                {
                    posfixa[j] = desempilha(p);
                    j++;
                }
                empilha(p, &exp[i]); /* quando chega em um inicio de bloco eu empilho o operandor '+' ou '-' */
                break;
            
            case '*':
            case '/':
                /* Joga na posfixa o conteúdo da pilha até estar vazia, encontrar o inicio do bloco '('
                ou encontrar o operador de menor precedência '+' ou '-' */
                while(p->topo > 0 && p->itens[p->topo] != '('
                && p->itens[p->topo] != '+' && p->itens[p->topo] != '-') /* enquanto a pilha for maior que 0 e o topo for diferente de '(', '+', '-' */
                {
                    posfixa[j] = desempilha(p);
                    j++;
                }
                /* Quando sai do while, ja foi desempilhado todos os operadores que vieram antes e que tem prioridade */
                empilha(p, &exp[i]);
                break;
            
            default: /* caso dos operandos */
                posfixa[j] = exp[i]; /* atribui os operandos para a posfixa */
                j++;
                              
        }
    }

    /* desempilhando o que sobrou na pilha */ 
    while(p->topo > 0)
    {
        posfixa[j] = desempilha(p);
        j++;
    }

    /* Adicionando um espaço entre o ultimo operando e o ultimo operador*/
    char auxAdicionarEspaco;
    posfixa[j] = '\0';
    j--;
    auxAdicionarEspaco = posfixa[j];
    posfixa[j] = ' ';
    posfixa[j + 1] = auxAdicionarEspaco;

    armazenaExp(p, posfixa); /* armazena a expressão posfixa na pilha */
    return posfixa;
}

int ehOperando(char *operando) {
    for(int i = 0; i < strlen(operando); i++)
    {
        if(operando[i] >= '0' && operando[i] <= '9')
            return 1;
    }
    return 0;
}

char *posfixaParaInfixa(char *exp, pilha *p) {
    int tamanhoExp = strlen(exp);
    int countEmpilha = 0; /* variável para contar quantos tokens foram empilhados, necessária para que não empilhe mais de 2 tokens de uma vez */
    int topoAux = -1;
    int i = 0;
    
    char *token = strtok(exp, " ");
    char *infixa;
    char *pilhaAux[MAX_TAM_EXP];
    
    while(i < tamanhoExp) {    
        switch(exp[i])
        {
            case '+':
            case '-':   
            case '*':
            case '/':
                countEmpilha = 0; /* zera o contador da quantidade de tokens que empilhei */

                /* Desempilho os dois tokens empilhados */
                char *operando1 = pilhaAux[topoAux];
                topoAux--;
                char *operando2 = pilhaAux[topoAux];
                topoAux--;

                char *concatena;
                concatena = malloc(tamanhoExp * 2);
                if(concatena == NULL)
                {
                    fprintf(stderr, "Erro na alocação de memória!\n");
                    free(operando1);
                    free(operando2);
                }
                else
                {
                    sprintf(concatena, "( %s %c %s )", operando2, exp[i], operando1); /* concatena e formata os dois operandos com o atual operador */
                    topoAux++; 
                    pilhaAux[topoAux] = concatena; /* empilha o resultado da concatenação */
                }
                concatena = NULL;
                free(concatena);
                break;
                
            default:
                while(token != NULL)
                {
                    if(ehOperando(token))
                    {
                        if(countEmpilha >= 2) /* verificação para empilhar sempre no máximo 2 tokens a cada vez */
                            break;

                        topoAux++; /* empilha o token */
                        pilhaAux[topoAux] = token;
                        countEmpilha++;
                    }
                    token = strtok(NULL, " ");
                }
                break;
        }
        i++; 
    }
    /* Atribuindo os itens que estão na pilha para a expressão infixa */
    infixa = pilhaAux[topoAux];
    topoAux--;
    armazenaExp(p, infixa); /* armazena a expressão convertida na pilha */

    for(int j = 0; j <= topoAux; j++)
        free(pilhaAux[j]);

    return infixa;
}