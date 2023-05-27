#include "arvore.h"
#include "memLog.h"

#include "getopt.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void help() {
    printf("Ajuda:\n");
    printf("Para testar o programa inserindo os elementos na árvore, insira-os na linha de comando ou no makefile.\n");
    printf("Flag i: passa os valores a serem inseridos na árvore\n");
    printf("Exemplo: -i 5 3 2 7 9\n");

    printf("Flag p: passa o nome do arquivo de log\n");
    printf("Exemplo: -p /tmp/multlog.out\n");

    printf("Flag l: ativa o registro de acesso á memória\n");
    printf("Exemplo: -l\n");

    printf("Exemplo de entrada com as flags juntas: -p tmp/arvorelog.out -l -i 2 9 10 5 7 8\n");
}

int main(int argc, char **argv) {
    printf("Programa para inserir em uma árvore binária\n");

    Tree tree;
    tree.raiz = NULL;

    int aux;
    int valorEscolhido = 0;
    int *valorASerInserido = malloc(sizeof(No) * 10);
    int j = 0;

    char lognome[100];
    int ativaRegAcesso = 0;

    //Ler vários números da linha de comando e inseri-los na árvore
    while((aux = getopt(argc, argv, "i:p:lh")) != EOF) 
    {
        switch(aux) 
        {
            case 'i':
                while(optarg != NULL) 
                {
                    valorEscolhido = atoi(optarg);
                    valorASerInserido[j] = valorEscolhido; //esse array vai ser utilizado para inserir na arvore depois que o getopt terminar
                    printf("Valor %d a ser inserido na árvore\n", valorASerInserido[j]);
                    j++;
                    optarg = argv[optind]; //optind representa o índice do próximo elemento no argv
                    argv++;
                }
                break;

            case 'p':
                strcpy(lognome, optarg);
                break;
            
            case 'l':
                ativaRegAcesso = 1;
                break;

            case 'h':
                help();
                exit(1);

            default:
                fprintf(stderr, "Opção inválida ou ausente: %c \n", optopt);
                break;
        }
        
    }

    iniciaMemLog(lognome);
    if(ativaRegAcesso)
        ativaMemLog();
    else
        desativaMemLog();
    
    defineFaseMemLog(0);
    for(int i = 0; i < j; i++)
        inserir(&tree, valorASerInserido[i], 0);
    
    defineFaseMemLog(1);
    int id = 1;
    if(ativaRegAcesso)
    {
        printf("Árvore binária atual:\n");
        imprimir(tree.raiz, &id);
    }
    
    printf("\n");
    free (valorASerInserido);
    return finalizaMemLog();
}