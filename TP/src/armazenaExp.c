#include "../include/armazenaExp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void criaPilha(pilha *p) {
    p->tamanho = 0;
    p->topo = -1;
}

void empilha(pilha *p, char *exp) {
    if(p->tamanho == MAX_TAM_EXP)
        printf("Pilha cheia!\n");
    
    p->topo++;
    p->itens[p->topo] = *exp;
    p->tamanho++;
}

char desempilha(pilha *p) {
    if(p->tamanho == 0)
        printf("A pilha está vazia!\n");
    
    char aux = p->itens[p->topo];
    p->tamanho--;
    p->topo--;
    return aux;
}

void limpaPilha(pilha *p) {
    p->topo = -1;
    p->tamanho = 0;
}

void imprimePilha(pilha *p) {
    for(int i = 0; i < p->tamanho; i++)
        printf("p[%d] = %c \n", i, p->itens[i]);
}

int armazenaExp(pilha *p, char *exp) {
    int tamanhoExp = strlen(exp);
    criaPilha(p);
    for(int i = 0; i < tamanhoExp; i++)
        empilha(p, &exp[i]);
    return 0;
}

int validaEntrada(int argc, char **argv) {
    if(argc < 2 || argc >= 3)
    {
        fprintf(stderr, "Entrada inválida! :(\n");
        fprintf(stderr, "Exemplo de entrada: 'bin/main nome_do_arquivo.txt', contanto que o arquivo esteja no mesmo diretório! \n");
        exit(1);
        return 0;
    }
    return 1;
}

