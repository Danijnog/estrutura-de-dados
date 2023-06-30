#ifndef TABELA_FREQUENCIA_H
#define TABELA_FREQUENCIA_H
#define TAM 256

#include <iostream>

using namespace std;

// Tabela de frequência de caracteres que vai ser usado para realizar a lista encadeada ordenada.

class frequenceTable {
    private:

    public:
        frequenceTable();

        void initializeFrequenceTableWith0(unsigned int table[]);
        void fillFrequenceTable(unsigned char text[], unsigned int table[]);
        void printFrequenceTable(unsigned int table[]);
};

#endif