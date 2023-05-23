#include "../include/heap.h"

void constroiHeap(int *Array, int esq, int dir) {
    int aux = Array[esq]; // elemento pai
    int j = esq * 2 + 1; // calculamos um dos filhos do elemento pai

    while(j <= dir)
    {
        if(j < dir) 
        {
            if(Array[j] < Array[j + 1]) // verificando qual filho é maior
                j++;
        }
        if(aux < Array[j]) // elemento pai é menor que o filho?
        {
            Array[esq] = Array[j];
            esq = j;
            j = 2 * esq + 1;
        }
        else
            j = dir + 1;
    }
    Array[esq] = aux;
}

void heapSort(int *Array, int n) {
    int i, aux;
    for(i = (n - 1) / 2; i >= 0; i--) /* constroi o heap da metade até o começo, deixando a árvore com as conformidades do heap */
        constroiHeap(Array, i, n - 1);

    for(i = n - 1; i >= 1; i--) /* pega o maior elemento do topo da árvore e coloca no final do vetor e acha o maior do vetor restante */
    {
        aux = Array[0];
        Array[0] = Array[i];
        Array[i] = aux;
        constroiHeap(Array, 0, i - 1); /* reconstroi a heap */
    }
}

void printArray(int *Array, int n) {
    for(int i = 0; i < n; i++)
        std::cout << Array[i] << " ";

    std::cout << std::endl;
}
