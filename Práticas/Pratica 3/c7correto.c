#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    char* alphabet = calloc(27, sizeof(char)); //estamos alocando 27 elementos de tamanho 1 = 26 bytes alocados

    for(uint8_t i = 0; i < 26; i++) { //uint8_t é um tipo de 1 byte inteiro
        *(alphabet + i) = 'A' + i;
    }
    *(alphabet + 26) = '\0'; //null-terminate the string?

    printf("%p \n", alphabet);
    free(alphabet);
    return 0;
}

