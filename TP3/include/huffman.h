#ifndef LIST_H
#define LIST_H

#include "no.h"

/* Nesse arquivo é feito a lista encadeada ordenada a partir da tabela de frequência
 e montado a árvore de Huffman a partir da lista encadeada ordenada. */

class Huffman {
    private:
        No *begin;
        int size;

    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Huffman();

        /**
         * @brief Insere na lista encadeada de forma ordenada.
         * 
         * @param no 
         * @return * void 
         */
        void sortedInsert(No *no);

        /**
         * @brief Preenche a lista ordenada de acordo com a tabela de frequência de
                caracteres gerada.
         * 
         * @param table 
         * @return * void 
         */
        void fillList(unsigned int *table);

        /**
         * @brief Printa a lista encadeada ordenada.
         * 
         * @return * void 
         */
        void printList();

        /**
         * @brief Remove um elemento do início da lista.
         * 
         * @return * No* 
         */
        No *popFromList();
        
        /**
         * @brief Constroi a árvore de Huffman de acordo com a lista encadeada criada.
         * 
         * @return * No* 
         */
        No *buildTree();

        /**
         * @brief Printa a árvore de Huffman construída.
         * 
         * @param raiz 
         * @param size 
         * @return * void 
         */
        void printTree(No *root, int size);
};

#endif