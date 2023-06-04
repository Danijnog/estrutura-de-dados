#include "../include/convexHull.h"
#include "../include/exceptions.h"
#include "graphics.h"
#include "point.h"

ConvexHull::ConvexHull() {};

ConvexHull::~ConvexHull() {};

ConvexHull::ConvexHull(Line l1, Line l2) {
    this->l1 = l1;
    this->l2 = l2;
}

void ConvexHull::displayConvexHull(Stack stack) {
    cout << "FECHO CONVEXO" << endl;
    for(int i = 0; i < stack.getSize(); i++)
        cout << "(" << stack.getPoint(i).getX() << " " << stack.getPoint(i).getY() << ")" << endl;
}

int ConvexHull::validateDrawConvexHull(Stack stack, Point p0) {
    // Valores definidos com base no limite da janela que é aberta com o graphics.h
    int xMax = 530;
    int yMax = 480;
    if(p0.getX() > xMax || p0.getX() < 0)
        throw coordenadaXInvalida();
    if(p0.getY() > yMax || p0.getY() < 0)
        throw coordenadaYInvalida();
    
    while(!stack.emptyStack())
    {
        Point p = stack.pop();
        if(p.getX() > xMax || p.getX() < 0)
            throw coordenadaXInvalida();
        if(p.getY() > yMax || p.getY() < 0)
            throw coordenadaYInvalida();
    }
    return 1;
}

void ConvexHull::drawConvexHull(Stack stack, Point p0) {
    int gd = DETECT, gm;

    if(validateDrawConvexHull(stack, p0))
    {
        initgraph(&gd, &gm, NULL);
        setbkcolor(BLACK);
        setcolor(LIGHTBLUE);
    
        // Mover para o primeiro ponto
        moveto(p0.getX(), p0.getY());
        
        // Desenhar linhas entre os pontos
        while(!stack.emptyStack())
        {
            Point p = stack.pop();        
            lineto(p.getX(), p.getY());
        }

        // Fechar a figura
        lineto(p0.getX(), p0.getY());

        delay(5000);
        closegraph();
    }
}