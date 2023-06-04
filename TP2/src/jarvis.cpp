#include "../include/jarvis.h"
#include "../include/stack.h"
#include "../include/exceptions.h"
#include <cstddef>

Jarvis::Jarvis() {}

Jarvis::~Jarvis() {}

int Jarvis::getMostLeftIndex(Point *points, int n) {
    int mostLeft = 0;
    for(int i = 0; i < n; i++)
        if(points[i].getX() < points[mostLeft].getX())
            mostLeft = i;

    return mostLeft;
}

Stack Jarvis::jarvisMarch(Point *points, int n) {
    Stack hull;

    // Verifica se o tamanho do array é válido
    if(n < 2)
        throw tamanhoArrayPontosInvalido();

    // Se no array de pontos só tiver pontos colineares, o fecho convexo é a linha que liga o primeiro e o último ponto
    if(Point::verifyCollinearPoints(points, n))
    {
        Stack stack = Stack();
        stack.push(points[0]);
        stack.push(points[n - 1]);
        return stack;
    }

    // Achar o ponto mais a esquerda na coordenada x
    int mostLeft = getMostLeftIndex(points, n);
    
    /* Começa pelo ponto mais a esquerda, e continua movendo no sentido
        anti-horário (counterclockwise) até encontrar o ponto de início. */
    int p = mostLeft;
    int q = 0;
    do 
    {
        hull.push(points[p]);

        q = (p + 1) % n;
        for(int i = 0; i < n; i++)
        {
            // Se 'i' é mais anti-horário que 'q', então atualiza o 'q'
            if(Point::orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        /* Agora 'q' é o mais anti-horário em respeito a p
        Seta 'p' igual a 'q' na próxima iteração, para que 'q' seja adicionado no resultado 'hull' */
        p = q;

    } while(p != mostLeft);
    return hull;
}
