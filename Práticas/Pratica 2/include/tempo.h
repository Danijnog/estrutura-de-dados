//---------------------------------------------------------------------
// Arquivo	: tempo.h
// Conteudo	: implementacao do .h do arquivo tempo
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 29/03/2023 - arquivo criado
//---------------------------------------------------

#ifndef TEMPO_H
#define TEMPO_H

#include "time.h"
#include "sys/resource.h"

float difTempoUsuario(struct rusage *start, struct rusage *end); //função para calcular o tempo de usuario decorrido em segundos
float difTempoSistema(struct rusage *start, struct rusage *end); //função para calcular o tempo do sistema decorrido em segundos
void consomeTempo(); //função para atrasar algum processo caso necessário

#endif