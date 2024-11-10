#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst.h"
#include "queue.h"


BSTNode *create_node(){
    BSTNode *new_node = malloc(sizeof(BSTNode));
    if(new_node == NULL){
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }
    return new_node;
}


void insert(BSTNode *root, int data){
    BSTNode *new_node = create_node();
    if(new_node == NULL){
        fprintf(stderr, "error allocating memory.\n");
        exit(1);
    }
    new_node->data = data;
    if(root == NULL){
        new_node->left = NULL;
        new_node->right = NULL;
        root = new_node;
    }
    else if (new_node->data < root->data){
        insert(root->left, data);
    }else{
        insert(root->right, data);
    }
}
bool search(BSTNode *root, int target){
    if(root == NULL){
        fprintf(stderr,"No node passed into search\n");
        return false;
    }
    if(root->data == target) return true;
    else if (target < root->data) return search(root->left, target);
    else return search(root->right, target);
}
int findMin(BSTNode *root){
    if(!root){
        fprintf(stderr, "Cannot search empty list.\n");
        return -1;
    }
    BSTNode *curr = root;
    while(curr->left){
        curr = curr->left;
    }
    return curr->data;
}

BSTNode *findMinNode(BSTNode *root){
    if(root == NULL){
        fprintf(stderr, "Cannot search empty list.\n");
        return NULL;
    }
    BSTNode *curr = root;
    while(curr->left){
        curr= curr->left;
    }
    return curr;
}

int findMax(BSTNode *root){
    if(!root){
        fprintf(stderr, "Cannot search empty list.\n");
        return -1;
    }
    BSTNode *curr = root;
    while(curr->right){
        curr = curr->right;
    }
    return curr->data;
}

int findHeight(BSTNode *root){
    if (!root){
        return -1;
    }
    return max(findHeight(root->left), findHeight(root->right)) + 1;

}

int max(int num1, int num2){
    if(num1>num2){
        return num1;
    }else return num2;
}


void BFSTraversal(BSTNode *root){
    if (root == NULL){
        fprintf(stderr, "No data in root\n");
        exit(1);
    }
    Queue *q = createQueue();
    enqueue(q, root);
    while(q->front != NULL){
        BSTNode *node = dequeue(q);
        printf("%d ", node->data);

        if(node->left != NULL) enqueue(q, node->left);
        if(node->right != NULL) enqueue(q,node->right);
    }

    free(q);
}


void DFS_PreOrder(BSTNode *root){
    if(root == NULL) return;
    printf("%d ", root->data);
    DFS_PreOrder(root->left);
    DFS_PreOrder(root->left);
}

void DFS_InOrder(BSTNode *root){
    if (root == NULL) return;
    DFS_InOrder(root->left);
    printf("%d ", root->data);
    DFS_InOrder(root->right);
}

void DFS_PostOrder(BSTNode *root){
    if (root == NULL) return;
    DFS_PostOrder(root->left);
    DFS_PostOrder(root->right);
    printf("%d ", root->data);
}


bool isSubTreeLesser(BSTNode *root, int value){
    if(root == NULL) return true;
    if(root->data <= value && isSubTreeLesser(root->left, value) && isSubTreeLesser(root->right, value)) return true;
    else return false;
}

bool isSubTreeGreater(BSTNode *root, int value){
    if(root == NULL) return true;
    if(root->data >= value 
    && isSubTreeGreater(root->left, value) 
    && isSubTreeGreater(root->right, value))
        return true;  
     
    else
        return false;
    
}

bool isBinarySearchTree(BSTNode *root){
    if(root == NULL) return true;
    if(isSubTreeLesser(root->left, root->data) 
    && isSubTreeGreater(root->right, root->data) 
    && isBinarySearchTree(root->left) 
    && isBinarySearchTree(root->right))
        return true;
    else
        return false;
}
    

BSTNode *delete(BSTNode *root, int value){
    if(root == NULL) return root;
    else if (value < root->data) root->left = delete(root->left, value);
    else if (value > root->data) root->right = delete(root->right, value);
    else{
        /* Item is found. Now check for children */
        //case 1: no child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        else if(root->left == NULL){
            BSTNode *temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL){
            BSTNode *temp = root;
            root = root->left;
            free(temp);
        }else{
            BSTNode *temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);

        }
    }
    return root;
}

void destroyTree(BSTNode *root){
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}



