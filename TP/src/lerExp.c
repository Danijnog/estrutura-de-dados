#include "../include/lerExp.h"
#include "../include/identificaExp.h"
#include <string.h>

void lerExpressao() {
    char *exp[MAX_TAM_EXP];
    FILE *arquivo;

    
    arquivo = fopen("expressao.txt", "r"); //vai ler de um arquivo e armazenar na expressão "exp"
    char line[1000];
    int i = 0;
    int contNumeroExpressoes = 0;

    if(arquivo == NULL)
    {
        printf("Arquivo vazio, não foi possível ler!\n");
        exit(1);    
    }

    while(fgets(line, sizeof(line), arquivo) != NULL) //lendo cada linha do arquivo
    {
        if(identificaExpInfixa(line) || identificaExpPosFixa(line))
        {
            exp[i] = strdup(line); //strdup é utilizada para duplicar uma string, para cada linha do arquivo ele vai duplicar a string e armazenar em exp[i]
            i++;
            contNumeroExpressoes++;
        }
        else 
            printf("Expressão inválida! \n");
       
    }

    for(int j = 0; j < contNumeroExpressoes; j++)
    {
        printf("%s ", exp[j]);
    }
    fclose(arquivo);
}

int main() {
    lerExpressao();
}
