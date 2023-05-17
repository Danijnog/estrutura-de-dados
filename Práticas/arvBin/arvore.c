#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>

void inserirDireita(No *no, int valor) {
    if(no->dir == NULL)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        no->dir = novoNo;
    }

    else
    {
        if(valor < no->dir->conteudo) /* se o valor for menor que o conteudo do nó a direita*/
            inserirEsquerda(no->dir, valor);
        
        else
            inserirDireita(no->dir, valor);
    }
}

void inserirEsquerda(No *no, int valor) {
    if(no->esq == NULL)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        no->esq = novoNo;
    }

    else /* se o nó da esquerda não for nulo*/
    {
        if(valor < no->esq->conteudo) /* se o valor for menor que o conteudo do nó a esquerda */
            inserirEsquerda(no->esq, valor);
        
        else
            inserirDireita(no->esq, valor);
    }
}

void inserir(Tree *tree, int valor) {
    if(tree->raiz == NULL)
    {
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        tree->raiz = novoNo;
    }
    else /* se a raiz não for nula */
    {
        if(valor < tree->raiz->conteudo) /* se o valor for menor que o conteúdo da raiz */
            inserirEsquerda(tree->raiz, valor);
        
        else
            inserirDireita(tree->raiz, valor);
    }
}

void imprimir(No *raiz) {
    if(raiz != NULL)
    {
        imprimir(raiz->esq); /* esse formato de impressão está em formato in-ordem (ordenada) */
        printf("%d ", raiz->conteudo);
        imprimir(raiz->dir);
    }
}