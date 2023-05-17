#include "arvore.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
    printf("Programa para inserir em uma árvore binária\n");

    Tree tree;
    tree.raiz = NULL;

    int option;

    while(option != 0)
    {
        printf("\nDigite 0 para sair do programa\n");
        printf("Digite 1 para inserir um valor na árvore\n");
        printf("Digite 2 para imprimir a árvore\n");
        scanf("%d", &option);
        switch(option)
        {
            case 0:
                printf("Saindo...\n");
                break;
            
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                int value;
                scanf("%d", &value);
                inserir(&tree, value);
                break;

            case 2:
                printf("\nImprimindo a árvore...\n");
                imprimir(tree.raiz);
                break;
            
            default:
                printf("\nOpção inválida!\n");
                break;
        }
    }
    return 0;
}