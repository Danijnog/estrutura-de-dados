#ifndef CAMINHA_H
#define CAMINHA_H

#include "geraarvbin.h"

long caminhamentoPreOrdem(TipoApontador *T);
long caminhamentoInOrdem(TipoApontador *T);
long caminhamentoPosOrdem(TipoApontador *T);
int ancestral(int i, int j, TipoApontador *T, prm_t prm);

#endif