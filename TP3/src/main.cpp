#include "../include/tabelaFrequencia.h"
#include "../include/huffman.h"
#include "dicionario.h"
#include <locale.h>

int main () {
    setlocale(LC_ALL, ""); // Reconhece a codificação da máquina que está rodando

    // ---- 1 - Tabela de frequência
    frequenceTable frequenceTable;
    unsigned char text[] = "Vamos aprender a programa";
    unsigned int freqTable[TAM];

    frequenceTable.initializeFrequenceTableWith0(freqTable);
    frequenceTable.fillFrequenceTable(text, freqTable);
    frequenceTable.printFrequenceTable(freqTable);

    // ---- 2 - Lista encadeada ordenada
    List list = List();
    list.fillList(freqTable);
    list.printList();


    // ---- 3 - Arvore de huffman a partir da lista
    No *arvore;
    arvore = list.buildTree();
    cout << "\nArvore de Huffman \n";
    list.printTree(arvore, 0);

    // ---- 4 - Dicionário do texto codificado
    Dictionary dictionary;
    int columns = No::treeHeight(arvore) + 1; // Temos que incluir o + 1 por causa do caracter final \0 de strings
    char **dictionary_;
    char path[] = "";
    dictionary_ = dictionary.alocateDictionary(columns);
    dictionary.buildDictionary(dictionary_, arvore, path, columns);
    dictionary.printDictionary(dictionary_);

    return 0;
}