#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

// Classes de exceções que são usadas pelo programa para o tratamento de erros.

class entradaInvalida : public exception {
    public:
        const char *what() const throw()
        {
            return "Linha de comando inválida :(\n Execute o seguinte comando para menu de ajuda: 'bin/main -h'";
        }
};

#endif