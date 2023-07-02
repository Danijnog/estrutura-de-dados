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

No *No::getLeftNo() {
    return left;
}

No *No::getRightNo() {
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

void No::setLeftNo(No *no) {
    this->left = no;
}

void No::setRightNo(No *no) {
    this->right = no;
}

int No::treeHeight(No *raiz) {
    int left, right;

    if(raiz == nullptr)
        return -1;
    
    else
    {
        left = treeHeight(raiz->getLeftNo()) + 1;
        right = treeHeight(raiz->getRightNo()) + 1;

        if(left > right)
            return left;

        return right;
    }
}