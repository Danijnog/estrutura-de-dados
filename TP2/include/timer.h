#ifndef TEMPO_H
#define TEMPO_H

#include "time.h"
#include "sys/resource.h"

float userTime(struct rusage *start, struct rusage *end); //função para calcular o tempo de usuario decorrido em segundos

#endif