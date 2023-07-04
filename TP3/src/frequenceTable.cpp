#include "frequenceTable.h"

frequenceTable::frequenceTable() {}

void frequenceTable::initializeFrequenceTableWith0(unsigned int *table) {
    for(int i = 0; i < TAM; i++)
        table[i] = 0;
}

void frequenceTable::fillFrequenceTable(unsigned char *text, unsigned int *table) {
    for(int i = 0; text[i] != '\0'; i++)
        table[text[i]]++;
}

void frequenceTable::printFrequenceTable(unsigned int *table) {
    for(int i = 0; i < TAM; i++)
        if(table[i] > 0) // Só vamos imprimir o caracter que tiver mais de 0 em sua frequencia na tabela
            printf("%d = %c = frequencia: %u \n", i, i, table[i]);
}