#ifndef COMPRESS_H
#define COMPRESS_H

#include "no.h"

#include <iostream>
using namespace std;

class Compress {
    private:

    public:
        Compress();
        void compress(unsigned char *str, char *filename);
        unsigned int isBit1(unsigned char byte, int pos);
        void decompress(No *raiz, char *compactedFilename, char *outputFilename);
};


#endif