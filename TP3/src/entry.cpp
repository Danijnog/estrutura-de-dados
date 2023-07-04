#include "entry.h"
#include "exceptions.h"

int countCharactersOfFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    int count = 0;
    if(file == nullptr)
        throw arquivoNaoEncontradoNaEntrada();

    while(fgetc(file) != -1) // A função fgetc lê cada caracter do arquivo
        count++;

    return count;
}

void readFile(const char *filename, unsigned char *text) {
    FILE *file = fopen(filename, "r");
    if(file == nullptr)
        throw arquivoNaoEncontradoNaEntrada();

    char letter;
    int i = 0;
    while(1)
    {
        letter = fgetc(file);
        if(feof(file))
            break;
            
        if(letter != -1) // Verificação para checar que não vai ser pego caracteres inválidos do arquivo
        {
            text[i] = letter;
            i++;
        }
    }
}

int validateEntry(int argc, char **argv) {
    int aux;
    int choosenOption = 0;

    if(argc > 4 || argc < 2)
        throw entradaInvalida();

    while((aux = getopt(argc, argv, "c:d:h")) != EOF) //Opções 'c' e 'd' requerem argumento
    {
        switch(aux)
        {
            case 'c': // Compactar
                choosenOption = COMPRESS;
                break;
            
            case 'd': // Descompactar
                choosenOption = DECOMPRESS;
                break;
            
            case 'h': // Ajuda
                cout << YELLOW << "Menu de ajuda: " << endl;
                cout << MAGENTA << "Comando para compactar um arquivo: " << endl;
                cout << RESET << "\tbin/main -c nome_arquivo_a_ser_lido.in nome_arquivo_compactado" << endl;
                cout << "\tExemplo: bin/main -c entrada.in compactado.wg" << endl;
                cout << endl;
                cout << MAGENTA << "Comandos para descompactar um arquivo: " << endl;
                cout << RESET << "\tbin/main -d nome_arquivo_compactado arquivo_descompactado.txt" << endl;
                cout << "\tExemplo: bin/main -d compactado.wg output.txt" << endl;
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
        throw arquivoNaoEncontradoNaEntrada();

    fputs(reinterpret_cast<const char*>(text), file);
}

long int getFileSize(char *filename) {
    FILE* file = fopen(filename, "rb");

    if (file == nullptr)
        throw arquivoNaoEncontradoNaEntrada();

    fseek(file, 0, SEEK_END);  // Move o ponteiro para o final do arquivo
    long int fileSize = ftell(file);  // Obtém a posição atual do ponteiro (tamanho do arquivo)

    return fileSize;
}