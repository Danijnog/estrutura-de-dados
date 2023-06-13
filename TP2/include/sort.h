#ifndef SORT_HPP
#define SORT_HPP

#include "point.h"

#include <iostream>
#include <math.h>

#define TAM 20 // Tamanho do balde pra ser usado no bucketSort

/**
 * @brief Struct que representa um balde que será utilizado exclusivamente no bucketSort.
 * 
 */
typedef struct bucket {
    Point values[TAM];
    int qtd;
} Bucket;

class Sort {

    public:

    /**
     * @brief Construtor padrão da Classe.
     */
    Sort();

    /**
     * @brief Destrutor padrão da Classe.
     * 
     */
    ~Sort();
    
    /**
     * @brief Divide recursivamente o conjunto de dados até que cada subconjunto possua 1 elemento.
                Combina 2 subconjuntos de forma a obter 1 conjunto maior e ordenado.
                Complexidade de pior caso e melhor caso: O(nlog(n)) - Estável
     * 
     * @param points 
     * @param inicio 
     * @param fim 
     * @param p0 
     * @return * void 
     */
    void mergeSort(Point *points, int inicio, int fim, Point p0);

    /**
     * @brief Combina 2 subconjuntos de forma a obter 1 conjunto maior e ordenado de pontos.
                Complexidade de pior caso e melhor caso: O(nlog(n)) - Estável
     * 
     * @param points 
     * @param inicio 
     * @param meio 
     * @param fim 
     * @param p0 
     * @return * void 
     */
    void merge(Point *points, int inicio, int meio, int fim, Point p0);

    /**
     * @brief Ordenação por inserção.
                Complexidade do melhor caso: O(n), pior caso: O(n^2) - Estável
     * 
     * @param points 
     * @param size 
     * @param p0 
     * @return * void 
     */
    void insertionSort(Point *points, int size, Point p0);


    /**
     * @brief Distribui os pontos a serem ordenados em um conjunto de baldes.
                Ordena os pontos em cada balde e depois percorre os baldes e 
                coloca os valores ordenados de volta no array de pontos.
                Performance: Melhor caso: O(n + K), onde K é o número de baldes.
                             Pior caso: O(n^2), todos são colocados no mesmo balde.
     * 
     * @param points 
     * @param size 
     * @param p0 
     * @return * void 
     */
    void bucketSort(Point *points, int size, Point p0);

};

#endif