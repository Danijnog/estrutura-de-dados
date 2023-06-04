#include "../include/line.h"

Line::Line() {};

Line::~Line() {};

Line::Line(Point p1, Point p2) {
    this->p1 = p1;
    this->p2 = p2;
}

void Line::displayLine() {
    cout << "Reta: " << endl;
    cout << "(" << p1.getX() << " " << p1.getY() << ")" << "-->" << "(" << p2.getX() << " " <<  p2.getY() << ")" << endl;
}