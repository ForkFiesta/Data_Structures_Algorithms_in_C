#ifndef QUEUE_H
#define QUEUE_H
#include <stdbool.h>


typedef struct Node{
    struct Node *next;
    int data;
}Node;

typedef struct Queue{
    Node *front;
    Node *end;
}Queue;

Node *create_node(int data);

Queue *initialize_queue();

void enqueue(Queue *queue, int data);

int dequeue(Queue *queue);

int peek(Queue *queue);

bool isEmpty(Queue *queue);


void destroy_queue(Queue *queue);




#endif