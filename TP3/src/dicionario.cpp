#include "dicionario.h"
#include "tabelaFrequencia.h"

Dictionary::Dictionary() {}

char **Dictionary::alocateDictionary(int columns) {
    char **dictionary;

    // Aloca memória para as linhas
    dictionary = new char*[TAM];

    // Aloca memória para as colunas de cada linha
    for (int i = 0; i < TAM; i++)
        dictionary[i] = (char*)calloc(columns, sizeof(char)); // Foi utilizado o calloc para já inicializar com 0 cada posição

    return dictionary;
}

void Dictionary::buildDictionary(char **dictionary, No *raiz, char *path, int columns) {
    char left[columns], right[columns];

    // Checar se estamos em uma folha
    if(raiz->getLeft() == nullptr && raiz->getRight() == nullptr)
        strcpy(dictionary[raiz->getCharacter()], path);

    else
    {
        strcpy(left, path);
        strcpy(right, path);

        // Na árvore de Huffman ao caminhar pra esquerda atribuimos 0 ao caminho (path), se caminharmos pra direita atribuimos 1 ao caminho (path)
        strcat(left, "0"); // Concatena a string left com 0
        strcat(right, "1"); // Concatena a string right com 1

        buildDictionary(dictionary, raiz->getLeft(), left, columns);
        buildDictionary(dictionary, raiz->getRight(), right, columns);
    }
}

void Dictionary::printDictionary(char **dictionary) {
    cout << "\nDicionário" << endl;

    for(int i = 0; i < TAM; i++)
        if(strlen(dictionary[i]) > 0)
            cout << "\tCaracter na tabela ASC: " << i << " " << "Código: " << dictionary[i] << endl;
}


