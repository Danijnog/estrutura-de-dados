#include "../include/entry.h"
#include "../include/convexHull.h"
#include "../include/exceptions.h"
#include "../include/graham.h"
#include "../include/jarvis.h"
#include "../include/timer.h"

#include "../include/sort.h"

#include <bits/getopt_core.h>
#include <fstream>

int draw = 0;
int validateEntry(int argc, char **argv) {
    if(argc < 2 || argc > 3)
        throw entradaInvalida();

    int aux;
    // Verifica se o segundo parametro existe para desenhar o fecho convexo ou não
    if(argc == 3)
    {
        aux = getopt(argc, argv, "d"); // Aux recebe "d" se o parametro -d for passado
        if(aux == 'd')
            draw = 1;
        else 
            throw entradaInvalida();
    }
    return 1;
}
void readEntry(int argc, char **argv) {
    Stack stack = Stack();
    Stack jarvisStackDrawConvexHull = Stack();
    Line straightLine = Line();
    Graham graham = Graham();
    Jarvis jarvis = Jarvis();
    ConvexHull convexHull = ConvexHull();
    Point points[10000];

    struct rusage start, end; // Estrutura para armazenar o tempo de usuário decorrido
    
    ifstream file(argv[1]); // Ler um arquivo passado no primeiro parametro do argv

    if(!file.is_open())
        throw erroAoAbrirArquivo();
    
    int size = 0;
    char line[1000];
    while(file.getline(line, 10000)) // Le cada linha do arquivo até o final
    {
        int x, y;
        sscanf(line, "%d %d", &x, &y); // O primeiro valor da linha será a coordenada x, e o segundo valor a coordenada y
        Point p = Point(x, y); // Transforma esses valores para o tipo ponto
        points[size] = p; // Amazena em um array de pontos
        size++;
    }
    // Fecho convexo de Jarvis que é printado no terminal sem desenhar
    jarvisStackDrawConvexHull = jarvis.jarvisMarch(points, size);
    convexHull.displayConvexHull(jarvisStackDrawConvexHull);

    // Se o usuário passou a flag -d para desenhar o fecho convexo, então esse if retorna verdadeiro
    if(draw)
    {
        int min = graham.getMostBottomIndex(points, size);
        Point p0 = Point();
        Point::swap(points[0], points[min]);
        p0 = points[0];
        convexHull.drawConvexHull(jarvisStackDrawConvexHull, points, size, p0);
    }

    getrusage(RUSAGE_SELF, &start); // Inicio do processo atual da análise do scan de Graham com Mergesort
    stack = graham.grahamScanWithMergesort(points, size);
    getrusage(RUSAGE_SELF, &end); // Fim do processo atual da análise do scan de Graham com Mergesort
    printf("GRAHAM + MERGESORT: %.3fs\n", userTime(&start, &end));
    stack.clearStack();

    getrusage(RUSAGE_SELF, &start); // Inicio do processo atual da análise do scan de Graham com InsertionSort
    stack = graham.grahamScanWithInsertionSort(points, size);
    getrusage(RUSAGE_SELF, &end); // Fim do processo atual da análise do scan de Graham com InsertionSort
    printf("GRAHAM + INSERTIONSORT: %.3fs\n", userTime(&start, &end));
    stack.clearStack();

    getrusage(RUSAGE_SELF, &start); // Inicio do processo atual da análise do scan de Graham com InsertionSort
    stack = graham.grahamScanWithBucketSort(points, size);
    getrusage(RUSAGE_SELF, &end); // Fim do processo atual da análise do scan de Graham com InsertionSort
    printf("GRAHAM + LINEAR (BucketSort): %.3fs\n", userTime(&start, &end));
    stack.clearStack();

    getrusage(RUSAGE_SELF, &start); // Inicio do processo atual da análise do marchar de Jarvis
    stack = jarvis.jarvisMarch(points, size);
    getrusage(RUSAGE_SELF, &end); // Fim do processo atual da análise do marchar de Jarvis
    printf("JARVIS: %.3fs\n", userTime(&start, &end));
    stack.clearStack();

    file.close();
}