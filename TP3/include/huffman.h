#ifndef LIST_H
#define LIST_H

#include "no.h"

/* Nesse arquivo é feito a lista encadeada ordenada a partir da tabela de frequência
 e montado a árvore de Huffman a partir da lista ordenada. */

class List {

    private:
        No *inicio;
        int size;

    public:
        List();
        void sortedInsert(No *no);
        void fillList(unsigned int *table);
        void printList();
        No *popFromList();
        
        No *buildTree();
        void printTree(No *raiz, int size);
};

#endif