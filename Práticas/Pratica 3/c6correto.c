#include <stdlib.h>
#include <stdint.h>
#include "stdio.h"

struct _List {
    int32_t* data; //o tamanho para um ponteiro de 32 bits (4 bytes) pode variar dependendo do computador e da arqtuiterua. Nesse caso, ele vale 8 bytes
    int32_t length; //o compilador adicionou 4 bytes de padding, porém o int32_t normalmente tem apenas 4 bytes, ficano nesse caso 8 bytes
};
typedef struct _List List;

List* resizeArray(List* array) {
    int32_t* dPtr = array->data;
    dPtr = realloc(dPtr, 15 * sizeof(int32_t)); //doesn't update array->data
    array->length = 10;

    if(dPtr != NULL) //temos que checar se foi realocado corretamente
    {
        array->data = dPtr; //atualizamos o ponteiro data para apontar para o novo bloco de memória alocado
        for(int i = 0; i < array->length; i++)
            array->data[i] = i;
    }
    else 
        printf("Falha na realocação de memória!\n");
    
    return array;
}

int main() {
    List* array = calloc(1, sizeof(List)); //irá alocar 1 elemento de tamanho 16 bytes
    array->data = calloc(10, sizeof(int32_t)); //irá alocar 10 elementos de tamanho 4 bytes cada um
    array->length = 5;

    printf("Valores iniciais\n");
    for(int i = 0; i < array->length; i++)
    {
        array->data[i] = i;
        printf("%d \n", array->data[i]);
    }

    array = resizeArray(array);

    printf("Valores depois de realocar o array\n");
    for(int i = 0; i < array->length; i++)
    {
        array->data[i] = i;
        printf("%d \n", array->data[i]);
    }

    free(array->data);
    free(array);

    return 0;
}

