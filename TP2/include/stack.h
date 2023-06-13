#ifndef STACK_H
#define STACK_H

#include "point.h"
#include "exceptions.h"

#include <iostream>

class Stack {

    private:
        int top;
        int size;
        static const int STACK_SIZE = 10000; //atributo estático pois o tamanho tem de ser o mesmo para todos os objetos da classe
        Point itens[STACK_SIZE];

    public:
        /**
         * @brief Construtor padrão da classse.
         * 
         */
        Stack();

        /**
         * @brief Destrutor padrão da classe.
         * 
         */
        ~Stack();

        /**
         * @brief Empilha um item do tipo Point na pilha.
         * 
         * @param item 
         * @return * void 
         */
        void push(Point item);

        /**
         * @brief Imprime a pilha.
         * 
         * @return * void 
         */
        void displayStack();

        /**
         * @brief Limpa a pilha setando o topo como -1 e o tamanho como 0.
         * 
         * @return * void 
         */
        void clearStack();

        /**
         * @brief Verifica se a pilha está vazia, retornando 1 caso verdadeiro.
         * 
         * @return * int 
         */
        int emptyStack();

        /**
         * @brief Verifica se a pilha está cheia, retornando 1 caso verdadeiro.
         * 
         * @return * int 
         */
        int fullStack();

        /**
         * @brief Retorna o tamanho atual da pilha.
         * 
         * @return * int 
         */
        int getSize();

        /**
         * @brief Desempilha um item do tipo Point da pilha.
         * 
         * @return * Point 
         */
        Point pop();

        /**
         * @brief Retorna o topo da pilha.
         * 
         * @return * Point 
         */
        Point getTop();

        /**
         * @brief Retorna o item do tipo Point que está na posição index da pilha.
         * 
         * @param index 
         * @return * Point 
         */
        Point getPoint(int index);

        /**
         * @brief Retorna o ponto que está logo abaixo do topo da pilha.
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