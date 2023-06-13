#include "../include/graham.h"
#include "../include/sort.h"
#include "../include/stack.h"
#include "../include/exceptions.h"

Graham::Graham() {}

Graham::~Graham() {}

int Graham::getMostBottomIndex(Point *points, int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++)
        if (points[i].getY() < points[minIndex].getY() || (points[i].getY() == points[minIndex].getY() && points[i].getX() < points[minIndex].getX()))
            minIndex = i;

    return minIndex;
}

Stack Graham::grahamScan(Point *points, int size, Point p0) {
    // Verifica se o tamanho do array é válido
    if(size < 2)
        throw tamanhoArrayPontosInvalido();
    
    // Se no array de pontos só tiver pontos colineares, o fecho convexo é a linha que liga o primeiro e o último ponto
    if(Point::verifyCollinearPoints(points, size))
    {
        Stack stack = Stack();
        stack.push(points[0]);
        stack.push(points[size - 1]);

        return stack;
    }

    int m = 1;
    for(int i = 1; i < size; i++)
    {
        //continua removendo i enquanto o angulo de i e i + 1 for igual respeitando p0
        while(i < size - 1 && Point::orientation(p0, points[i], points[i + 1]) == 0)
            i++;
        points[m] = points[i];
        m++; //atualiza o tamanho do array modificado
    }

    if(m < 2) //se o array modificado tiver menos que 3 pontos, figura convexa não é possível
    {
        throw tamanhoArrayPontosInvalido();
    }

    // Cria uma pilha vazia e empilha os primeiros 3 pontos
    Stack stack = Stack();
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);

    // Continua o processo para size-3 pontos
    for(int i = 3; i < m; i++)
    {
        // Enquanto o tamanho da pilha for maior que 1 e a orientação for diferente de 2 (sentido anti-horário)
        // continua desempilhando a pilha
        while(stack.getSize() > 1 && Point::orientation(Stack::nextToTop(stack), stack.getTop(), points[i]) != 2)
            stack.pop();
        
        stack.push(points[i]);
    }
    return stack;
}

Stack Graham::grahamScanWithMergesort(Point *points, int size) {
    Sort sort = Sort();
    Stack stack = Stack();

    // Encontra o ponto com o menor valor de y, se houver empate analisa a menor coordenada x
    int min = getMostBottomIndex(points, size);

    // Coloca o ponto de referência na primeira posição
    Point::swap(points[0], points[min]);
    Point p0 = points[0];
    sort.mergeSort(points, 0, size - 1, p0);
    stack = grahamScan(points, size, p0);

    return stack;
}

Stack Graham::grahamScanWithInsertionSort(Point *points, int size) {
    Sort sort = Sort();
    Stack stack = Stack();

    // Encontra o ponto com o menor valor de y, se houver empate analisa a menor coordenada x
    int min = getMostBottomIndex(points, size);

    // Coloca o ponto de referência na primeira posição
    Point::swap(points[0], points[min]);
    Point p0 = points[0];
    sort.insertionSort(points, size, p0);
    stack = grahamScan(points, size, p0);

    return stack;
}

Stack Graham::grahamScanWithBucketSort(Point *points, int size) {
    Sort sort = Sort();
    Stack stack = Stack();

    // Encontra o ponto com o menor valor de y, se houver empate analisa a menor coordenada x
    int min = getMostBottomIndex(points, size);

    // Coloca o ponto de referência na primeira posição
    Point::swap(points[0], points[min]);
    Point p0 = points[0];
    sort.bucketSort(points, size, p0);
    stack = grahamScan(points, size, p0);

    return stack;
}