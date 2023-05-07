#include "../include/identificaExp.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int identificaExpInfixa(char *exp) {
    int tamanhoExp = strlen(exp);
    int countOperando = 0; //esse contador vai auxiliar para verificar a validade da expressão
    int countOperador = 0; //esse outro contador também auxilia para verificar a validade da expressão
    int virgula = 0;

    for(int i = 0; i < tamanhoExp; i++)
    {
        if(exp[i] == ' ' || exp[i] == '(' || exp[i] == ')') 
            continue; //ignora os espaçoes em branco e os parênteses
        
        else if(exp[i] >= '0' && exp[i] <= '9')
        {
            countOperando++;
            virgula = 0;
        }
        
        else if(exp[i] == '.')
        {
            countOperando--;
            if(virgula)
            {
                printf("Virgula colocada incorretamente!\n");
                return 0;
            }
            virgula++;
        }

        else if(exp[tamanhoExp - 1] == '+' || exp[tamanhoExp - 1] == '-' || exp[tamanhoExp - 1] == '*' || exp[tamanhoExp - 1] == '/') //se o ultimo caracter da expressão for um operador significa que não é infixa
            return 0;

        else if((exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')) //verificando também se o ultimo digito da expressão é um numero, porque se não for então significa que a expressão não é infixa e pode ser posfixa
        {
            countOperador++;
        }
           
        else
        {
            return 0;
        }
    }
    return(countOperando -1 >= countOperador);
}

int identificaExpPosfixa(char *exp) {
    int count = -1; // o count vai servir para fazer a lógica de se é uma expressão pos-fixa ou nao
    int tamanhoExp = strlen(exp);
    int virgula = 0;

    if(tamanhoExp == 1) //se for passado somente um número ou um operador na expressão
    {
        printf("Expressão inválida! Apenas 1 caracter passado como parâmetro!\n");
        return 0;
    }

    for(int i = 0; i < tamanhoExp; i++)
    {
        if(exp[i] == ' ')
            continue;

        else if(exp[i] == '.')
        {
           if(virgula)
           {
                printf("Virgula colocada incorretamente!\n");
                return 0;
           }
           virgula++;
        }

        else if(exp[i] >= '0' && exp[i] <= '9')
        {
            virgula = 0;
            count++; //cada vez que encontra um número incrementa o count
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            count--; //cada vez que encontra uma operação decrementa o count
        }
        
        else //se não for um caracter ou um digito
            return 0;

    }
    return (count >= 0); //se o count for igual a 0, a expressão é pos fixa e retorna verdadeira
}


