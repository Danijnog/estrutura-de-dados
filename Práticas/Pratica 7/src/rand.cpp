#include "../include/rand.h"
#include <iostream>

int *randomArray(int n, int max) {
    srand(time(NULL)); // a função time(null) retorna o numero de segundos de 1970 até o momento atual
                                    // e com isso usamos como semente na função srand pra gerar números pseudo-aleatórios
    int *Array = new int[n];
    for(int i = 0; i < n; i++)
        Array[i] = rand() % max;
    
    return Array;
}

float difTempoUsuario(struct rusage *start, struct rusage *end) { //função para calcular o tempo de usuario decorrido em segundos
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
            1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
} 

float difTempoSistema(struct rusage *start, struct rusage *end) { //função para calcular o tempo do sistema decorrido em segundos
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
            1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}