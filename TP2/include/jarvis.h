#ifndef JARVIS_H
#define JARVIS_H

#include "point.h"
#include "stack.h"

class Jarvis {

    public:

        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Jarvis();

        /**
         * @brief Destrutor padrão da classe.
         * 
         */
        ~Jarvis();

        /**
         * @brief Algoritmo de Jarvis para encontrar o fecho convexo de um conjunto de pontos passado como parâmetro.
         * 
         * @param points 
         * @param n 
         * @return * Stack 
         */
        Stack jarvisMarch(Point *points, int n);

        /**
         * @brief Encontra o índice do ponto que está mais a esquerda em relação ao eixo x.
         * 
         * @param points 
         * @param n 
         * @return * int 
         */
        int getMostLeftIndex(Point *points, int n);
};


#endif