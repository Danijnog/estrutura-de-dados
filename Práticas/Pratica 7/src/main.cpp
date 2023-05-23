#include "../include/heap.h"
#include "../include/shellsort.h"
#include "../include/rand.h"

int main () {
    struct rusage start, end; //estrutura para armazenar o tempo de usuario e sistema decorrido
    
    printf("\nATENÇÃO: cada execução do programa gera um conjunto de vetores aleatórios, de tamanho de 1 a 340 no máximo, com valores de 0 a 100, a ser ordenado tanto pelo Heapsort quanto pelo Shellsort!\n");
    printf("Também é realizada a análise do tempo de usuário e tempo de sistema de cada chamada da função de realizar o Heapsort e o Shellsort :) \n\n");

    srand(time(NULL));
    int n = rand() % MIN_TAM + 1; //o tamanho do array vai variar em cada execução, possuindo o tamanho pelomenos 1

    std::cout << " Primeiro array aleatório" << std::endl;
    int *randArray = randomArray(n, MAX_VALUE);
    int *randArrayAux = randArray;
    printArray(randArray, n);
    std::cout << "-------------" << std::endl;

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Heapsort)
    std::cout << "Heapsort sendo realizado...." << std::endl;
    heapSort(randArray, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Heapsort)

    printArray(randArray, n);
    printf("Heapsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo do sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Shellsort)
    std::cout << "Shellsort sendo realizado...." << std::endl;
    shellSort(randArrayAux, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Shellsort)

    printArray(randArrayAux, n);
    printf("Shellsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo de sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    n = n + rand() % 20;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << " Segundo array aleatório" << std::endl;
    randArray = randomArray(n, 40);
    randArrayAux = randArray;
    printArray(randArray, n);
    std::cout << "-------------" << std::endl;

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Heapsort)
    std::cout << "Heapsort sendo realizado...." << std::endl;
    heapSort(randArray, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Heapsort)
    
    printArray(randArray, n);
    printf("Heapsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo do sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Shellsort)
    std::cout << "Shellsort sendo realizado...." << std::endl;
    shellSort(randArrayAux, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Shellsort)

    printArray(randArrayAux, n);
    printf("Shellsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo do sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    n = n + rand() % 20;

    std::cout << "---------------------------------------" << std::endl;
    std::cout << std::endl;

    std::cout << " Terceiro array aleatório" << std::endl;
    randArray = randomArray(n, 40);
    randArrayAux = randArray;
    printArray(randArray, n);
    std::cout << "-------------" << std::endl;

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Heapsort)
    std::cout << "Heapsort sendo realizado...." << std::endl;
    heapSort(randArray, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Heapsort)

    printArray(randArray, n);
    printf("Heapsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo do sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    getrusage(RUSAGE_SELF, &start); //começando o processo da thread atual (Shellsort)
    std::cout << "Shellsort sendo realizado...." << std::endl;
    shellSort(randArrayAux, n);
    getrusage(RUSAGE_SELF, &end); //encerrando o processo da thread atual (Shellsort)

    printArray(randArrayAux, n);
    printf("Shellsort status: \n");
    printf("-Tempo de usuário: %.07f seg, tempo do sistema: %.08f seg\n\n", difTempoUsuario(&start, &end), difTempoSistema(&start, &end));

    delete[] randArray;
        
    return 0;
}