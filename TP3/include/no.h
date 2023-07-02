#ifndef NO_H
#define NO_H

class No {
    // O no 'proximo' é usado apenas na lista ordenada.
    // Os nos 'left' e 'right' são usados para montar a árvore a partir da lista ordenada.
    private:
        unsigned char character; // Deve ser unsigned pois irá pegar apenas os valores positivos de char na tabela ASC (0 a 255)
        int frequence;
        No *left, *right, *proximo;
    
    public:
        No();

        int getFrequence();
        unsigned char getCharacter();
        No *getProximo();
        No *getLeftNo();
        No *getRightNo();

        void setFrequence(int f);
        void setCharacter(unsigned char c);
        void setProximo(No *no);
        void setLeftNo(No *no);
        void setRightNo(No *no);

        static int treeHeight(No *raiz);
};

#endif