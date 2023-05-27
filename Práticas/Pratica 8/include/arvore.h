#ifndef ARVORE_H
#define ARVORE_H

typedef struct no {
    struct no *esq;
    struct no *dir;
    int conteudo;
    int id;
} No;

typedef struct tree {
    No *raiz;
} Tree;

void inserir(Tree *tree, int valor, int id);
void inserirDireita(No *no, int valor, int id);
void inserirEsquerda(No *no, int valor, int id);
void imprimir(No *raiz, int *id); /* temos que passar o parâmetro id por referencia para atualizar
                                 corretamente o valor de "id" a cada chamada recursiva */


#endif