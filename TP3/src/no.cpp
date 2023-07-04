#include "../include/no.h"

No::No() {};

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

int No::getFrequence() {
    return frequence;
}

unsigned char No::getCharacter() {
    return character;
}

No *No::getNextNo() {
    return next;
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

void No::setNextNo(No *no) {
    this->next = no;
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