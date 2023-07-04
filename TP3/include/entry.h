#ifndef ENTRY_H
#define ENTRY_H

#include "getopt.h"

#include <iostream>

using namespace std;

// Definição de cores que serão usadas no terminal      
#define GREEN   "\033[32m"      
#define YELLOW  "\033[33m" 
#define MAGENTA "\033[35m"          
#define CYAN    "\033[36m"
#define RESET   "\033[0m"

#define COMPRESS 1
#define DECOMPRESS 2

/**
 * @brief Retorna a quantidade de caracteres de um arquivo.
 * 
 * @param filename 
 * @return * int 
 */
int countCharactersOfFile(const char *filename);

/**
 * @brief Lê o arquivo passado como parâmetro e 
        atribui ao char *text passado como parâmetro o texto do arquivo de entrada.
 * 
 * @param filename 
 * @param text 
 * @return * void 
 */
void readFile(const char *filename, unsigned char *text);

/**
 * @brief Lê a entrada do programa e realiza a validação da mesma
        de acordo com a flags definidas na regra de négocio.
 * 
 * @param argc 
 * @param argv 
 * @return * int 
 */
int validateEntry(int argc, char **argv);

/**
 * @brief Escreve o texto do arquivo de entrada do programa em um arquivo auxiliar
        passado como parâmetro nessa função, que será utilizado no momento de 
        descompactação de um arquivo no programa.
 * 
 * @param filename 
 * @param text 
 * @return * void 
 */
void writeEntryOnAuxFile(const char *filename, unsigned char *text);

/**
 * @brief Retorna o tamanho de um arquivo em Bytes.
 * 
 * @param filename 
 * @return * long int 
 */
long int getFileSize(char *filename);

#endif
