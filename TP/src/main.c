#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/armazenaExp.h"
#include "../include/converteExp.h"
#include "../include/identificaExp.h"
#include "../include/resolveExp.h"

void lerEntrada(int argc, char **argv) {
    char *expAuxiliar[MAX_TAM_EXP]; /* variável auxiliar que vai armazenar cada linha do arquivo */
    char expressao[MAX_TAM_EXP]; /* variável que realmente vai conter a expressão a ser transformada ou resolvida */
    char nomeArquivo[20];
    char linha[1000];
    int countNumLinhas = 0;
    int i = 0;

    FILE *arquivo;
    pilha p[MAX_TAM_EXP];

    if(validaEntrada(argc, argv)) /* se a entrada for válida, copia o nome do arquivo passado pelo usuário para a variável nomeArquivo */
        strcpy(nomeArquivo, argv[1]);

    arquivo = fopen(nomeArquivo, "r");
    if(arquivo == NULL)
    {
        fprintf(stderr, "Não foi possível abrir o arquivo :(\n");
        fprintf(stderr, "Certifique-se de que o arquivo não está vazio e de ter digitado o nome do arquivo corretamente junto com seu caminho, caso ele não esteja no mesmo diretório da pasta do programa!\n");
        exit(1);    
    }
    
    /* Le o arquivo até o final */
    while(fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        expAuxiliar[i] = strdup(linha); /* duplica o char linha e armazena em expAuxiliar */
        countNumLinhas++;
        i++;
    }

    for(int j = 0; j < countNumLinhas; j++) /* percorrendo o número de linhas */
    {
        char *posicao = strstr(expAuxiliar[j], "LER"); /* verifica a ocorrência da string "LER" */
        if(posicao != NULL)
        {
            /* Armazeno a expressão na pilha, porém sem a primeira e a segunda posição
            pois a primeira posição é o comando LER e o segundo indica se é POSFIXA ou INFIXA */
            strcpy(expressao, posicao + strlen("LER POSFIXA")); /* copia a expressão encontrada no arquivo para a variável expressao */
            expressao[strcspn(expressao, "\n")] = '\0'; /* removendo o "\n" no final e adicionando '\0' */

            printf("Lendo expressão... \n");
            if(identificaExpInfixa(expressao))
            {
                printf(" Expressão infixa!\n");
                armazenaExp(p, expressao);

                printf("\n");
                posicao = strstr(expAuxiliar[j + 1], "POSFIXA");
                char *posfixa;
                posfixa = infixaParaPosfixa(expressao, p);
                printf(" Expressão no formato posfixa: %s \n", posfixa);
                limpaPilha(p);

                posicao = strstr(expAuxiliar[j + 2], "RESOLVE #");
                float resultadoPosFixa = resolvePosfixa(posfixa, p);
                printf(" RESOLVE # %f \n", resultadoPosFixa);
                printf("-------------------------------- ----------------------------------\n\n");
                free(posfixa);
            }
            
            else if(!identificaExpInfixa(expressao) && (identificaExpPosfixa(expressao)))
            {
                printf("Expressão posfixa!\n");
                char expPosFixaAux[MAX_TAM_EXP];
                strcpy(expPosFixaAux, expressao); /* uma string e uma pilha auxiliar é criada para resolver a expressão */
                pilha pilhaAux[MAX_TAM_EXP];
                armazenaExp(p, expressao);
                armazenaExp(pilhaAux, expPosFixaAux);

                printf("\n");
                posicao = strstr(expAuxiliar[j + 1], "INFIXA");
                char *infixa;
                infixa = posfixaParaInfixa(expressao, p);
                printf(" Expressão no formato infixa: %s \n", infixa);
                limpaPilha(p);

                posicao = strstr(expAuxiliar[j + 2], "RESOLVE #");
                float resultadoInfixa = resolvePosfixa(expPosFixaAux, pilhaAux);
                printf(" RESOLVE # %f \n", resultadoInfixa);
                printf("-------------------------------- ----------------------------------\n\n");
                free(infixa);
            }

            else
                printf("Expressão inválida!\n");
        }
    }
    for(int k = 0; k < countNumLinhas; k++) /* desalocando a memória alocada pelo strdup */
        free(expAuxiliar[k]);
    
    //printf("%s ", exp[0]);

    // for(int j = 0; j < countNumeroExpressoes; j++)
    // {
    //     printf("Expressão %d: %s", j+1, exp[j]);
    // }

    fclose(arquivo);
}

