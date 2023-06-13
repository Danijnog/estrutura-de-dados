#ifndef POINT_H
#define POINT_H

#include <math.h>

class Point {
    
    private:
        int x, y;
    
    public:

        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Point();

        /**
         * @brief Construtor da classe.
         * 
         */
        Point(int x, int y);

        /**
         * @brief Destrutor da classe.
         * 
         */
        ~Point();

        /**
         * @brief troca os valores de 2 pontos
         * 
         * @param p1 
         * @param p2 
         * @return * void 
         */
        static void swap(Point &p1, Point &p2);

        /**
         * @brief método para achar a orientação entre 3 pontos ordenados
                    retorna os seguintes valores:
                    0 -> p, q, r são colineares
                    1 -> os pontos estão dispostos no sentindo horário (clockwise)
                    2 -> os pontos estão dispostos no sentido anti-horário(counterclockwise)
         * 
         * @param p 
         * @param q 
         * @param r 
         * @return * int 
         */
        static int orientation(Point p, Point q, Point r);

        /**
         * @brief Encontra o valor do ângulo passado como parâmetro em relação a origem (0, 0) em radianos.
         * 
         * @param p 
         * @return * double 
         */
        double computeAngle(Point p);

        /**
         * @brief Verifica se todos os pontos passado como parâmetro são colineares, retornando verdadeiro se forem.
         * 
         * @param points 
         * @param n 
         * @return * int 
         */
        static int verifyCollinearPoints(Point *points, int size);

        /**
         * @brief retorna a coordenada x de um ponto.
         * 
         * @return * int 
         */
        int getX();

        /**
         * @brief retorna a coordenada y de um ponto.
         * 
         * @return * int 
         */
        int getY();
};

#endif