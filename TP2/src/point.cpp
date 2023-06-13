#include "../include/point.h"
#include "../include/graham.h"

Point::Point() {}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

Point::~Point() {}

void Point::swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

int Point::orientation(Point p, Point q, Point r) {
    int value = (q.y - p.y) * (r.x - q.x) - // Esse calculo vem da simplificação de calcular a inclinação da reta (m)
                (q.x - p.x) * (r.y - q.y);

    if(value == 0) //colineares
        return 0;

    else if(value > 0) //sentido horário (clockwise)
        return 1;
    
    else //se value for negativo, é sentido anti-horário (counterclockwise)
        return 2;
}

double Point::computeAngle(Point p) {
    double X = p.getX();
    double Y = p.getY();

    double angle = atan2(Y, X); // Retorna o arco tangente do ângulo do eixo x da linha que está na origem (0,0) e os pontos passados como parâmetros na função

    return angle; // É retornado o valor em radianos
}

int Point::verifyCollinearPoints(Point *points, int n) {
    for(int i = 0; i < n; i++)
        if(points[i].getX() != points[i].getY())
            return 0;
            
    return 1;
}

int Point::getX() {
    return this->x;
}

int Point::getY() {
    return this->y;
}
