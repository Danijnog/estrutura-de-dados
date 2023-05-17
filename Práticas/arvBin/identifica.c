#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Definição da estrutura de um nó da árvore
struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Cria um novo nó da árvore
struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para verificar se o caractere é um operador
int isOperator(char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return 1;
    return 0;
}

// Função para construir a árvore de expressão a partir da expressão infixa
struct TreeNode* buildExpressionTree(char infix[], int start, int end) {
    if (start > end)
        return NULL;

    struct TreeNode* newNode = NULL;
    int parenthesesCount = 0;
    int index = -1;
    int i;

    // Procura pelo operador com a menor precedência dentro do intervalo [start, end]
    for (i = end; i >= start; i--) {
        if(infix[i] == ' ')
            continue;

        else if (infix[i] == ')')
            parenthesesCount++;
        else if (infix[i] == '(')
            parenthesesCount--;
        else if (parenthesesCount == 0 && isOperator(infix[i])) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // Se não há operadores dentro do intervalo, então é um operando
        newNode = createNode(infix[start]);
        return newNode;
    }

    newNode = createNode(infix[index]);

    newNode->left = buildExpressionTree(infix, start, index - 1);
    newNode->right = buildExpressionTree(infix, index + 1, end);

    return newNode;
}

// Função para avaliar a árvore de expressão
float evaluateExpressionTree(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return root->data - '0';

    float leftValue = evaluateExpressionTree(root->left);
    float rightValue = evaluateExpressionTree(root->right);

    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
    }

    return 0;
}

int main() {
    char infixExpression[100];

    printf("Digite a expressao infixa: ");
    fgets(infixExpression, sizeof(infixExpression), stdin);

    // Remove o caractere de nova linha do final da expressão
    infixExpression[strlen(infixExpression) - 1] = '\0';

    struct TreeNode* root = buildExpressionTree(infixExpression, 0, strlen(infixExpression) - 1);

    printf("Resultado: %f\n", evaluateExpressionTree(root));

    return 0;
}
