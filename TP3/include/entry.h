#ifndef ENTRY_H
#define ENTRY_H

#include "getopt.h"
#include <iostream>
using namespace std;

#define COMPACTAR 1
#define DESCOMPACTAR 2

int countCharactersOfFile(const char *filename);
void readEntry(const char *filename, unsigned char *text);
int validateEntry(int argc, char **argv);

void writeEntryOnAuxFile(const char *filename, unsigned char *text);


#endif
