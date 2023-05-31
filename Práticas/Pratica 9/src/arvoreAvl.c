#include "../include/arvoreAvl.h"

/*---------------------------------------------------------------------
 Arquivo	: arvoreAvl.c
 Conteudo	: implementação dos métodos de uma árvore AVL que foi modificada com o objetivo de
 realizar o balanceamento por peso dos nós das subárvores esquerda e direita referente a um nó raiz.
 Autor	    : Daniel Nogueira Junqueira (danijnog@ufmg.br)
 Historico	: 2023-05-31 - arquivo criado
--------------------------------------------------- */

node * insert(node * T, int x, stat_t * st) {
  if (T == NULL) {
    T = (node * ) malloc(sizeof(node));
    T -> data = x;
    T -> left = NULL;
    T -> right = NULL;
    T->weight = 1;
  } else
  if (x > T -> data) // insert in right subtree
  {
    T -> right = insert(T -> right, x, st);
    // Pesos
    if(T->left != NULL && T->right != NULL)
      T->weight = 1 + T->left->weight + T->right->weight;
    
    else if(T->left != NULL)
        T->weight = 1 + T->left->weight;
    
    else if(T->right != NULL)
        T->weight = 1 + T->right->weight;
    
    else  
        T->weight = 1;

    if (BF(T) == -2){ // Arvore pendendo para a direita (BF negativo)
      if (x > T -> right -> data){
        T = RR(T); // Rotaciona para a esquerda
	st->RR++;
      } else{
        T = RL(T);
	st->RL++;
      }
    }
  } else
  if (x < T -> data) {
    T -> left = insert(T -> left, x, st);
    // Pesos
    if(T->right != NULL && T->left != NULL)
      T->weight = 1 + T->left->weight + T->right->weight;

    else if(T->left != NULL)
      T->weight = 1 + T->left->weight;
    
    else if(T->right != NULL)
        T->weight = 1 + T->right->weight;
    
    else
        T->weight = 1;
    
    if (BF(T) == 2){ // Arvore pendendo para a esquerda (BF positivo)
      if (x < T -> left -> data){
        T = LL(T); // Rotaciona para a direita
	st->LL++;
      }else{
        T = LR(T);
	st->LR++;
      }
    }
  }
    T -> weight = weight(T);
  return (T);
}

node * Delete(node * T, int x, stat_t * st) {
  node * p;
  if (T == NULL) {
    return NULL;
  } else
  if (x > T -> data) // insert in right subtree
  {

    T -> right = Delete(T -> right, x, st);
    // Pesos
    if(T->right != NULL && T->left != NULL)
      T->weight = 1 + T->right->weight + T->left->weight;
    
    else if(T->right != NULL)
      T->weight = 1 + T->right->weight;
    
    else if(T->left != NULL)
      T->weight = 1 + T->left->weight;
    
    else
      T->weight = 1;

    if (BF(T) == 2){
      if (BF(T -> left) >= 0){
        T = LL(T);
	st->LL++;
      }
      else{
        T = LR(T);
	st->LR++;
      }
    }
  } else
  if (x < T -> data) {
    T -> left = Delete(T -> left, x, st);
    // Pesos
    if(T->left != NULL && T->right != NULL)
      T->weight = 1 + T->left->weight + T->right->weight;
    
    else if(T->left != NULL)
      T->weight = 1 + T->left->weight;
    
    else if(T->right != NULL)
      T->weight = 1 + T->right->weight;
    
    else
      T->weight = 1;

    if (BF(T) == -2){ //Rebalance during windup
      if (BF(T -> right) <= 0){
        T = RR(T);
	st->RR++;
      }
      else{
        T = RL(T);
	st->RL++;
      }
    }
  } else {
    //data to be deleted is found
    if (T -> right != NULL) { //delete its inorder succesor
      p = T -> right;
      while (p -> left != NULL)
        p = p -> left;
      T -> data = p -> data;
      T -> right = Delete(T -> right, p -> data, st);
      if (BF(T) == 2){ //Rebalance during windup
        if (BF(T -> left) >= 0){
          T = LL(T);
	  st->LL++;
	}
        else{
          T = LR(T);\
	  st->LR++;
	}
      }
    } else
      return (T -> left);
  }
    T -> weight = weight(T);
  return (T);
}

int height(node * T) {
  int lh, rh;
  if (T == NULL)
    return (0);
  if (T -> left == NULL)
    lh = 0;
  else
    lh = 1 + T -> left -> ht;
  if (T -> right == NULL)
    rh = 0;
  else
    rh = 1 + T -> right -> ht;
  if (lh > rh)
    return (lh);
  return (rh);
}

int weight(node *T) {
    int leftWeight, rightWeight;
    if(T == NULL)
        return 0;
    
    if(T->left == NULL)
        leftWeight = 0;
    
    else
        leftWeight = 1 + T->left->weight;
    
    if(T->right == NULL)
        rightWeight = 0;
    
    else
        rightWeight = 1 + T->right->weight;
    
    int result = leftWeight - rightWeight;
    if(result >= 0)
        return leftWeight;

    return rightWeight;
}

node * rotateright(node * x) {
  node * y;
  y = x -> left;
  x -> left = y -> right;
  y -> right = x;

  // Atualizar o peso dos nós
  x->weight = 1 + (x->left ? x->left->weight : 0) + (x->right? x->right->weight : 0);
  y->weight = 1 + (y->left ? y->left->weight : 0) + x->weight;
  return (y);
}

node * rotateleft(node * x) {
  node * y;
  y = x -> right;
  x -> right = y -> left;
  y -> left = x;

  // Atualizar o peso dos nós
  x->weight = 1 + (x->left ? x->left->weight : 0) + (x->right ? x->right->weight : 0);
  y->weight = 1 + (y->right ? y->right->weight : 0) + x->weight;
  return (y);
}

node * RR(node * T) {
  T = rotateleft(T);
  return (T);
}

node * LL(node * T) {
  T = rotateright(T);
  return (T);
}

node * LR(node * T) { // Rotação dupla esquerda direita
  T -> left = rotateleft(T -> left);
  T = rotateright(T);
  return (T);
}

node * RL(node * T) { // Rotação dupla direita esquerda
  T -> right = rotateright(T -> right);
  T = rotateleft(T);
  return (T);
}
 
int BF(node * T) { // Calcula o fator de balanceamento com base no peso da árvore
  int leftWeight, rightWeight;
  if (T == NULL)
    return (0);

  if (T -> left == NULL)
    leftWeight = 0;
  else
    leftWeight = T -> left -> weight;

  if (T -> right == NULL)
    rightWeight = 0;
  else
    rightWeight = T -> right -> weight;

  return (leftWeight - rightWeight);
}

void preorder(node * T) {
  if (T != NULL) {
    printf("%d(Fator de balanceamento (BF)=%d)\n", T -> data, BF(T));
    preorder(T -> left);
    preorder(T -> right);
  }
}

void inorder(node * T) {
  if (T != NULL) {
    inorder(T -> left);
    printf("%d(Fator de balanceamento (BF)=%d)\n", T -> data, BF(T));
    inorder(T -> right);
  }
}

void dump(node * T, int level,char * pref) {
  if (T != NULL) {
    printf("%s ",pref);
    for(int i=0; i<level; i++) printf("    ");
    printf("%3d (Fator de balanceamento (BF)=%d, Peso=%d)\n", T -> data, BF(T),T->weight);
    dump(T -> left,level+1,pref);
    dump(T -> right,level+1,pref);
  }
}
