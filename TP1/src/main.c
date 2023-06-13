#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/armazenaExp.h"
#include "../include/converteExp.h"
#include "../include/identificaExp.h"
#include "../include/resolveExp.h"
#include "../include/msgAssert.h"

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

    printf("------------- Bem vindo(a) ao programa resolvedor de expressões numéricas! -------------  \n\n");
    for(int j = 0; j < countNumLinhas; j++) /* percorrendo o número de linhas */
    {
        char *posicao = strstr(expAuxiliar[j], "LER"); /* verifica a ocorrência da string "LER" */
        if(posicao != NULL)
        {
            /* Armazeno a expressão na pilha, porém sem a primeira e a segunda posição
            pois a primeira posição é o comando LER e o segundo indica se é POSFIXA ou INFIXA */
            strcpy(expressao, posicao + strlen("LER POSFIXA")); /* copia a expressão encontrada no arquivo para a variável expressao */
            expressao[strcspn(expressao, "\n")] = '\0'; /* removendo o "\n" no final e adicionando '\0' */

            if(expressao[strlen(expressao + 1)] == ' ') /* caso tenha algum espaço em branco no final de uma expressão */
            {
                fprintf(stderr, "Linha: %d\n", j + 1);
                erroAssert(0, "Por favor, remova o espaço em branco que está no final da linha citada acima!\n");
            }

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
    
    fclose(arquivo);
}

int main (int argc, char **argv) {
    lerEntrada(argc, argv);

    return 0;
}