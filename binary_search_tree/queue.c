#include "bst.h"
#include "queue.h"
#include <stdlib.h>
#include <stdio.h>




// Utility to create an empty queue
Queue* createQueue(){
    Queue *queue = malloc(sizeof(Queue));
    if(queue == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(Queue *queue, BSTNode *bstnode){
    QueueNode* queue_node = malloc(sizeof(QueueNode));
    if(queue_node == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    queue_node->node = bstnode;
    queue_node->next = NULL;
    if(queue->rear == NULL){
        queue->front = queue->rear = queue_node;
        return;
    }

    queue->rear->next = queue_node;
    queue->rear = queue_node;

}

BSTNode* dequeue(Queue *queue){
    if(queue->front == NULL) return NULL;
    QueueNode* temp = queue->front;
    BSTNode* node = temp->node;
    queue->front = queue->front->next;
    if(queue->front == NULL) queue->rear = NULL;
    free(temp);
    return node;


}

