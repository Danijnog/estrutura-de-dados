#ifndef ARVORE_H
#define ARVORE_H

typedef struct no {
    struct no *esq;
    struct no *dir;
    int conteudo;
} No;

typedef struct tree {
    No *raiz;
} Tree;

void inserir(Tree *tree, int valor);
void inserirDireita(No *no, int valor);
void inserirEsquerda(No *no, int valor);
void imprimir(No *raiz);


#endif