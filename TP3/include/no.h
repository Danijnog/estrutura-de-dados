#ifndef NO_H
#define NO_H

class No {
    private:
        unsigned char character; // Deve ser unsigned pois irá pegar apenas os valores positivos de char na tabela ASC (0 a 255)
        int frequence;
        No *left, *right, *next; // No 'next': usado apenas na lista ordenada.
                                    // No 'left' e 'right': usados para montar a árvore a partir da lista ordenada.
    public:
        /**
         * @brief Construtor padrão da classe.
         * 
         */
        No();
        
        /**
         * @brief Retorna a altura da árvore.
         * 
         * @param root
         * @return * int 
         */
        static int treeHeight(No *root);

        /**
         * @brief Retorna a frequência de um nó.
         * 
         * @return * int 
         */
        int getFrequence();

        /**
         * @brief Retorna o caracter de um nó.
         * 
         * @return * unsigned char 
         */
        unsigned char getCharacter();

        /**
         * @brief Retorna o próximo nó.
         * 
         * @return * No* 
         */
        No *getNextNo();

        /**
         * @brief Retorna o nó a esquerda.
         * 
         * @return * No* 
         */
        No *getLeftNo();

        /**
         * @brief Retorna o nó a direita.
         * 
         * @return * No* 
         */
        No *getRightNo();

        /**
         * @brief Define a frequência de um nó.
         * 
         * @param f 
         * @return * void 
         */
        void setFrequence(int f);

        /**
         * @brief Define o caracter de um nó.
         * 
         * @param c 
         * @return * void 
         */
        void setCharacter(unsigned char c);

        /**
         * @brief Define o próximo nó de um nó.
         * 
         * @param no 
         * @return * void 
         */
        void setNextNo(No *no);

        /**
         * @brief Define o nó a esquerda de um nó.
         * 
         * @param no 
         * @return * void 
         */
        void setLeftNo(No *no);

        /**
         * @brief Define o nó a direita de um nó.
         * 
         * @param no 
         * @return * void 
         */
        void setRightNo(No *no);
};

#endif