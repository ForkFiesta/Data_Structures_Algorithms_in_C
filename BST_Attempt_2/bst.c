#include "bst.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Unique Prototypes */
static void DFS_PreOrder_Recursive(BSTNode *node);
static BSTNode *insert_recursive(BSTNode *root, int data);
static bool recursive_search(BSTNode *node, int target);
static int findHeightRecursive(BSTNode *node);
static BSTNode *delete_recursive(BSTNode *root, int value);
static void DFS_PreOrder_Recursive(BSTNode *node);
static void DFS_InOrder_Recursive(BSTNode *node);
static void DFS_PostOrder_Recursive(BSTNode *node);
static bool isBinarySearchTree_Recursive(BSTNode *node, int min, int max);
static void destroyTree_Recursive(BSTNode *node);
static int max(int num1, int num2);

BinarySearchTree *create_tree(){
    BinarySearchTree *tree = malloc(sizeof(BinarySearchTree));
    if(tree == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    tree->root = NULL;
    return tree;
}

BSTNode *create_node(int data){
    BSTNode *node = malloc(sizeof(BSTNode));
    if(node == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(BinarySearchTree *tree, int data){
    tree->root = insert_recursive(tree->root, data);
}

// Helper function for recursive insertion
static BSTNode *insert_recursive(BSTNode *root, int data) {
    if (root == NULL) return create_node(data);
    if (data < root->data)
        root->left = insert_recursive(root->left, data);
    else
        root->right = insert_recursive(root->right, data);
    return root;
}


void delete(BinarySearchTree *tree, int value) {
    tree->root = delete_recursive(tree->root, value);
}
//Help function for recursive deletion
static BSTNode *delete_recursive(BSTNode *root, int value) {
    if (root == NULL) return NULL;
    if (value < root->data)
        root->left = delete_recursive(root->left, value);
    else if (value > root->data)
        root->right = delete_recursive(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        }
        else {
            BSTNode *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = delete_recursive(root->right, temp->data);
        }
    }
    return root;
}

bool search(BinarySearchTree *tree, int target){
    return recursive_search(tree->root, target);

}

static bool recursive_search(BSTNode *node, int target){
    if (node==NULL) return false;
    if (target == node->data) return true;
    else if (target < node->data) return recursive_search(node->left, target);
    else return recursive_search(node->right, target);
}

int findMin(BinarySearchTree *tree){
    if(tree->root == NULL){
        fprintf(stderr, "Error: Tree is empty.\n");
        return -1;
    }
    BSTNode *temp = tree->root;
    while(temp->left){
        temp = temp->left;
    }
    return temp->data;
}

BSTNode *findMinNode(BSTNode *node){
    if(node == NULL){
        fprintf(stderr, "Error: no node passed.\n");
        return NULL;
    }
    BSTNode *temp = node;
    while(temp->left) temp = temp->left;
    return temp;
}

int findMax(BinarySearchTree *tree){
    if(tree->root == NULL){
        fprintf(stderr, "Error: Tree is empty.\n");
        return -1;
    }
    BSTNode *temp = tree->root;
    while(temp->right){
        temp = temp->right;
    }
    return temp->data;
}

int findHeight(BinarySearchTree *tree){
    return findHeightRecursive(tree->root);
}
static int findHeightRecursive(BSTNode *node){
    if (node == NULL) return -1;
    else return max(findHeightRecursive(node->left), findHeightRecursive(node->right))+1;
}

void BFSTraversal(BinarySearchTree *tree){
    if(tree == NULL){
        fprintf(stderr, "Tree is empty\n");
        return;
    }
    Queue *queue = createQueue();
    enqueue(queue, tree->root);

    while(queue->front != NULL){
        BSTNode *temp = dequeue(queue);
        printf("%d ", temp->data);

        if(temp->left != NULL) enqueue(queue, temp->left);
        if(temp->right != NULL) enqueue(queue, temp->right);

    }
    destroy_queue(queue);
    

}

void DFS_PreOrder(BinarySearchTree *tree){
    DFS_PreOrder_Recursive(tree->root);
}

static void DFS_PreOrder_Recursive(BSTNode *node){
    if(node == NULL) return;
    printf("%d ", node->data);
    DFS_PreOrder_Recursive(node->left);
    DFS_PreOrder_Recursive(node->right);
}


void DFS_InOrder(BinarySearchTree *tree){
    DFS_InOrder_Recursive(tree->root);
}

static void DFS_InOrder_Recursive(BSTNode *node){
    if(node == NULL) return;
    DFS_InOrder_Recursive(node->left);
    printf("%d ", node->data);
    DFS_InOrder_Recursive(node->right);
}

void DFS_PostOrder(BinarySearchTree *tree){
    DFS_PostOrder_Recursive(tree->root);
}

static void DFS_PostOrder_Recursive(BSTNode *node){

    if(node == NULL) return;
    DFS_PostOrder_Recursive(node->left);
    DFS_PostOrder_Recursive(node->right);
    printf("%d ", node->data);

}

bool isBinarySearchTree(BinarySearchTree *tree) {
    return isBinarySearchTree_Recursive(tree->root, INT_MIN, INT_MAX);
}


static bool isBinarySearchTree_Recursive(BSTNode *node, int min, int max) {
    if (node == NULL) return true;
    if (node->data <= min || node->data >= max) return false;
    return isBinarySearchTree_Recursive(node->left, min, node->data) &&
           isBinarySearchTree_Recursive(node->right, node->data, max);
}



void destroyTree(BinarySearchTree *tree){
    if(tree->root == NULL){
        fprintf(stderr,"No tree to destroy.\n");
        return;
    }
    destroyTree_Recursive(tree->root);
    free(tree);
}

static void destroyTree_Recursive(BSTNode *node){
    if(node == NULL) return;
    destroyTree_Recursive(node->left);
    destroyTree_Recursive(node->right);
    free(node);
}

static int max(int num1, int num2){
    if(num1 >= num2) return num1;
    else return num2;
}