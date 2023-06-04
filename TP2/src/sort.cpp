#include "../include/sort.h"
#include "../include/point.h"
#include "../include/graham.h"

Sort::Sort() {}

void Sort::mergeSort(Point *points, int inicio, int fim, Point p0) {
    int meio;
    if(inicio < fim)
    {
        meio = floor((inicio + fim) / 2); // Floor arredonda o valor para baixo caso seja um ponto flutuante
        mergeSort(points, inicio, meio, p0);
        mergeSort(points, meio + 1, fim, p0);
        merge(points, inicio, meio, fim, p0); // Combina as 2 metades de forma ordenada
    }
}

void Sort::merge(Point *points, int inicio, int meio, int fim, Point p0) {
    int p1 = meio - inicio + 1;
    int p2 = fim - meio;

    // Indices dos subarrays que vão ser temporários
    int indexStart = 0;
    int indexEnd = 0;

    // Indice do array points que vai ser a união dos subarrays
    int indexMerged = inicio;

    // Arrays temporários de subconjunto de pontos
    Point *pointStart = new Point[p1];
    Point *pointEnd = new Point[p2];

    for(int i = 0; i < p1; i++)
        pointStart[i] = points[inicio + i];
    
    for(int j = 0; j < p2; j++)
        pointEnd[j] = points[meio + 1 + j];

    // Compara os pontos com base nas coordenadas X e Y
    while(indexStart < p1 && indexEnd < p2) 
    {
        if(pointStart[indexStart].getY() < pointEnd[indexEnd].getY()) // Coordenada y do primeiro ponto é menor que o segundo
        {
            points[indexMerged] = pointStart[indexStart];
            indexStart++;
        }

        else if(pointStart[indexStart].getY() == pointEnd[indexEnd].getY()) // Coordenadas y dos pontos são iguais
        {
            if(pointStart[indexStart].getX() < pointEnd[indexEnd].getX()) // Analisa a coordenada x no caso dos pontos y serem iguais
            {
                points[indexMerged] = pointStart[indexStart];
                indexStart++;
            }
            else
            {
                points[indexMerged] = pointEnd[indexEnd];
                indexEnd++;
            }
        }
        else // Coordenada y do primeiro ponto é maior que do segundo
        {
            points[indexMerged] = pointEnd[indexEnd];
            indexEnd++;
        }
        indexMerged++;
    }

    // Copia os elementos do subconjunto de pontos do inicio se ainda houver algum
    while(indexStart < p1)
    {
        points[indexMerged] = pointStart[indexStart];
        indexStart++;
        indexMerged++;
    }

    // Copia os elementos do subconjunto de pontos do final se ainda houver algum
    while(indexEnd < p2)
    {
        points[indexMerged] = pointEnd[indexEnd];
        indexEnd++;
        indexMerged++;
    }

    // Ordenar os pontos em relação ao ponto inicial computando o ângulo entre os pontos
    for(int i = inicio + 1; i <= fim; i++)
    {
        for(int j = i + 1; j <= fim; j++)
        {
            double firstAngle = points[inicio].computeAngle(points[i]);
            double secondAngle = points[inicio].computeAngle(points[j]);

            if(firstAngle > secondAngle)
            {
                Point aux = points[i];
                points[i] = points[j];
                points[j] = aux;
            }
        }
    }

    delete[] pointStart;
    delete[] pointEnd;
}

void Sort::insertionSort(Point *points, int size, Point p0) {
    // Primeiro é feita a ordenação em relação às coordenadas X e Y
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(points[j].getY() < points[i].getY() ||
               (points[i].getY() == points[j].getY()
               && points[j].getX() < points[i].getX()))
            {
                Point aux = points[j];
                points[j] = points[i];
                points[i] = aux;
            }
        }
    }

    // Ordenar os pontos em relação a p0 por inserção comparando os angulos dos pontos
    int j = 0;
    for(int i = 1; i < size; i++)
    {
        Point aux = points[i];
        double secondAngle = p0.computeAngle(aux);

        // Enquanto o ângulo do ponto na posição i na posição i for menor que na posição i - 1
        j = i;
        while(j > 0 && secondAngle < p0.computeAngle(points[j - 1]))
        {
            points[j] = points[j - 1];
            j--;
        }
        points[j] = aux;
    }
}

void Sort::bucketSort(Point *points, int size, Point p0) {
    Point biggestPoint = Point();
    Point smallerPoint = Point();
    
    int pos = 0;
    //Encontra o ponto com o maior e menor angulo em relação a p0
    biggestPoint = smallerPoint = points[0];
    for(int i = 1; i < size; i++)
    {
        if(p0.computeAngle(points[i]) > p0.computeAngle(biggestPoint))
            biggestPoint = points[i];
        
        if(p0.computeAngle(points[i]) < p0.computeAngle(smallerPoint))
            smallerPoint = points[i];
    }

    // Inicializa os baldes (buckets)
    int numberOfBuckets = floor(p0.computeAngle(biggestPoint) - p0.computeAngle(smallerPoint) / TAM + 1);
    Bucket *bucket = new Bucket[numberOfBuckets * sizeof(Bucket)];
    for(int i = 0; i < numberOfBuckets; i++)
        bucket[i].qtd = 0; // Não tem nenhum elemento no balde
    
    // Distribui os pontos nos baldes
    for(int i = 0; i < size; i++)
    {
        pos = p0.computeAngle(points[i]) - p0.computeAngle(smallerPoint) / TAM;
        bucket[pos].values[bucket[pos].qtd] = points[i];
        bucket[pos].qtd++;
    }

    pos = 0;
    // Ordena os baldes e coloca no array de pontos
    for(int i = 0; i < numberOfBuckets; i++)
    {
        insertionSort(bucket[i].values, bucket[i].qtd, p0); // Realiza a ordenação em cada balde através do insertionSort
        for(int j = 0; j < bucket[i].qtd; j++)
        {
            points[pos] = bucket[i].values[j]; // Coloca os pontos ordenados no array de pontos
            pos++;
        }
    }
    delete[] bucket;
} 
