#include "../include/arvore.h"
#include "../include/memLog.h"
#include <stdio.h>
#include <stdlib.h>

void inserirDireita(No *no, int valor, int id) {
    if(no->dir == NULL)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        no->dir = novoNo;
        no->dir->id = id;
        ESCREVEMEMLOG((long int) (&(no->dir)), sizeof(No), no->dir->id);
    }

    else
    {
        if(valor < no->dir->conteudo) /* se o valor for menor que o conteudo do nó a direita*/
        {
            inserirEsquerda(no->dir, valor, id);
        }
        
        else if(valor > no->dir->conteudo)
        {
            inserirDireita(no->dir, valor, id);
        }
    }
}

void inserirEsquerda(No *no, int valor, int id) {
    if(no->esq == NULL)
    {
        No *novoNo = malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        no->esq = novoNo;
        no->esq->id = id;
        ESCREVEMEMLOG((long int) (&(no->esq)), sizeof(No), no->esq->id);
    }

    else /* se o nó da esquerda não for nulo*/
    {
        if(valor < no->esq->conteudo) /* se o valor for menor que o conteudo do nó a esquerda */
        {
            inserirEsquerda(no->esq, valor, id);
        }
        
        else if(valor > no->esq->conteudo) 
        {
            inserirDireita(no->esq, valor, id);

        }
    }
}

void inserir(Tree *tree, int valor, int id) {
    if(tree->raiz == NULL)
    {
        No *novoNo = (No*) malloc(sizeof(No));
        novoNo->conteudo = valor;
        novoNo->esq = NULL;
        novoNo->dir = NULL;

        tree->raiz = novoNo;
        tree->raiz->id = id;
        //ESCREVEMEMLOG((long int) (&(tree->raiz)), sizeof(Tree), tree->raiz->id);
    }
    else /* se a raiz não for nula */
    {
        if(valor < tree->raiz->conteudo) /* se o valor for menor que o conteúdo da raiz */
            inserirEsquerda(tree->raiz, valor, id);
        
        else if(valor > tree->raiz->conteudo)
            inserirDireita(tree->raiz, valor, id);
    }
}

void imprimir(No *raiz, int *id) { /* tivemos que passar id por referência para que atualize corretamente o valor de cada nó a cada chamada recursiva*/
    if(raiz != NULL)
    {
        imprimir(raiz->esq, id); /* esse formato de impressão está em formato in-ordem (ordenada) */
        printf("%d ", raiz->conteudo);
        raiz->id = *id;
        LEMEMLOG((long int)(&(raiz->conteudo)), sizeof(No), raiz->id);
        imprimir(raiz->dir, id);
    }
}