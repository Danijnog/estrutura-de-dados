#include "../include/shellsort.h"

void shellSort(int *V, int n) {
    int i, j, h, aux;

    h = 1;
    h = (h + 1) * 3; /* teoricamente, essa é a melhor sequencia que se pode ter do 'h' */
    
    while(h > 0)
    {
        for(i = h; i < n; i++)
        {
            aux = V[i];
            j = i;
            // efetua comparações entre elementos de distância 'h'
            while(j >= h && aux < V[j - h])
            {
                V[j] = V[j - h];
                j = j - h;
            }
            V[j] = aux;
        }
        h = (h - 1) / 3; // atualiza o valor do h
    }
}