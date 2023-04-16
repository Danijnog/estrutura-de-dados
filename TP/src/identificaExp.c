#include "../include/identificaExp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int identificaExpInfixa(char *exp) {
    int tamanhoExp = strlen(exp);
    int ehOperando = 0, ehOperador = 0;
    int virgula = 0;
    int verificaRepeticao = 1; //variável para verificar se mais de um número é digitado sem um operador entre eles

    if(exp[0] == '+' || exp[0] == '-' || exp[0] == '/' || exp[0] == '*' || exp[0] == ',')
    {
        printf("Expressão inválida! \n");
        exit(1);
    }

    else if(tamanhoExp == 1)
    {
        printf("Expressão inválida! Apenas 1 caracter passado como parâmetro! \n");
        exit(1);
    }

    for(int i = 0; i < tamanhoExp; i++)
    {
        if(exp[i] == ' ') //espaço em branco
            continue; //ignora os espaços em branco

        else if(exp[i] >= '0' && exp[i] <= '9') //se for um número
        {
            if(verificaRepeticao == 2)
            {
                printf("Caracteres repetidos! \n");
                exit(1);
                return 0;
            }
            else 
                verificaRepeticao++;
            
            ehOperando = 1;
            ehOperador = 0;  
        }

        else if(exp[i] == ',') //se for uma virgula
        {
            if(virgula) //se ja tiver uma virgula no numero
            {
                printf("Virgula colocada incorretamente! \n");
                exit(1);
            }
            virgula = 1;
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') //se for um desses operadores
        {
            if(ehOperador && !ehOperando) //se for um operador e não for um operando
            {
                printf("Expressão não é infixa!");
                return 0; //não é infixa
            }
            ehOperando = 0;
            verificaRepeticao--; //reinicia a verificação de repetição de caracteres
            ehOperador = 1;
            virgula = 0; //reinicia a verificação da virgula para o próximo número
        }
       
        else
        {
            printf("Caracteres inválidos!\n");
            exit(1);
        }
    }
    return (ehOperando && !ehOperador);
}

int identificaExpPosFixa(char *exp) {
    int tamanhoExp = strlen(exp);
    char *token;
    int count = -1; // o count vai servir para fazer a lógica de se é uma expressão pos-fixa ou nao

    token = strtok(exp, " "); //recebe a expressão e o delimitador

    if(tamanhoExp == 1) //se for passado somente um número ou um operador na expressãp
    {
        printf("Expressão inválida! Apenas 1 caracter passado como parâmetro!\n");
        exit(1);
    }

    for(int i = 0; i < tamanhoExp; i++)
    {
        while(token != NULL)
        {
            if(token[i] >= '0' && token[i] <= '9')
            {
                count++; //cada vez que encontra um número incrementa o count
            }

            else if(token[i] == '+' || token[i] == '-' || token[i] == '*' || token[i] == '/')
            {
                count--; //cada vez que encontra uma operação decrementa o count
            }

            else //se não for um caracter ou um digito
                return 0;

        printf("Token: %s \n ", token);
        token = strtok(NULL, " ");
        }
    }

    return (count == 0); //se o count for igual a 0, a expressão é pos fixa e retorna verdadeira
}
