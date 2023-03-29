//---------------------------------------------------------------------
// Arquivo	: fatorial.c
// Conteudo	: implementacao das funções definidas em fatorial.h
// Autor	: Daniel Nogueira Junqueira (danijnog@ufmg.br)
// Historico	: 29/03/2023 - arquivo criado
//---------------------------------------------------

#include "../include/fatorial.h"
#include "../include/tempo.h"
#include "stdio.h"

int fatorialRecursivo(int n) {
    consomeTempo(); //função implementada para levar mais tempo a execução do programa
    if(n == 0)
        return 1;
    else
        return n * (fatorialRecursivo(n-1));
}

int fatorialIterativo(int n) {
    int resultado = 1;
    while(n > 0)
    {
        resultado = resultado * n;
        n--;
    }
    return resultado;
}
