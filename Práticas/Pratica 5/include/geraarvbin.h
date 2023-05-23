#ifndef GERA_ARVORE_H
#define GERA_ARVORE_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>


// Syntax tree structure
typedef long TipoChave; //chave da árvore

typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo { //nó da arvore que contem o registro da chave e o apontador para os nós da esquerda e da direita
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm {
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

#endif

void dumpTree(TipoApontador * T, int level, prm_t * prm);
int createTree(TipoNo ** curr, int level, prm_t * prm);
