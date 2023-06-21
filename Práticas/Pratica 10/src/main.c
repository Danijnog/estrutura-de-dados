#include "../include/arvexp.h"
#include "../include/timer.h"

#define PESQUISA 0
#define INSERE 1
#define RETIRA 2

int main(int argc, char *argv[]) { 
  Registro x;
  Pagina *D;
  stat_t st;
  exp_t exp;

  struct rusage start, end;
  int i, op;

  exp.print = 0;
  exp.seed = 1;
  exp.numops = 10000;
  exp.maxch = 100;
  exp.op[PESQUISA] = 0.4;
  exp.op[INSERE] = 0.7;
  exp.op[RETIRA] = 1.0;

  srand48((unsigned int)exp.seed);

  Inicializa(&D);

  for (i=0; i<exp.numops; i++){
    // define op
    double opaux = drand48();
    for (op=0; op<3; op++){
      if (opaux<exp.op[op]){ break; }
    }
    
    // define chave
    x.Chave = (long)(exp.maxch*drand48());

    if (exp.print){
      printf("i %d opaux %f op %d x %ld\n",i,opaux,op,x.Chave);
    }

    switch (op){
      case PESQUISA:
           getrusage(RUSAGE_SELF, &start); // inicio da análise do tempo do processo de pesquisa
           Pesquisa(&x,D); 
           getrusage(RUSAGE_SELF, &end); // fim da análise do tempo do processo de pesquisa

           printf("Tempo de pesquisa: %.07f\n", difTempoUsuario(&start, &end));
           break;

      case INSERE:
           getrusage(RUSAGE_SELF, &start); // inicio da análise do tempo do processo de insere
           Insere(x,&D); 
           getrusage(RUSAGE_SELF, &end); // fim da análise do tempo do processo de insere

           printf("Tempo de inserção: %.07f\n", difTempoUsuario(&start, &end));
           break;

      case RETIRA:
           getrusage(RUSAGE_SELF, &start); // inicio da análise do tempo de retirada
           Retira(x.Chave, &D);
           getrusage(RUSAGE_SELF, &end); // fim da análise do tempo do processo de retirada

           printf("Tempo de retirada: %.07f\n", difTempoUsuario(&start, &end));
           break;
    }
    if (exp.print) Imprime(D,stdout,&st,"");
  }
  return 0;
}
