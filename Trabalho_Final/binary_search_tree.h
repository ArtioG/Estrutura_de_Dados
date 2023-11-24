#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

struct TreeNode {
    int key;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int key);
struct TreeNode* insert(struct TreeNode* root, int key);
int search(struct TreeNode* root, int key);
struct TreeNode* removeNode(struct TreeNode* root, int key);
void inorderTraversal(struct TreeNode* root);
void preorderTraversal(struct TreeNode* root);
void postorderTraversal(struct TreeNode* root);
int findMinValue(struct TreeNode* root);
int findMaxValue(struct TreeNode* root);
void freeTree(struct TreeNode* root);

#endif