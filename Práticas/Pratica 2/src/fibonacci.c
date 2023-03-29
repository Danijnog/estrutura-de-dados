//---------------------------------------------------------------------
// Arquivo	: fibonacci.c
// Conteudo	: implementacao das funções definidas em fibonacci.h
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 29/03/2023 - arquivo criado
//---------------------------------------------------

#include "../include/fibonacci.h"
#include "../include/tempo.h"

int fibonacciRecursivo(int n) {
    if(n == 1 || n == 2)
        return 1;
    else 
        return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
    consomeTempo(); //função implementada para levar mais tempo a execução do programa
}

int fibonacciIterativo(int n) {
    int atual = 0; //termo atual da sequencia
    int ant1 = 1; //termo de ordem n-1 da sequencia
    int ant2 = 0; //termo de ordem n-2 da sequencia

    while(n >= 2)
    {
        atual = ant1 + ant2;
        ant2 = ant1;
        ant1 = atual;
        n--;
    }
    return ant1;
}