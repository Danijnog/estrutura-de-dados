#ifndef ARMAZENA_EXP_H
#define ARMAZENA_EXP_H

#define MAX_TAM_EXP 1000

typedef struct Pilha {
    char itens[MAX_TAM_EXP];
    int topo;
    int tamanho;
} pilha;

/**
 * @brief Valida a entrada que é digitada na linha de comando no programa.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int validaEntrada(int argc, char **argv);

/**
 * @brief Armazena uma expressão na pilha, criando a pilha e empilhando a expressão.
 * 
 * @param p - pilha criada passada como parâmetro
 * @param exp - expressão passada como parâmetro
 * @return * int 
 */
int armazenaExp(pilha *p, char *exp);


void criaPilha(pilha *p);
void empilha(pilha *p, char *exp);
char desempilha(pilha *p);
void limpaPilha(pilha *p);
void imprimePilha(pilha *p);

#endif