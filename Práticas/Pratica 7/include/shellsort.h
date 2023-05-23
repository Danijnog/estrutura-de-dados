#ifndef SHELL_SORT_H
#define SHELL_SORT_H

#include <iostream>

/* Compara itens de um vetor separados por 'h' posições
    A posição x é comparada com a posição x - h
    Quando h = 1, shellsort equivale ao insertionSort
*/

void shellSort(int *V, int n);

#endif