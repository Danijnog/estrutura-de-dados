/*---------------------------------------------------------------------
 Arquivo	: arvoreAvl.c
 Conteudo	:  A seguinte árvore AVL foi implementada originalmente realizando o balanceamento pela altura das subárvores da esquerda
    e das subárvores da direita.
    Porém, foi modificada para realizar o balanceamento pelo peso dos nós da subárvore da esquerda e da direita, apesar
    de manter as funções de altura da árvore. 
 Autor	    : Daniel Nogueira Junqueira (danijnog@ufmg.br)
 Historico	: 2023-05-31 - arquivo criado
--------------------------------------------------- */

#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/time.h>

typedef struct stat{
  int RR;
  int LL;
  int RL;
  int LR;
} stat_t;

typedef struct node {
  int data;
  struct node * left, * right;
  int ht;
  int weight;
} node;

node * insert(node * , int, stat_t *);
node * Delete(node * , int, stat_t *);
void preorder(node * );
void inorder(node * );
void dump(node *, int, char* );
int height(node * );
int weight(node * );
node * rotateright(node * );
node * rotateleft(node * );
node * RR(node * );
node * LL(node * );
node * LR(node * );
node * RL(node * );
int BF(node * );

#endif