#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct BSTNode{
    struct BSTNode *left;
    struct BSTNode *right;
    int data;
}BSTNode;




BSTNode *initialize_root();
BSTNode *create_node();
void insert(BSTNode *root, int data);
bool search(BSTNode *root, int target);
int findMin(BSTNode *root);

BSTNode *findMinNode(BSTNode *root);

int findMax(BSTNode *root);
int findHeight(BSTNode *root);
int max(int num1, int num2);
void BFSTraversal(BSTNode *root);
void DFS_PreOrder(BSTNode *root);
void DFS_InOrder(BSTNode *root);
void DFS_PostOrder(BSTNode *root);

bool isSubTreeLesser(BSTNode *root, int value);
bool isSubTreeGreater(BSTNode *root, int value);
bool isBinarySearchTree(BSTNode *root);

BSTNode *delete(BSTNode *root, int value);
void destroyTree(BSTNode *root);
void check_null(void *ptr);

#endif