#ifndef STACK_H
#define STACK_H

#include "point.h"

#include <iostream>

class Stack {

    private:
        int top;
        int size;
        static const int STACK_SIZE = 10000; //atributo estático pois o tamanho tem de ser o mesmo para todos os objetos da classe
        Point itens[STACK_SIZE];

    public:
        Stack();
        ~Stack();
        void push(Point item);
        void displayStack();
        void clearStack();
        int emptyStack();
        int fullStack();
        int getSize();
        Point pop();
        Point getTop();
        Point getPoint(int index);

        /**
         * @brief retorna o ponto que está logo abaixo do topo da pilha.
                    É passado a pilha como referência pois é necessário modificar
                    a pilha dentro da função e refletir essa modificação fora da função.
                    A função recebe uma referência do objeto original ao invés de fazer uma cópia. 
         * 
         * @param S 
         * @return * Point 
         */
        static Point nextToTop(Stack &S);
};

#endif