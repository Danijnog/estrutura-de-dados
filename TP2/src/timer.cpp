#include "../include/timer.h"

#include <stdio.h>

float userTime(struct rusage *start, struct rusage *end) { //função para calcular o tempo de usuario decorrido em segundos
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
            1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}