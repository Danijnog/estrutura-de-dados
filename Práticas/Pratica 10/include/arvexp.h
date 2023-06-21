#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>

#ifndef CARGA
#define CARGA 10
#endif

#ifndef m               
#define m               50
#endif
#define mm              (m * 2)
#define FALSE           0
#define TRUE            1

#define MAXCH 100

typedef long TipoChave;

typedef struct Registro {
  TipoChave Chave;
  char Carga[CARGA];
} Registro;

typedef struct Pagina *Apontador;

typedef struct Pagina {
  short n;
  Registro r[mm];
  Apontador p[mm + 1];
} Pagina;

typedef struct stat{
  int X;
  int curr;
  Pagina p[3];
}stat_t;

typedef struct exp{
  int numops;
  float op[3];
  int maxch; 
  int seed;
  int print;
} exp_t;

void Inicializa(Apontador *Dicionario);

void Pesquisa(Registro *x, Apontador Ap);

void InsereNaPagina(Apontador Ap, Registro Reg, Apontador ApDir);

void Ins(Registro Reg, Apontador Ap, short *Cresceu, 
	 Registro *RegRetorno,  Apontador *ApRetorno);

void Insere(Registro Reg, Apontador *Ap);

void Reconstitui(Apontador ApPag, Apontador ApPai, int PosPai, short *Diminuiu);

void Antecessor(Apontador Ap, int Ind, Apontador ApPai, short *Diminuiu);

void Ret(TipoChave Ch, Apontador *Ap, short *Diminuiu);

void Retira(TipoChave Ch, Apontador *Ap);

void ImprimeI(Apontador p, int nivel, FILE * out, stat_t * st, char * pref);

void Imprime(Apontador p,FILE * out, stat_t * st, char * pref); 

void TestaI(Apontador p, int pai, short direita);

void Testa(Apontador p);