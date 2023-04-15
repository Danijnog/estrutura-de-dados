#include "../include/fila.h"
#include "../include/pilha.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {

    struct fila *p = malloc(sizeof(struct fila)); //aloquei memoria dinamicamente para a fila
    p->itens = malloc(sizeof(int) * MAX_FILA); //vamos alocar memoria dinamicamente para o vetor de itens, que é um inteiro * o tamanho maximo da fila

    int *itemDigitadoPeloUsuario = malloc(sizeof(int) * MAX_FILA); //também aloquei memória para o digito que o usuário vai digitar pra empilhar
    printf("Digite os 10 digitos inteiros a serem empilhados: \n");
    
    for(int i = 0; i < MAX_FILA - 1; i++)
    {
        if(scanf("%d", &itemDigitadoPeloUsuario[i]) != 1) //se o usuário digitar algo que não seja um inteiro, o programa vai entrar nesse if e encerrar
        {
            printf("Por favor, digite apenas números inteiros! \n");
            exit(1);
        }
    }
    
    for(int i = 0; i < MAX_FILA; i++)
    {
        p->itens[i] = itemDigitadoPeloUsuario[i]; //atribui o valor digitado pelo usuário para o vetor de itens da fila
    }

    criaPilha(p);
    for(int i = 0; i < MAX_FILA - 1; i++)
    {
        itemEmpilhado(p, p->itens[i]); //seta os itens a serem empilhados na fila circular
    }

    printf("Pilha: \n");
    empilha(p); //empilha os itens por meio da fila circular
    printf("\n");

    printf("Desempilhando...\n");
    for(int i = 0; i < MAX_FILA - 1; i++)
    {
        desempilha(p);
    }

    free(p->itens);
    free(p);
    free(itemDigitadoPeloUsuario);
    return 0;
}