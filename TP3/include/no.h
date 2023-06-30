#ifndef NO_H
#define NO_H

class No {
    // O no 'proximo' é usado apenas na lista ordenada.
    // Os nos 'left' e 'right' são usados para montar a árvore a partir da lista ordenada.
    private:
        unsigned char character;
        int frequence;
        No *left, *right, *proximo;
    
    public:
        No();

        int getFrequence();
        unsigned char getCharacter();
        No *getProximo();
        No *getLeft();
        No *getRight();

        void setFrequence(int f);
        void setCharacter(unsigned char c);
        void setProximo(No *no);
        void setLeft(No *no);
        void setRight(No *no);

        static int treeHeight(No *raiz);
};

#endif