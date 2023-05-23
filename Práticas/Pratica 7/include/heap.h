#ifndef HEAP_H
#define HEAP_H

#include <iostream>

/* Representação de uma árvore por meio de vetores para realizar o heapsort
    nós são numerados de 1 a n
    os nós '2i' e '2i + 1' são filhos da esquerda e direita do nó i, para 1 <= i <= n/2
*/

void constroiHeap(int *Array, int n);
void heapSort(int *Array, int n);
void printArray(int *Array, int n);


#endif