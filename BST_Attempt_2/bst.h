#ifndef BST_H
#define BST_H
#include <stdbool.h>

typedef struct BSTNode {
    struct BSTNode *left;
    struct BSTNode *right;
    int data;
} BSTNode;

// A superior data type to hold the root node
typedef struct BinarySearchTree {
    BSTNode *root;
} BinarySearchTree;

BinarySearchTree *create_tree();
BSTNode *create_node(int data);
void insert(BinarySearchTree *tree, int data);
bool search(BinarySearchTree *tree, int target);
int findMin(BinarySearchTree *tree);
int findMax(BinarySearchTree *tree);
int findHeight(BinarySearchTree *tree);
void BFSTraversal(BinarySearchTree *tree);
void DFS_PreOrder(BinarySearchTree *tree);
void DFS_InOrder(BinarySearchTree *tree);
void DFS_PostOrder(BinarySearchTree *tree);
bool isBinarySearchTree(BinarySearchTree *tree);
void delete(BinarySearchTree *tree, int value);
void destroyTree(BinarySearchTree *tree);


BSTNode *findMinNode(BSTNode *node);




#endif
