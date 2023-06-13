#ifndef TEMPO_H
#define TEMPO_H

#include "time.h"
#include "sys/resource.h"

// Função que retorna o tempo de usuário decorrido em segundos
float userTime(struct rusage *start, struct rusage *end);

#endif