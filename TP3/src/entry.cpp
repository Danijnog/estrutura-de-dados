#include "entry.h"
#include "exceptions.h"

int countCharactersOfFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == nullptr)
    {
        cout << "Não foi possível abrir o arquivo na função countCharactersOfFile() do arquivo entry.cpp.\n";
        exit(1);
    }
    int count = 0;

    while(fgetc(file) != -1) // A função fgetc lê cada caracter do arquivo
        count++;

    return count;
}

void readEntry(const char *filename, unsigned char *text) {
    FILE *file = fopen(filename, "r");
    if(file == nullptr)
        cout << "Não foi possível abrir o arquivo na função readEntry() do arquivo entry.cpp." << endl;

    char letra;
    int i = 0;
    while(1)
    {
        letra = fgetc(file);
        if(feof(file))
            break;
            
        if(letra != -1) // Verificação para checar que não vai ser pego caracteres inválidos do arquivo
        {
            text[i] = letra;
            i++;
        }
    }
}

int validateEntry(int argc, char **argv) {
    int aux;
    int choosenOption = 0;

    // if(argc != 4)
    //     throw entradaInvalida();

    while((aux = getopt(argc, argv, "c:d:h")) != EOF) //Opções 'c' e 'd' requerem argumento
    {
        switch(aux)
        {
            case 'c': // Compactar
                choosenOption = COMPACTAR;
                break;
            
            case 'd': // Descompactar
                choosenOption = DESCOMPACTAR;
                break;
            
            case 'h': // Ajuda
                cout << "Menu de ajuda: " << endl;
                cout << "Comando para compactar um arquivo: " << endl;
                cout << "\tbin/main -c nome_arquivo_a_ser_lido.in nome_arquivo_compactado" << endl;
                cout << "\tExemplo: bin/main -c entrada.in compactado." << endl;
                cout << endl;
                cout << "Comandos para descompactar um arquivo: " << endl;
                break;

            
            default:
                cout << "Opção inválida ou ausente: " << optopt << endl; // Saída de erro
                break;

        }
    }
    return choosenOption;
}

void writeEntryOnAuxFile(const char *filename, unsigned char *text) {
    FILE *file = fopen(filename, "w");
    if(file == nullptr)
    {
        cout << "Não foi possível abrir o arquivo na função writeEntryOnAuxFile do arquivo entry.cpp";
        exit(1);
    }

    fputs(reinterpret_cast<const char*>(text), file);
}