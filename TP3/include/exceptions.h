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

class falhaAoAbrirArquivoDeEntrada : public exception {
    public:
        const char *what() const throw()
        {
            return "Não foi possível abrir o arquivo de entrada na função main durante a compactação!";
        }
};

class falhaAoAbrirArquivoAuxiliar : public exception {
    public:
        const char *what() const throw()
        {
            return "Não foi possível abrir o arquivo auxiliar na função main durante a descompactação!";
        }
};

class arquivoNaoEncontradoNaEntrada : public exception {
    public:
        const char *what() const throw()
        {
            return "Não foi possível abrir o arquivo desejado! Arquivo onde ocorreu o erro: entry.cpp";
        }
};

class arquivoNaoEncontradoNaCompressao : public exception {
    public:
        const char *what() const throw()
        {
            return "Não foi possível abrir o arquivo desejado! Arquivo onde ocorreu o erro: compress.cpp";
        }
};

class erroAoAlocarMemoriaNaLista : public exception {
    public:
        const char *what() const throw()
        {
            return "Erro ao alocar memória de um nó para preencher a lista encadeada! Método: fillList()";
        }
};

class erroAoAlocarMemoriaNaArvore : public exception {
    public:
        const char *what() const throw()
        {
            return "Não foi possível alocar memória para o novo nó ao construir a árvore! Método: buildTree()";
        }
};

#endif