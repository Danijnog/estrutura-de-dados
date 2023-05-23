#include "../include/caminha.h"

/* Visita recursivamente o nó, o filho da esquerda e o filho da direita*/
long caminhamentoPreOrdem(TipoApontador *T) { 
    if((*T) != NULL)
    {
        printf("%ld ", (*T)->Reg.Chave);
        caminhamentoPreOrdem(&(*T)->Esq);
        caminhamentoPreOrdem(&(*T)->Dir);
    }
    return 0;
}

/* Visita recursivamente o filho da esquerda, o da direita e por último o nó*/
long caminhamentoPosOrdem(TipoApontador *T) {
    if((*T) != NULL)
    {
        caminhamentoPosOrdem(&(*T)->Esq);
        caminhamentoPosOrdem(&(*T)->Dir);
        printf("%ld ", (*T)->Reg.Chave);
    }
    return 0;
}


/* Visita recursivamente o filho da esquerda, o nó e o filho da direita */
long caminhamentoInOrdem(TipoApontador *T) {
    if((*T) != NULL)
    {
        caminhamentoInOrdem(&(*T)->Esq);
        printf("%ld ", (*T)->Reg.Chave);
        caminhamentoInOrdem(&(*T)->Dir);
    }
    return 0;
}

int ancestral(int i, int j, TipoApontador *T, prm_t prm) {
    char armazenaPreOrdem[50] = " ";
    sprintf(armazenaPreOrdem, "%ld ", caminhamentoPreOrdem(T));

    char armazenaInOrdem[50] = " ";
    sprintf(armazenaInOrdem, "%ld ", caminhamentoInOrdem(T));

    char armazenaPosOrdem[50] = " ";
    sprintf(armazenaPosOrdem, "%ld ", caminhamentoPosOrdem(T));

    int k = 0;
    int n = 0;
    
    int tamPreOrdem = strlen(armazenaPreOrdem);

    if(armazenaPreOrdem[0] == i || armazenaInOrdem[0] == i || armazenaPosOrdem[0] == i) //Se for a raiz, i não é ancestral de ninguém
        return 0;
    
    else if(armazenaPreOrdem[prm.treesize] == i || armazenaInOrdem[prm.treesize] == i || armazenaPosOrdem[prm.treesize] == i) //Se for o nó folha, i não é ancestral de ninguem
        return 0;
    
    while(armazenaPreOrdem[k] != i) //Enquanto eu não encontrar o elemento "i" no vetor de preordem
    {
        k++;
    }

    while(armazenaPreOrdem[n] != j) //Enquanto eu não encontrar o elemento "j" no vetor de preordem
    {
        n++;
    }

    if(k >= n) //Se i estiver numa posição do vetor maior que j, (k >= n) então i não pode ser ancestral de j
        return 0;

    return 1;
}