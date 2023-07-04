#include "huffman.h"
#include "exceptions.h"
#include "frequenceTable.h"

Huffman::Huffman() {
    begin = nullptr;
    size = 0;
}

void Huffman::sortedInsert(No *no) {
    No *aux;

    // Checar se a lista está vazia
    if(begin == nullptr)
    {
        begin = no;
        size++;
    }
    
    // Analisar a frequência do nó que queremos inserir e a frequência do nó inicial
    else if(no->getFrequence() < begin->getFrequence())
    {
        no->setNextNo(begin);
        begin = no;
        size++;
    }

    // Nesse caso a frequência do nó que queremos inserir é maior que a frequência do nó do início
    else
    {
        aux = begin;
        // Enquanto existir um próximo nó e a frequência desse próximo nó for menor que a frequência do nó que quero inserir
        while(aux->getNextNo() && aux->getNextNo()->getFrequence() <= no->getFrequence())
            aux = aux->getNextNo(); // Caminha na lista

        no->setNextNo(aux->getNextNo());
        aux->setNextNo(no);
        size++;
    }
}

void Huffman::fillList(unsigned int *table) {
    No *newNo;

    for(int i = 0; i < TAM; i++)
    {
        if(table[i] > 0)
        {
            newNo = new No();
            if(newNo)
            {
                newNo->setCharacter(i); // O caracter do nó vai ser a posição i
                newNo->setFrequence(table[i]); // A frequência do nó vai ser a frequência que está na posição i da tabela
                newNo->setNextNo(nullptr);
                newNo->setLeftNo(nullptr);
                newNo->setRightNo(nullptr);

                sortedInsert(newNo);
            }

            else
                throw erroAoAlocarMemoriaNaLista();
        }
    }
}

void Huffman::printList() {
    No *aux = begin;

    cout << "\nLista encadeada ordenada, tamanho: " << size << endl;
    while(aux != nullptr)
    {
        cout << "\tCaracter: " << aux->getCharacter() << " " << "Frequencia: " << aux->getFrequence() << endl;
        aux = aux->getNextNo();
    }
}

No *Huffman::popFromList() {
    No *aux = nullptr;

    if(begin != nullptr)
    {
        aux = begin;
        begin = aux->getNextNo(); // O início da lista vai ser o próximo ponteiro
        aux->setNextNo(NULL);
        size--;
    }
    return aux;
}

No *Huffman::buildTree() {
    No *first, *second;
    No *newNo;

    while(size > 1)
    {
        first = popFromList();
        second = popFromList();
        newNo = (No*) malloc(sizeof(No));

        if(newNo)
        {
            newNo->setCharacter('+'); // O caracter desse nó é indiferente, pois ele é um nó intermediário
            int somaFrequencia = first->getFrequence() + second->getFrequence();
            newNo->setFrequence(somaFrequencia); // Frequencia do novo nó

            newNo->setLeftNo(first); // O nó da esquerda aponta pro primeiro nó que foi removido
            newNo->setRightNo(second); // O nó da direita aponta pro segundo nó que foi removido
            newNo->setNextNo(NULL);

            sortedInsert(newNo); // Insere o novo nó na lista
        }

        else
            throw erroAoAlocarMemoriaNaArvore();
    }
    return begin;
}

void Huffman::printTree(No *raiz, int size) {
    // Na árvore de huffman vamos imprimir somente os nós folhas
    if(raiz->getLeftNo() == NULL && raiz->getRightNo() == NULL)
        cout << "\tFolha: " << raiz->getCharacter() << " " << "Altura: " << size << endl;
    
    else
    {
        printTree(raiz->getLeftNo(), size + 1);
        printTree(raiz->getRightNo(), size + 1);
    }
}
