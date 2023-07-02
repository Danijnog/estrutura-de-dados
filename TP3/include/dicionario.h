#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "no.h"
#include <string.h>

class Dictionary {
    private:

    public:
        Dictionary();
        char **alocateDictionary(int columns); // Vai ser uma matriz.
        void buildDictionary(char **dictionary, No *raiz, char *path, int columns);
        void printDictionary(char **dictionary);

        int calculateSizeOfString(char **dictionary, unsigned char *text);

        /**
         * @brief Concatena os valores definidos de cada caracter do dicionário em uma única string
         * 
         * @param dictionary 
         * @param text 
         * @return * char* 
         */
        char *encode(char **dictionary, unsigned char *text);

        char *decode(No *raiz, unsigned char *text);


};


#endif