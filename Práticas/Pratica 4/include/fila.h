/* Implementação de uma fila circular por arranjo
 First in, first out                 */

#ifndef FILA_H
#define FILA_H

#define MAX_FILA 11

struct fila {
    int *itens; //vai ser um ponteiro pois vai armazenar diversos valores em diferentes posições no array e aloquei dinâmicamente na main
    int inicio, fim;
    int tamanho;
};

void criaFila(struct fila *p);
int enfileira(struct fila *p, int item);
int desenfileira(struct fila *p);
int filaCheia(struct fila *p);
int filaVazia(struct fila *p);
void destroiFila(struct fila *p);
void imprimeFila(struct fila *p);

#endif