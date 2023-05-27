#include "../include/memLog.h"
#include "../include/msgAssert.h"

memlog_tipo ml;

void clkDifMemLog(struct timespec t1, struct timespec t2, struct timespec * res) {
// Descricao: calcula a diferenca entre t2 e t1, que e armazenada em res
// Entrada: t1, t2
// Saida: res
  if (t2.tv_nsec < t1.tv_nsec) {
	// ajuste necessario, utilizando um segundo de tv_sec
	res-> tv_nsec = 1000000000+t2.tv_nsec-t1.tv_nsec;
	res-> tv_sec = t2.tv_sec-t1.tv_sec-1;
  } else {
	// nao e necessario ajuste
	res-> tv_nsec = t2.tv_nsec-t1.tv_nsec;
	res-> tv_sec = t2.tv_sec-t1.tv_sec;
  }
}

int iniciaMemLog(char * nome)
// Descricao: inicializa o registro de acessos, abrindo o arquivo nome
// Entrada: nome
// Saida: nao tem

{ // escolhe modo do relogio
  ml.clk_id = CLOCK_MONOTONIC;
  // abre arquivo de registro e verifica se foi aberto corretamente
  ml.log = fopen(nome,"wt");
  erroAssert(ml.log != NULL,"Cannot open memlog output");
  // captura o tempo inicial do registro
  struct timespec tp;
  int result = clock_gettime(ml.clk_id,&tp);
  ml.inittime.tv_sec = tp.tv_sec;  ml.inittime.tv_nsec = tp.tv_nsec;
  // inicializa variaveis do TAD
  ml.count = 1;   ml.ativo = MLATIVO;  ml.fase = 0;
  // imprime registro inicial
  int retprint = fprintf(ml.log,"I %ld %ld.%.9ld\n",
                     	ml.count,tp.tv_sec,tp.tv_nsec);
  erroAssert(retprint>=0,"Nao foi possivel escrever registro");
  return result;
}

int ativaMemLog() {
// Descricao: ativa o registro de acessos
// Entrada: nao tem
// Saida: MLATIVO
  ml.ativo = MLATIVO;
  return MLATIVO;
}

int desativaMemLog() {
// Descricao: desativa o registro de acessos
// Entrada: nao tem
// Saida: MLINATIVO
  ml.ativo = MLINATIVO;
  return MLINATIVO;
}

int defineFaseMemLog(int f) {
// Descricao: define a fase de registro de acessos
// Entrada: f
// Saida: valor de f
  ml.fase = f;
  return f;
}

int leMemLog(long int pos, long int tam, int id) {
// Descricao: registra acesso de leitura de tam bytes na posicao pos
// Entrada: pos,tam
// Saida: resultado da obtencao do relogio
// verifica se registro esta ativo
  if (ml.ativo == MLINATIVO) return 0;
  // captura tempo atual
  struct timespec tp, tdif;
  int result = clock_gettime(ml.clk_id,&tp);
  // calcula a diferenca com tempo inicial, para economia de armazenamento
  clkDifMemLog(ml.inittime,tp,&tdif);
  // atualiza contador
  ml.count++;
  // imprime registro
  int retprint = fprintf(ml.log,"L %d %ld %d %ld.%.9ld %ld %ld\n",
      	ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);

  erroAssert(retprint>=0,"Nao foi possivel escrever registro");
  return result;
}

int escreveMemLog(long int pos, long int tam, int id) {
// Descricao: registra acesso de escrita de tam bytes na posicao pos
// Entrada: pos, tam
// Saida: resultado da obtencao do relogio
// verifica se registro esta ativo
  if (ml.ativo == MLINATIVO) return 0;
  // captura tempo atual
  struct timespec tp,tdif;
  int result = clock_gettime(ml.clk_id,&tp);
  // calcula a diferenca com tempo inicial, para economia de armazenamento
  clkDifMemLog(ml.inittime,tp,&tdif);
  // atualiza contador
  ml.count++;
  // imprime registro
  int retprint = fprintf(ml.log,"E %d %ld %d %ld.%.9ld %ld %ld\n",
      	ml.fase, ml.count, id, tdif.tv_sec, tdif.tv_nsec, pos, tam);

  erroAssert(retprint>=0,"Nao foi possivel escrever registro");
  return result;
}

int finalizaMemLog() {
// Descricao: finaliza o registro de acessos a memoria
// Entrada: nao tem
// Saida: resultado da obtencao do relogio
// captura o tempo atual
  struct timespec tp, tdif;
  int result = clock_gettime(ml.clk_id,&tp);
  // calcula a diferenca com tempo inicial, para economia de armazenamento
  clkDifMemLog(ml.inittime,tp,&tdif);
  // atualiza contador
  ml.count++;
  // imprime registros finais
  int retprint = fprintf(ml.log,"F %ld %ld.%.9ld %ld.%.9ld\n", ml.count, 
                 tp.tv_sec,tp.tv_nsec, tdif.tv_sec,tdif.tv_nsec);

  erroAssert(retprint>=0,"Nao foi possivel escrever registro");
  // fecha arquivo de registro
  int retclose = fclose(ml.log);

  erroAssert(retclose == 0,"Nao foi possivel fechar o arquivo de registro");
  // atualiza variavel de estado
  ml.ativo = MLINATIVO;
  return result;
}






