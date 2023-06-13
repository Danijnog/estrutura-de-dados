#include "../include/identificaExp.h"
#include "../include/converteExp.h"
#include "../include/msgAssert.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int identificaExpInfixa(char *exp) {
    int tamanhoExp = strlen(exp);
    int countOperando = 0; //esse contador vai auxiliar para verificar a validade da expressão
    int countOperador = 0; //esse outro contador também auxilia para verificar a validade da expressão
    int countOperadorRepetido = 0;
    int decimal = 0;
    int countAbreParenteses = 0;
    int countFechaParenteses = 0;

    for(int i = 0; i < tamanhoExp; i++)
    {
        char c = exp[i];
        if(exp[tamanhoExp - 1] == '+' || exp[tamanhoExp - 1] == '-' || exp[tamanhoExp - 1] == '*' || exp[tamanhoExp - 1] == '/') //se o ultimo caracter da expressão for um operador significa que não é infixa
            return 0;
           
        if(c == ' ') 
        {
            decimal = 0;
            continue; //ignora os espaçoes em branco e os parênteses
        }
        
        if((ehOperando(&c)) || c == '.')
        {
            if(c == '.')
            {
                countOperando--;
                if(decimal)
                    erroAssert(0, "Virgula colocada incorretamente!\n");

                decimal++;
            }
            if(ehOperando(&c))
                countOperando++;
            countOperadorRepetido = 0;
        }

        else if((c == '+' || c == '-' || c == '*' || c == '/')) //verificando também se o ultimo digito da expressão é um numero, porque se não for então significa que a expressão não é infixa e pode ser posfixa
        {
            decimal = 0;
            countOperador++;
            if(countOperadorRepetido)
            {
                erroAssert(0, "Operador repetido!\n");
            }
            countOperadorRepetido++;
        }

        else if(c == '(')
            countAbreParenteses++;

        else if(c == ')')
            countFechaParenteses++;

        else
        {
            fprintf(stderr, "O seguinte caracter é inválido: %c\n", c);
            erroAssert(0, "Caracter inválido!\n");
            return 0;
        }
    }

    erroAssert(countOperador > 0, "Quantidade de operadores inválido!\n");
    erroAssert(countOperando > 1, "Quantidade de operandos inválido!\n");
    erroAssert(countAbreParenteses == countFechaParenteses, "Parenteses colocados incorretamente!\n"); /* a quantidade de parenteses que abre tem que ser igual a quantidade de parenteses que fecha*/

    return(countOperando -1 >= countOperador);
}

int identificaExpPosfixa(char *exp) {
    int count = -1; // o count vai servir para fazer a lógica de se é uma expressão pos-fixa ou nao
    int countOperando = 0;
    int countOperador = 0;
    int tamanhoExp = strlen(exp);
    int decimal = 0;

    if(tamanhoExp == 1) //se for passado somente um número ou um operador na expressão
    {
        printf("Expressão inválida! Apenas 1 caracter passado como parâmetro!\n");
        return 0;
    }

    for(int i = 0; i < tamanhoExp; i++)
    {
        char c = exp[i];
        if(c == ' ')
            continue;

        if(ehOperando(&c) || c == '.')
        {
            if(c == '.')
            {
                if(decimal)
                    erroAssert(0, "Virgula colocada incorretamente!\n");
                decimal = 0;
            }
            if(ehOperando(&c))
                countOperando++;
            count++; //cada vez que encontra um número incrementa o count
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            countOperador++;
            count--; //cada vez que encontra uma operação decrementa o count
        }
        
        else //se não for um caracter ou um digito
        {
            fprintf(stderr, "O seguinte caracter é inválido: %c\n", c);
            erroAssert(0, "Caracter inválido!\n");
            return 0;
        }
    }
    erroAssert(countOperando > 1, "Quantidade de operandos inválida!\n");
    erroAssert(countOperador > 0, "Quantidade de operadores inválida!\n");
    return (count >= 0); //se o count for igual a 0, a expressão é pos fixa e retorna verdadeira
}


