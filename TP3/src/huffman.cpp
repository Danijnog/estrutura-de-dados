#include "huffman.h"
#include "tabelaFrequencia.h"
#include <cstddef>

List::List() {
    inicio = nullptr;
    size = 0;
}

void List::sortedInsert(No *no) {
    No *aux;

    // Checar se a lista está vazia
    if(inicio == nullptr)
    {
        inicio = no;
        size++;
    }
    
    // Analisar a frequência do nó que queremos inserir e a frequência do nó inicial
    else if(no->getFrequence() < inicio->getFrequence())
    {
        no->setProximo(inicio);
        inicio = no;
        size++;
    }

    // Nesse caso a frequência do nó que queremos inserir é maior que a frequência do nó do início
    else
    {
        aux = inicio;
        // Enquanto existir um próximo nó e a frequência desse próximo nó for menor que a frequência do nó que quero inserir
        while(aux->getProximo() && aux->getProximo()->getFrequence() <= no->getFrequence())
            aux = aux->getProximo(); // Caminha na lista

        no->setProximo(aux->getProximo());
        aux->setProximo(no);
        size++;
    }
}

void List::fillList(unsigned int *table) {
    No *novo;

    for(int i = 0; i < TAM; i++)
    {
        if(table[i] > 0)
        {
            novo = new No();
            if(novo)
            {
                novo->setCharacter(i); // O caracter do nó vai ser a posição i
                novo->setFrequence(table[i]); // A frequência do nó vai ser a frequência que está na posição i da tabela
                novo->setProximo(nullptr);
                novo->setLeft(nullptr);
                novo->setRight(nullptr);

                sortedInsert(novo);
            }

            else
                throw "Erro ao alocar memória de um nó para preencher a lista!";
        }
    }
}

void List::printList() {
    No *aux = inicio;

    cout << "\nLista encadeada ordenada, tamanho: " << size << endl;
    while(aux != nullptr)
    {
        cout << "\tCaracter: " << aux->getCharacter() << " " << "Frequencia: " << aux->getFrequence() << endl;
        aux = aux->getProximo();
    }
}

No *List::popFromList() {
    No *aux = nullptr;

    if(inicio != nullptr)
    {
        aux = inicio;
        inicio = aux->getProximo(); // O início da lista vai ser o próximo ponteiro
        aux->setProximo(NULL);
        size--;
    }
    return aux;
}

No *List::buildTree() {
    No *primeiro, *segundo;
    No *novo;

    while(size > 1)
    {
        primeiro = popFromList();
        segundo = popFromList();
        novo = new No();

        if(novo)
        {
            novo->setCharacter('+'); // O caracter desse nó é indiferente, pois ele é um nó intermediário
            int somaFrequencia = primeiro->getFrequence() + segundo->getFrequence();
            novo->setFrequence(somaFrequencia); // Frequencia do novo nó

            novo->setLeft(primeiro); // O nó da esquerda aponta pro primeiro nó que foi removido
            novo->setRight(segundo); // O nó da direita aponta pro segundo nó que foi removido
            novo->setProximo(NULL);

            sortedInsert(novo); // Insere o novo nó na lista
        }

        else
            throw "Não foi possível alocar memória para o novo nó ao construir a árvore! Função: buildTree()";
    }
    return inicio;
}

void List::printTree(No *raiz, int size) {
    // Na árvore de huffman vamos imprimir somente os nós folhas
    if(raiz->getLeft() == NULL && raiz->getRight() == NULL)
        cout << "\tFolha: " << raiz->getCharacter() << " " << "Altura: " << size << endl;
    
    else
    {
        printTree(raiz->getLeft(), size + 1);
        printTree(raiz->getRight(), size + 1);
    }
}
