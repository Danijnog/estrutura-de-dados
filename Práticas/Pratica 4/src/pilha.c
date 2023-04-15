#include "../include/pilha.h"
#include "fila.h"
#include "stdio.h"

void criaPilha(struct fila *f) {
    criaFila(f);
}

int empilha (struct fila *f) { //empilha os itens por meio da fila circular, desinfileirando a fila
    int aux;

    if(filaCheia(f))
        printf("Pilha cheia!\n");
    else  
    {
        for(int i = 0; i < f->fim; i++)
        {
            aux = desenfileira(f); //desenfileira um elemento da fila e armazena na variável aux
            f->itens[f->fim] = aux; //o item que tiver no fim da fila vai receber a variável aux
            f->tamanho++; //incrementa o tamanho
            printf("%d ", f->itens[f->fim]);
        }
    }
    return f->itens[f->fim];
}

int desempilha (struct fila *f) {
    int aux = 0;

    if(filaVazia(f)) 
        printf("A pilha está vazia!\n");
    else  
    {
        aux = f->itens[f->fim - 1];
        f->fim--;
        f->tamanho--;
        printf("%d \n", aux);  
    }
    return aux; 
}

void itemEmpilhado(struct fila *f, int item) {
    enfileira(f, item);
}

void imprimePilha(struct fila *f) {
    imprimeFila(f);
}

void destroiPilha(struct fila *f) {
    destroiFila(f);
}

