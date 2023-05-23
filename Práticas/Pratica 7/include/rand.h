#ifndef RAND_H
#define RAND_H

#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "sys/resource.h"

#define MIN_TAM 300
#define MAX_VALUE 100

int *randomArray(int n, int max);

float difTempoUsuario(struct rusage *start, struct rusage *end); //função para calcular o tempo de usuario decorrido em segundos
float difTempoSistema(struct rusage *start, struct rusage *end); //função para calcular o tempo do sistema decorrido em segundos


#endif