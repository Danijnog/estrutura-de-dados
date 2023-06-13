#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

// Classes de exceções que são usadas pelo programa para o tratamento de erros.

class tamanhoArrayPontosInvalido : public exception {
    public:
        const char *what() const throw()
        {
            return "Tamanho do array de pontos inválido! O tamanho deve ser maior ou igual a 2.";
        }
};

class erroAoAbrirArquivo : public exception {
    public:
        const char *what() const throw()
        {
            return "Erro ao abrir o arquivo!";
        }
};

class coordenadaXInvalida : public exception {
    public:
        const char *what() const throw()
        {
            return "Coordenada x inválida, não foi possível desenhar o fecho convexo. Valores válidos: de 0 a 630.";
        }
};

class coordenadaYInvalida : public exception {
    public:
        const char *what() const throw()
        {
            return "Coordenada y inválida, não foi possível desenhar o fecho convexo. Valores válidos: de 0 a 480.";
        }
};

class entradaInvalida : public exception {
    public:
        const char *what() const throw()
        {
            return "Entrada inválida :(\n Exemplo de entrada: 'bin/fecho nome_do_arquivo.in', contanto que o arquivo esteja no mesmo diretório\n Se quiser desenhar o fecho convexo, utilize a flag -d como adicional na entrada: Exemplo: 'bin/fecho nome_do_arquivo.in -d' ";
        }
};

class pilhaVazia : public exception {
    public:
        const char *what() const throw()
        {
            return "A pilha está vazia!";
        }
};

class pilhaCheia : public exception {
    public:
        const char *what() const throw()
        {
            return "A pilha está cheia!";
        }
};

class indicePilhaInvalido : public exception {
    public:
        const char *what() const throw()
        {
            return "O índice está fora do intervalo da pilha!";
        }
};

#endif