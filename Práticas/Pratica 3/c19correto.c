#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sum_to_n(int num)
{
    int i, sum=0;
    for(i=1; i <= num; i++)
        sum += i;
    return sum;
}

void printSum()
{
    char *buf = malloc(sizeof(char) * 10);
    
    char line[10];
    printf("enter a number:\n");
    fgets(line, 10, stdin); //isso serve para ler uma string, que recebe 3 parametros: a string a ser lida, o limite maximo de caracteres a ser lido e de onde será lido

    if(line != NULL) 
        strtok(line, "\n"); //divide a string fornecida em tokens por meio de um delimitador

    sprintf(buf, "sum = %d", sum_to_n(atoi(line))); //serve para formatar e armazenar em uma string valores. Primeiro parametro: ponteiro de caracteres onde a string formatada sera armazenada. Segundo parametro: valores que serão armazenados na string
    printf("%s\n", buf);
    free(buf);

}

int main(void)
{
    printSum();
    return 0;
}
