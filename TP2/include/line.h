#ifndef LINE_H
#define LINE_H

#include "point.h"
#include <iostream>

using namespace std;

class Line {

    private:
        Point p1, p2;
        
    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        Line();

        /**
         * @brief Construtor da classe.
         * 
         */
        Line(Point p1, Point p2);

        /**
         * @brief Destrutor padrão da classe.
         * 
         */
        ~Line();

        /**
         * @brief Imprime a reta entre dois pontos.
         * 
         * @return * void 
         */
        void displayLine();
};

#endif