/* Implementação de uma pilha através de uma fila circular
Pilha -> Last in, first out */

#ifndef PILHA_H
#define PILHA_H

#include "fila.h"

void criaPilha(struct fila *f);
int empilha(struct fila *f);
int desempilha(struct fila *f);
void imprimePilha(struct fila *f);
void destroiPilha(struct fila *f);
void itemEmpilhado(struct fila *f, int item);

#endif