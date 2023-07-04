#ifndef DICIONARIO_H
#define DICIONARIO_H

#include "no.h"
#include <string.h>

class Dictionary {
    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Dictionary();

        /**
         * @brief Aloca dinâmicamente a matriz de dicionário de caracteres
                de acordo com a quantidade de colunas, que é a altura da árvore.
         * 
         * @param columns 
         * @return * char** 
         */
        char **alocateDictionary(int columns);

        /**
         * @brief Constroi o dicionário dos caracteres com os valores 0 e 1.
         * 
         * @param dictionary 
         * @param raiz 
         * @param path 
         * @param columns 
         * @return * void 
         */
        void buildDictionary(char **dictionary, No *root, char *path, int columns);

        /**
         * @brief Printa o dicionário no terminal.
         * 
         * @param dictionary 
         * @return * void 
         */
        void printDictionary(char **dictionary);

        /**
         * @brief Retorna o tamanho do dicionário que será usado no método 'encode' abaixo.
         * 
         * @param dictionary 
         * @param text 
         * @return * int 
         */
        int calculateSizeOfString(char **dictionary, unsigned char *text);

        /**
         * @brief Concatena os valores definidos de cada caracter do dicionário em um único *char.
         * 
         * @param dictionary 
         * @param text 
         * @return * char* 
         */
        char *encode(char **dictionary, unsigned char *text);

        /**
         * @brief Retorna o texto decodificado a partir da árvore e do texto codificado.
         * 
         * @param raiz 
         * @param text 
         * @return * char* 
         */

        char *decode(No *root, unsigned char *encodeText);
};

#endif