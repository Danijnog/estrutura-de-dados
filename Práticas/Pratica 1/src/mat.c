//---------------------------------------------------------------------
// Arquivo	: mat.c
// Conteudo	: implementação das funções definida 
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 2023-03-21 - arquivo criado
//---------------------------------------------------

#include "../include/mat.h"
#include "../include/msgassert.h"

void criaMatriz(mat_tipo * mat, int tx, int ty, int id) {
  // verifica se os valores de tx e ty são validos
  erroAssert(tx>0,"Dimensao nula");
  erroAssert(ty>0,"Dimensao nula");
  erroAssert(tx<=MAXTAM,"Dimensao maior que permitido");
  erroAssert(ty<=MAXTAM,"Dimensao maior que permitido");

  // inicializa as dimensoes da matriz
  mat->tamx = tx;
  mat->tamy = ty;
  // inicializa o identificador da matriz, para rastreamento
  mat->id = id;
}

void inicializaMatrizNula(mat_tipo * mat) {

    int i, j;
    // inicializa todos os elementos da matriz com 0, por seguranca 
    for (i=0; i<MAXTAM; i++){
        for(j=0; j<MAXTAM; j++){
        mat->m[i][j] = 0;
        }
    }
}

void inicializaMatrizAleatoria(mat_tipo * mat) {

    int i, j;
    // inicializa a matriz com valores nulos, por seguranca
    inicializaMatrizNula(mat);
    // inicializa a parte alocada da matriz com valores aleatorios
    for (i=0; i<mat->tamx; i++){
        for(j=0; j<mat->tamy; j++){
            mat->m[i][j] = drand48()*INITRANDOMRANGE;
        }
    }
}

double acessaMatriz(mat_tipo * mat) {

    int i, j;
    double aux, s=0.0;
    for (i=0; i<mat->tamx; i++){
        for(j=0; j<mat->tamy; j++){
            aux = mat->m[i][j];
            s+=aux;
        }
    }
  return s; // apenas para evitar que acesso seja eliminado
}

void imprimeMatriz(mat_tipo * mat) {
    
    int i,j;

    // seguranca, mas erro não deve acontecer jamais
    erroAssert(mat->tamx<=MAXTAM,"Dimensao maior que permitido");
    erroAssert(mat->tamy<=MAXTAM,"Dimensao maior que permitido");

    // imprime os identificadores de coluna
    printf("%9s"," ");
    for(j=0; j<mat->tamy; j++)
        printf("%8d ",j);
    printf("\n");

    // imprime as linhas
    for (i=0; i<mat->tamx; i++){
        printf("%8d ",i);
        for(j=0; j<mat->tamy; j++){
            printf("%8.2f ",mat->m[i][j]);
        }
        printf("\n");
    }
}

void salvaMatriz(mat_tipo * mat, FILE * out) {
      
    int i,j;
    // seguranca, mas erro não deve acontecer jamais
    erroAssert(mat->tamx<=MAXTAM,"Dimensao maior que permitido");
    erroAssert(mat->tamy<=MAXTAM,"Dimensao maior que permitido");

    fprintf(out,"%d %d\n",mat->tamx,mat->tamy);
    // imprime as linhas
    for (i=0; i<mat->tamx; i++){
        for(j=0; j<mat->tamy; j++){
            fprintf(out, "%.6f ",mat->m[i][j]);
        }
        fprintf(out,"\n");
    }
}

void escreveElemento(mat_tipo * mat, int x, int y, double v) {

    // verifica se x e y sao validos
    erroAssert((x<0)||(x>=mat->tamx),"Indice invalido");
    erroAssert((y<0)||(y>=mat->tamy),"Indice invalido");

    mat->m[x][y] = v;
}

double leElemento (mat_tipo * mat, int x, int y) {

    // verifica se x e y sao validos
    erroAssert((x<0)||(x>=mat->tamx),"Indice invalido");
    erroAssert((y<0)||(y>=mat->tamy),"Indice invalido");

    return mat->m[x][y];
}

void copiaMatriz(mat_tipo *src, mat_tipo * dst, int dst_id) {
    
    int i,j;

    // cria novamente a matriz dst para ajustar as suas dimensoes
    criaMatriz(dst,src->tamx, src->tamy,dst_id);
    // inicializa a matriz dst como nula
    inicializaMatrizNula(dst);
    // copia os elementos da matriz src
    for (i=0; i<src->tamx; i++){
        for(j=0; j<src->tamy; j++){
            dst->m[i][j] = src->m[i][j];
        }
    }
}

void somaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c) {
    
    int i,j;
    // verifica se as dimensoes das matrizes a e b sao as mesmas
    erroAssert(a->tamx==b->tamx,"Dimensoes incompativeis");
    erroAssert(a->tamy==b->tamy,"Dimensoes incompativeis");

    // inicializa a matriz c garantindo a compatibilidade das dimensoes
    criaMatriz(c,a->tamx, a->tamy, c->id);
    inicializaMatrizNula(c);

    // faz a soma elemento a elemento
    for (i=0; i<a->tamx; i++){
        for(j=0; j<a->tamy; j++){
            c->m[i][j] = a->m[i][j]+b->m[i][j];
        }
    }
}

void multiplicaMatrizes(mat_tipo *a, mat_tipo *b, mat_tipo *c) {
    
    int i,j,k;
    // verifica a compatibilidade das dimensoes 
    erroAssert(a->tamy==b->tamx,"Dimensoes incompativeis");

    // cria e inicializa a matriz c
    criaMatriz(c,a->tamx, b->tamy,c->id);
    inicializaMatrizNula(c);

    // realiza a multiplicacao de matrizes
    for (i=0; i<c->tamx;i++){
        for (j=0; j<c->tamy;j++){
            for (k=0; k<a->tamy;k++){
                c->m[i][j] += a->m[i][k]*b->m[k][j];
            }
        }
    }
}

void transpoeMatriz(mat_tipo *a) {
    
    int i,j,dim;
  
    // determina a maior dimensao entre tamx e tamy
    dim = (a->tamx>a->tamy?a->tamx:a->tamy);

    // faz a transposicao como se a matriz fosse quadrada
    for (i=0; i<dim; i++){
        for(j=i+1; j<dim; j++){
            ELEMSWAP((a->m[i][j]),(a->m[j][i]));
        }
    }
    // inverte as dimensoes da matriz transposta
    ELEMSWAP(a->tamx,a->tamy);
}

void destroiMatriz(mat_tipo *a) {
    // apenas um aviso se a matriz for destruida mais de uma vez
    avisoAssert(((a->tamx>0)&&(a->tamy>0)),"Matriz já foi destruida");

    // torna as dimensoes invalidas
    a->id = a->tamx = a->tamy = -1;
}

void uso() {
    fprintf(stderr,"matop\n");
    fprintf(stderr,"\t-s \t(somar matrizes) \n");
    fprintf(stderr,"\t-m \t(multiplicar matrizes) \n");
    fprintf(stderr,"\t-t \t(transpor matriz)\n");
    fprintf(stderr,"\t-c <arq> \t(cria matriz e salva em arq)\n");
    fprintf(stderr,"\t-x <int>\t(primeira dimensao)\n");
    fprintf(stderr,"\t-y <int>\t(segunda dimensao)\n");
}

