#ifndef COMPRESS_H
#define COMPRESS_H

#include "no.h"

#include <iostream>

using namespace std;

class Compress {
    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Compress();

        /**
         * @brief Compressão de Huffman.
                 O char *str passado como parâmetro já é um texto codificado.
         * 
         * @param str 
         * @param filename 
         * @return * void 
         */
        void compress(unsigned char *str, char *filename);

        /**
         * @brief Verifica se um char passado como parâmetro é bit 1.
         * 
         * @param byte 
         * @param pos 
         * @return * unsigned int 
         */
        unsigned int isBit1(unsigned char byte, int pos);

        /**
         * @brief Descompactação de Huffman.
                É passado como parâmetro a raiz da árvore construída a partir da lista encadeada,
                o nome do arquivo que foi compactado e o arquivo de texto que será gerado de saída.
         * 
         * @param raiz 
         * @param compactedFilename 
         * @param outputFilename 
         * @return * void 
         */
        void decompress(No *root, char *compactedFilename, char *outputFilename);
};

#endif