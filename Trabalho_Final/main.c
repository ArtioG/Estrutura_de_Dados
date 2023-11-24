#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

int main() {
    struct TreeNode* root = NULL;

    // Teste de inserção
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Teste de busca
    int searchKey = 40;
    if (search(root, searchKey)) {
        printf("%d encontrado na arvore.\n", searchKey);
    } else {
        printf("%d nao encontrado na arvore.\n", searchKey);
    }

    // Teste de remoção
    int removeKey = 30;
    root = removeNode(root, removeKey);

    // Teste de busca após remoção
    if (search(root, removeKey)) {
        printf("%d encontrado na arvore.\n", removeKey);
    } else {
        printf("%d nao encontrado na arvore.\n", removeKey);
    }

    // Teste de percursos na árvore
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorderTraversal(root);
    printf("\n");

    // Teste de mínimo e máximo
    printf("Valor minimo na arvore: %d\n", findMinValue(root));
    printf("Valor maximo na arvore: %d\n", findMaxValue(root));

    // Libera a memória alocada para os nós da árvore
    freeTree(root);

    return 0;
}