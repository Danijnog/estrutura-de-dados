#include "tabelaFrequencia.h"
#include "huffman.h"
#include "dicionario.h"
#include "compress.h"
#include "entry.h"

int main (int argc, char **argv) {
    frequenceTable frequenceTable;
    Dictionary dictionary;
    Compress compress;
    No *arvore;
    List list;
    unsigned char *text;
    int size;
    char path[] = ""; // Variavel utilizada para construir o dicionário de textos
    int columns; // Variavel utilizada para saber a quantidade de colunas do dicionário
    FILE *file;

    int choosenOption = validateEntry(argc, argv);   // Verificar a opção escolhida pelo usuário
    switch(choosenOption)
    {
        case COMPACTAR:
            file = fopen(argv[2], "r");
            size = countCharactersOfFile(argv[2]);
            text = (unsigned char*)calloc(size + 2, sizeof(unsigned char));

            if(file == nullptr)
                cout << "Não foi possível abrir o arquivo na função main durante a compactação!\n";
            
            readEntry(argv[2], text);
            printf("TEXTO ");
            cout << text << endl;
            writeEntryOnAuxFile("arquivoAuxiliar.txt", text);

             // Tabela de frequência
            unsigned int freqTable[TAM];
            frequenceTable.initializeFrequenceTableWith0(freqTable);
            frequenceTable.fillFrequenceTable(text, freqTable);
            frequenceTable.printFrequenceTable(freqTable);

            // Lista encadeada ordenada
            list.fillList(freqTable);

            // Arvore de huffman a partir da lista
            arvore = list.buildTree();
            cout << "\nArvore de Huffman \n";
            list.printTree(arvore, 0);

            // Dicionário do texto codificado
            columns = No::treeHeight(arvore) + 1; // Temos que incluir o + 1 por causa do caracter final \0 de strings
            char **dictionary_;
            dictionary_ = dictionary.alocateDictionary(columns);
            dictionary.buildDictionary(dictionary_, arvore, path, columns);
            dictionary.printDictionary(dictionary_);

            // Codificar cada caracter e concatena o código
            char *encodeText;
            encodeText = dictionary.encode(dictionary_, text);
               
            // Gerar um arquivo compactado de fato
            cout << "\tCompactando....\n";
            compress.compress(reinterpret_cast<unsigned char*>(encodeText), argv[3]);

            free(text);
            for(int i = 0; i < columns; i++)
                free(dictionary_[i]);
            free(dictionary_);
            free(encodeText);

            fclose(file);
            break;
        
        case DESCOMPACTAR:
            // A tabela de frequência e a árvore de Huffman vai ser remontada a partir do arquivoAuxiliar gerado
            file = fopen("arquivoAuxiliar.txt", "r");
            size = countCharactersOfFile("arquivoAuxiliar.txt");
            text = (unsigned char*)calloc((size + 2), sizeof(unsigned char));

            if(file == nullptr)
                cout << "Não foi possível abrir o arquivo na função main durante a compactação!\n";
            
            readEntry("arquivoAuxiliar.txt", text);
            
            // Tabela de frequência
            unsigned int freqTableAux[TAM];
            frequenceTable.initializeFrequenceTableWith0(freqTableAux);
            frequenceTable.fillFrequenceTable(text, freqTableAux);

            // Lista encadeada ordenada
            list.fillList(freqTableAux);

            // Arvore de huffman a partir da lista
            arvore = list.buildTree();

            cout << "Descompactando....\n";
            compress.decompress(arvore, argv[2], argv[3]);

            fclose(file);
            break;
    }

    return 0;  
}

