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
};


#endif