#include "exceptions.h"
#include "frequenceTable.h"
#include "huffman.h"
#include "dictionary.h"
#include "compress.h"
#include "entry.h"

int main (int argc, char **argv) {
    frequenceTable frequenceTable;
    Dictionary dictionary;
    Compress compress;
    No *arvore;
    Huffman huffman;
    unsigned char *text;
    int size;
    char path[] = ""; // Variavel utilizada para construir o dicionário de textos
    int columns; // Variavel utilizada para saber a quantidade de colunas do dicionário
    FILE *file;

    int choosenOption = validateEntry(argc, argv);   // Verificar a opção escolhida pelo usuário
    switch(choosenOption)
    {
        case COMPRESS:
            file = fopen(argv[2], "r");
            size = countCharactersOfFile(argv[2]);
            text = (unsigned char*)calloc(size + 2, sizeof(unsigned char));

            if(file == nullptr)
                throw falhaAoAbrirArquivoDeEntrada();
            
            readFile(argv[2], text);
            writeEntryOnAuxFile("arquivoAuxiliar.txt", text);

             // Tabela de frequência
            unsigned int freqTable[TAM];
            frequenceTable.initializeFrequenceTableWith0(freqTable);
            frequenceTable.fillFrequenceTable(text, freqTable);

            // Lista encadeada ordenada
            huffman.fillList(freqTable);

            // Arvore de huffman a partir da lista
            arvore = huffman.buildTree();

            // Dicionário do texto codificado
            columns = No::treeHeight(arvore) + 1; // Temos que incluir o + 1 por causa do caracter final \0 de strings
            char **dictionary_;
            dictionary_ = dictionary.alocateDictionary(columns);
            dictionary.buildDictionary(dictionary_, arvore, path, columns);

            // Codificar cada caracter e concatena o código
            char *encodeText;
            encodeText = dictionary.encode(dictionary_, text);
               
            // Gerar um arquivo compactado de fato
            cout << YELLOW << "\nCompactando....\n";
            compress.compress(reinterpret_cast<unsigned char*>(encodeText), argv[3]);
            cout << CYAN << "\tTamanho do arquivo original: " << MAGENTA << getFileSize(argv[2])/1000 << "KB" << endl;
            cout << GREEN << "\t✓ " << CYAN << "Tamanho do arquivo compactado: " << GREEN << getFileSize(argv[3])/1000 << "KB" << endl;
    
            free(text);
            for(int i = 0; i < columns; i++)
                free(dictionary_[i]);
            free(dictionary_);
            free(encodeText);

            fclose(file);
            break;
        
        case DECOMPRESS:
            // A tabela de frequência e a árvore de Huffman vai ser remontada a partir do arquivoAuxiliar gerado
            file = fopen("arquivoAuxiliar.txt", "r");
            size = countCharactersOfFile("arquivoAuxiliar.txt");
            text = (unsigned char*)calloc((size + 2), sizeof(unsigned char));

            if(file == nullptr)
                throw falhaAoAbrirArquivoAuxiliar();
            
            readFile("arquivoAuxiliar.txt", text);
            
            // Tabela de frequência
            unsigned int freqTableAux[TAM];
            frequenceTable.initializeFrequenceTableWith0(freqTableAux);
            frequenceTable.fillFrequenceTable(text, freqTableAux);

            // Lista encadeada ordenada
            huffman.fillList(freqTableAux);

            // Arvore de huffman a partir da lista
            arvore = huffman.buildTree();

            cout << YELLOW << "\nDescompactando....\n";
            compress.decompress(arvore, argv[2], argv[3]);
            cout << GREEN << "\t✓ " << "Arquivo descompactado com sucesso!" << endl;
            cout << CYAN << "\tArquivo gerado: " << GREEN << argv[3] << endl;

            fclose(file);
            break;
    }
    return 0;  
}

