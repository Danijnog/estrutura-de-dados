#ifndef CONVEX_HULL_H
#define CONVEX_HULL_H

#include "line.h"
#include "stack.h"

#include <iostream>

using namespace std;

class ConvexHull {
    
    private:
        Line l1;
        Line l2;

    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        ConvexHull();
        /**
         * @brief Construtor da classe.
         * 
         */
        ConvexHull(Line l1, Line l2);

        /**
         * @brief Destrutor padrão da classe.
         * 
         */
        ~ConvexHull();

        /**
         * @brief Imprime o fecho convexo através da pilha.
         * 
         * @param stack 
         * @return * void 
         */
        void displayConvexHull(Stack stack);

        /**
         * @brief Valida se os pontos do fecho convexo para desenhar estão dentro dos limites definidos da tela.
         * 
         * @param stack 
         * @param p0 
         * @return * int 
         */
        int validateDrawConvexHull(Stack stack, Point p0);

        /**
         * @brief Desenha o fecho convexo através da biblioteca graphics.h.
         * 
         * @param stack 
         * @param p0 
         * @return * void 
         */
        void drawConvexHull(Stack stack, Point *points, int size, Point p0);
};

#endif