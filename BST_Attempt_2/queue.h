#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include "bst.h"


typedef struct QueueNode {
    struct BSTNode* node;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
}Queue;

// Utility to create an empty queue
Queue* createQueue();

//enqueue a node to the queue
void enqueue(Queue *queue, BSTNode *bstnode);
//dequeue a node a node from the dequeue and return its value
BSTNode* dequeue(Queue *queue);
//destroys queue
void destroy_queue(Queue *queue);

#endif