int main (int argc, char **argv) {
    lerEntrada(argc, argv);
    //Testando a expressão infixa
    // char exp[1000] = "2,3 + 5";
    // if(identificaExpInfixa(exp))
    //     printf("É infixa: %s\n", exp);
    // else 
    //     printf("Não é infixa: %s\n", exp);


    // // remove o caractere de nova linha do final da string
    // // exp2[strcspn(exp2, "\n")] = 0;

    // // Testando a expressão pos-fixa
    // char exp2[1000] = "5 3,2 2 + * 4,2 / 6,0 -";
    // if (identificaExpPosFixa(exp2)) {
    //     printf("A expressao eh pos-fixa.\n");
    //     pilha p[MAX_TAM_EXP];
    //     criaPilha(p);
    //     empilha(p, exp2);
    //     imprimePilha(p);
    // } else {
    //     printf("A expressao nao eh pos-fixa.\n");
    // }


    //Testando a pilha, junto com as expressões infixa e pos-fixa
    //char expressao[MAX_TAM_EXP] = "( ( ( ( ( 0.016298 ) * ( ( ( ( ( ( ( ( ( ( ( ( 5.451572 ) + ( ( 6.522725 ) + ( 4.053423 ) ) ) + ( 2.237167 ) ) * ( ( 6.761665 ) * ( ( 8.929393 ) + ( 3.288268 ) ) ) ) / ( 7.008292 ) ) + ( 8.866717 ) ) + ( ( ( ( 9.736813 ) + ( ( 2.670779 ) - ( 8.429765 ) ) ) + ( 9.916589 ) ) + ( 8.388820 ) ) ) / ( 5.781327 ) ) - ( ( 0.114987 ) / ( 9.796989 ) ) ) - ( ( 2.566517 ) * ( ( 7.189669 ) / ( 1.085716 ) ) ) ) + ( ( ( 3.230236 ) - ( ( ( 9.262806 ) + ( 4.472587 ) ) / ( 1.116756 ) ) ) - ( 4.147509 ) ) ) + ( 9.299896 ) ) ) - ( 6.391134 ) ) - ( ( ( ( ( 4.968851 ) / ( 5.251583 ) ) / ( 4.725458 ) ) * ( ( ( 2.956025 ) / ( 3.680148 ) ) * ( 2.821245 ) ) ) * ( ( 5.935397 ) + ( 2.565921 ) ) ) ) * ( ( 0.599650 ) * ( ( ( ( ( ( 7.011593 ) + ( 6.290626 ) ) - ( 3.518166 ) ) / ( 0.333738 ) ) + ( 8.825464 ) ) * ( 4.059770 ) ) ) )";
    // char expressao[MAX_TAM_EXP] =  "5.4352 4 * 2.5301 + 3.2 4 / -" ;
    // printf("Identificando expressão....\n");

    // if(identificaExpInfixa(expressao))
    // {
    //     printf("Expressão infixa!\n");
    //     pilha p[MAX_TAM_EXP];
    //     armazenaExp(p, expressao);

    //     char *posfixa;
    //     printf("Convertendo expressão para posfixa....\n");
    //     posfixa = infixaParaPosFixa(expressao, p);
    //     printf("Expressão no formato posfixa: %s\n", posfixa);
        
    //     limpaPilha(p); //limpa a pilha para armazenar a nova expressão no formato posfixa
    //     armazenaExp(p, posfixa); //armazeno a nova expressao no formato posfixa na pilha

    //     float resultadoPosFixa = resolvePosFixa(posfixa, p);
    //     printf("Resultado da posfixa: %f \n", resultadoPosFixa);

    //     free(posfixa);
    //     limpaPilha(p);
    // }
    
    // else if(!identificaExpInfixa(expressao) && (identificaExpPosFixa(expressao)))
    // {
    //     printf("Expressão posfixa!\n");
    //     pilha p2[MAX_TAM_EXP];
    //     armazenaExp(p2, expressao);
    //     printf("%s \n", expressao);

    //     char *infixa;
    //     printf("Convertendo expressão para infixa....\n");
    //     infixa = posfixaParaInfixa(expressao);
    //     printf("Expressão no formato infixa: %s\n", infixa);
    //     /* Liberar a memória armazenada pela infixa */
    //     //free(infixa);


    //     limpaPilha(p2);    
    // }

    // else
    //     printf("Expressão inválida! \n");
    
    // char infixa[MAX_TAM_EXP] = "(2 + 3) * 5 / 2";
    // pilha p[MAX_TAM_EXP];

    // char *posfixa;
    // posfixa = infixaParaPosFixa(infixa, p);
    
    // printf("Infixa: %s\n", infixa);
    // printf("Posfixa: %s\n", posfixa);
    // free(posfixa);

    return 0;

}