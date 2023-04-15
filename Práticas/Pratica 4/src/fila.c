#include "../include/fila.h"
#include <stdio.h>

void criaFila(struct fila *p) { // cria uma fila vazia
    p->inicio = 0;
    p->fim = 0;
    p->tamanho = 0;
}

int filaCheia(struct fila *p) { 
    if(p->tamanho == MAX_FILA)
        return 1;
    return 0;
}

int filaVazia(struct fila *p) {
    if(p->tamanho == 0)
        return 1;
    return 0;
}

int enfileira(struct fila *p, int item) {
    if(filaCheia(p))
       printf("Fila cheia!\n");
    else
    {
            p->itens[p->fim] = item; //armazenamos o item no final da fila
            // fila circular
            p->fim = (p->fim + 1) % MAX_FILA; // incrementa atras usando aritmetica modular para a fila circular
            p->tamanho++;
    }
    return 0;
}

int desenfileira(struct fila *p) {
    int aux = 0;

    if(filaVazia(p))
        printf("Fila vazia!\n");
    else 
    {
        aux = p->itens[p->inicio]; //armazenamos o item da frente em aux
        // fila circular
        p->inicio = (p->inicio + 1) % MAX_FILA; //incremente a frente usando aritmetica modular para a fila circula
        p->tamanho--; //decrementa o tamanho da fila
    }

    return aux;
}

void imprimeFila(struct fila *p) {
    int i;
    if(filaVazia(p))
        printf("Fila vazia, não foi possível imprimir!\n");
    else 
    {
        for(i = p->inicio; i < p->fim; i++)
            printf("%d ", p->itens[i]);
    }
}

void destroiFila(struct fila *p) {
    p->inicio = 0;
    p->fim = 0;
    p->tamanho = 0;
}