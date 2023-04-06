#include <stdlib.h>
#include <stdint.h>

int main() {
    char* destination = calloc(27, sizeof(char)); //alocando 27 bytes inicializados com valor 0
    char* source = malloc(26 * sizeof(char)); //alocando 26 bytes

    for(uint8_t i = 0; i < 27; i++) {
        *(destination + i) = *(source + i); //Look at the last iteration.
    }

    free(destination);
    free(source);
    return 0;
}

