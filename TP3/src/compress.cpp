#include "compress.h"
#include "exceptions.h"
#include <cstdio>

Compress::Compress() {}

void Compress::compress(unsigned char *str, char *filename) {
    // Esse arquivo será um arquivo binário e não um arquivo texto
    // O modo de abertura é 'w' para escrever no arquivo e 'b' de binário
    FILE *file = fopen(filename, "wb");
    unsigned char byte = 0;
    unsigned char aux;
    int j = 7;

    if(file == nullptr)
        throw arquivoNaoEncontradoNaCompressao();

    for(int i = 0; str[i] != '\0'; i++)
    {
        aux = 1;
        if(str[i] == '1')
        {
            aux = aux << j; // Desloca a variável aux pra esquerda 7 vezes, inicialmente
            byte = aux | byte;
        }
        j--;

        if(j < 0) // Se j < 0, significa que já temos um byte completo pra escrever no arquivo
        {
            fwrite(&byte, sizeof(byte), 1, file);
            j = 7;
            byte = 0;
        }
    }

    if(j != 7) // Bytes pela metade
        fwrite(&byte, sizeof(byte), 1, file);
}

unsigned int Compress::isBit1(unsigned char byte, int pos) {
    unsigned char aux = (1 << pos); // Desloca '00000001' 'pos' bits a esquerda

    return byte & aux; // Retorna o resultado entre a operação and entre 'byte' e 'aux' em 'pos'
}

void Compress::decompress(No *root, char *compactedFilename, char *outputFilename) {
    FILE *file = fopen(compactedFilename, "rb");
    FILE *outputFile = fopen(outputFilename, "w");
    unsigned char byte;

    No *aux = root;

    if(file == nullptr)
        throw arquivoNaoEncontradoNaCompressao();

    while(fread(&byte, sizeof(byte), 1, file))
    {
        for(int i = 7; i >= 0; i--)
        {
            if(isBit1(byte, i))
                aux = aux->getRightNo();
            else 
                aux = aux->getLeftNo();

            if(aux->getLeftNo() == nullptr && aux->getRightNo() == nullptr)
            {
                fputc(aux->getCharacter(), outputFile);
                aux = root;
            }
        }
    }
}