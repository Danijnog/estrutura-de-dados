#ifndef TABELA_FREQUENCIA_H
#define TABELA_FREQUENCIA_H
#define TAM 256

#include <iostream>

using namespace std;

// Tabela de frequência de caracteres que vai ser usado para realizar a lista encadeada ordenada.
class frequenceTable {
    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        frequenceTable();

        void initializeFrequenceTableWith0(unsigned int *table);

        /**
         * @brief Preenche a tabela de frequência com o texto passado como parâmetro.
         * 
         * @param text 
         * @param table 
         * @return * void 
         */
        void fillFrequenceTable(unsigned char *text, unsigned int *table);

        /**
         * @brief Printa o caracter tanto em sua normal representação quanto seu valor na tabela ASC
                e também printa sua frequência.
         * 
         * @param table 
         * @return * void 
         */
        void printFrequenceTable(unsigned int *table);
};

#endif