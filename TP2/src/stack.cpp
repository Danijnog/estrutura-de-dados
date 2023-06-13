#include "../include/stack.h"
#include "exceptions.h"

Stack::Stack()  {
    top = -1;
    size = 0;
}

Stack::~Stack() {}

void Stack::push(Point item) {
    if(fullStack())
        throw pilhaCheia();
    
    top++;
    itens[top] = item;
    size++;
}

Point Stack::pop() {
    if(emptyStack())
        throw pilhaVazia();
    
    Point unstackedItem = itens[top];
    top--;
    size--;
    return unstackedItem;
}

void Stack::displayStack() {
    if(!emptyStack())
    {
        std::cout << "Pilha: \n";
        for(int i = size - 1; i >= 0; i--)
            std::cout << "(" << itens[i].getX() << " " << itens[i].getY() << ")" << std::endl;
    }
}

void Stack::clearStack() {
    top = -1;
    size = 0;
}

int Stack::emptyStack() {
    if(size == 0)
        return 1;
    return 0;
}

int Stack::fullStack() {
    if(size == STACK_SIZE)
        return 1;
    return 0;
}

int Stack::getSize() {
    return size;
}

Point Stack::getTop() {
    if(!emptyStack())
        return itens[top];
    throw pilhaVazia();
}

Point Stack::getPoint(int index) {
    if(index >= 0 && index < size)
        return itens[index];
    throw indicePilhaInvalido();
}

Point Stack::nextToTop(Stack &stack) {
    Point topPoint = stack.getTop();
    stack.pop();

    Point nextToTop = stack.getTop();
    stack.push(topPoint);

    return nextToTop;
}
