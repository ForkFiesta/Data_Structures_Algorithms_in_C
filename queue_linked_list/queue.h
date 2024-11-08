#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "tests.h"

typedef struct Node {
    struct Node *next;
    int data;
} Node;

typedef struct Queue {
    Node *head;
    Node *tail;
} Queue;

Node *create_node();
Queue *initialize_list();
bool isEmpty(Queue *q);
void destroy_list(Queue *q);

#endif // QUEUE_H