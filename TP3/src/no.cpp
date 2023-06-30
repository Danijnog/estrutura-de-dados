#include "../include/no.h"

No::No() {};

int No::getFrequence() {
    return frequence;
}

unsigned char No::getCharacter() {
    return character;
}

No *No::getProximo() {
    return proximo;
}

No *No::getLeft() {
    return left;
}

No *No::getRight() {
    return right;
}

void No::setFrequence(int f) {
    this->frequence = f;
}

void No::setProximo(No *no) {
    this->proximo = no;
}

void No::setCharacter(unsigned char c) {
    this->character = c;
}

void No::setLeft(No *no) {
    this->left = no;
}

void No::setRight(No *no) {
    this->right = no;
}

int No::treeHeight(No *raiz) {
    int left, right;

    if(raiz == nullptr)
        return -1;
    
    else
    {
        left = treeHeight(raiz->getLeft()) + 1;
        right = treeHeight(raiz->getRight()) + 1;

        if(left > right)
            return left;

        return right;
    }
}