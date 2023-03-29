//---------------------------------------------------------------------
// Arquivo	: tempo.c
// Conteudo	: implementacao das funções definidas em tempo.h
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 29/03/2023 - arquivo criado
//---------------------------------------------------

#include "../include/tempo.h"
#include<stdio.h>

float difTempoUsuario(struct rusage *start, struct rusage *end) { //função para calcular o tempo de usuario decorrido em segundos
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
            1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
} 

float difTempoSistema(struct rusage *start, struct rusage *end) { //função para calcular o tempo do sistema decorrido em segundos
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
            1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}

void consomeTempo(void) { //função para atrasar algum processo caso necessário
    printf("\n Dentro da função de consumir tempo\n");
    int i = 0;

    for(;i<0xfffffee;i++);

    return;
}
