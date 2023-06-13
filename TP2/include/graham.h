#ifndef GRAHAM_H
#define GRAHAM_H

#include "point.h"
#include "stack.h"

#include <iostream>
#include <stdlib.h>

/* Algoritmo de Graham para determinar o fecho convexo de um conjunto de pontos
    Possui complexidade O(nlog(n))
*/
class Graham {

    public:
        /**
         * @brief Construtor padrão.
         * 
         */
        Graham();

        /**
         * @brief Destrutor padrão da classe.
         * 
         */
        ~Graham();

        /**
         * @brief Algoritmo Scan de Graham para determinar o fecho convexo do conjunto de pontos passado como parãmetro.
         * 
         * @param points 
         * @param n 
         * @param p0 
         * @return * Stack 
         */
        Stack grahamScan(Point *points, int size, Point p0);

        /**
         * @brief Algoritmo Scan de Graham utilizando o Mergesort como ordenação dos pontos, antes de determinar o fecho convexo.
         * 
         * @param points 
         * @param n 
         * @return * Stack 
         */
        Stack grahamScanWithMergesort(Point *points, int size);

        /**
         * @brief Algoritmo Scan de Graham utilizando o InsertionSort como ordenação dos pontos, antes de determinar o fecho convexo.
         * 
         * @param points 
         * @param n 
         * @return * Stack 
         */
        Stack grahamScanWithInsertionSort(Point *points, int size);

        /**
         * @brief Algoritmo Scan de Graham utilizando o BucketSort como ordenação dos pontos, antes de determinar o fecho convexo.
         * 
         * @param points 
         * @param n 
         * @return * Stack 
         */
        Stack grahamScanWithBucketSort(Point *points, int size);

        /**
         * @brief Encontra o indice do ponto que possui a menor coordenada y, se houver empate compara a coordenada x.
         * 
         * @param points 
         * @param n 
         * @return * int 
         */
        int getMostBottomIndex(Point *points, int size);
};

#endif