#ifndef TEMPO_H
#define TEMPO_H

#include "sys/resource.h"

float difTempoUsuario(struct rusage *start, struct rusage *end); //função para calcular o tempo de usuario decorrido em segundos
float difTempoSistema(struct rusage *start, struct rusage *end); //função para calcular o tempo do sistema decorrido em segundos

#endif