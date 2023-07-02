#include "dicionario.h"
#include "tabelaFrequencia.h"

Dictionary::Dictionary() {}

char **Dictionary::alocateDictionary(int columns) {
    char **dictionary;

    // Aloca memória para as linhas
    dictionary = (char**)malloc(sizeof(char*) * TAM);

    // Aloca memória para as colunas de cada linha
    for (int i = 0; i < TAM; i++)
        dictionary[i] = (char*)calloc(columns, sizeof(char)); // Foi utilizado o calloc para já inicializar com 0 cada posição

    return dictionary;
}

void Dictionary::buildDictionary(char **dictionary, No *raiz, char *path, int columns) {
    char left[columns], right[columns];

    // Checar se estamos em uma folha
    if(raiz->getLeftNo() == nullptr && raiz->getRightNo() == nullptr)
        strcpy(dictionary[raiz->getCharacter()], path);

    else
    {
        strcpy(left, path);
        strcpy(right, path);

        // Na árvore de Huffman ao caminhar pra esquerda atribuimos 0 ao caminho (path), se caminharmos pra direita atribuimos 1 ao caminho (path)
        strcat(left, "0"); // Concatena a string left com 0
        strcat(right, "1"); // Concatena a string right com 1

        buildDictionary(dictionary, raiz->getLeftNo(), left, columns);
        buildDictionary(dictionary, raiz->getRightNo(), right, columns);
    }
}

void Dictionary::printDictionary(char **dictionary) {
    cout << "\nDicionário" << endl;

    for(int i = 0; i < TAM; i++)
        if(strlen(dictionary[i]) > 0)
            cout << "\tCaracter na tabela ASC: " << i << " " << "Código: " << dictionary[i] << endl;
}

int Dictionary::calculateSizeOfString(char **dictionary, unsigned char *text) {
    int size = 0;
    for(int i = 0; text[i] != '\0'; i++)
        size = size + strlen(dictionary[text[i]]);

    return size + 1; // Caracter \0 no final
}

char *Dictionary::encode(char **dictionary, unsigned char *text) {
    int size = calculateSizeOfString(dictionary, text);

    char *code = (char*)calloc(size, sizeof(char));

    for(int i = 0; text[i] != '\0'; i++)
        strcat(code, dictionary[text[i]]);
    
    return code;
}

char *Dictionary::decode(No *raiz, unsigned char *text) {
    No *aux = raiz;
    char temp[2]; // Temp é utilizado para transformar um caracter em uma string para usar a função strcat

    char *decodeText = (char*)calloc(strlen((char*)(text)), sizeof(char));

    for(int i = 0; text[i] != '\0'; i++)
    {
        if(text[i] == '0')
            aux = aux->getLeftNo();
        
        else // Se o valor na posição i do texto for == 1
            aux = aux->getRightNo();
        
        if(aux->getRightNo() == nullptr && aux->getLeftNo() == nullptr) // Aux é uma folha
        {
            temp[0] = aux->getCharacter();
            temp[1] = '\0';
            strcat(decodeText, temp);

            aux = raiz;
        }
    }
    return decodeText;
}
