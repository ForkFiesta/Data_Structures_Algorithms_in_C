#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

Node *create_node(int data){
    Node *node = malloc(sizeof(Node));
    if(!node){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}


Queue *initialize_queue(){
    Queue *queue = malloc(sizeof(Queue));
    if(!queue){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    queue->end=NULL;
    queue->front=NULL;
    return queue;
}


void enqueue(Queue *queue, int data){
    Node *new_node = create_node(data);
    if(isEmpty(queue)){
        queue->front = queue->end = new_node;
        return;
    }

    queue->end->next = new_node;
    queue->end = new_node;
}

bool isEmpty(Queue *queue){
    return (queue->front == NULL);
}


int dequeue(Queue *queue){

    if(isEmpty(queue)){
        fprintf(stderr, "Cannot dequeue empty list.\n");
        return -1;
    }
    
    int value = queue->front->data;
    if(queue->front == queue->end){
        free(queue->front);
        queue->front = queue->end = NULL;
    }else{
        Node *temp = queue->front->next;
        free(queue->front);
        queue->front = temp;
    }
    return value;
}

int peek(Queue *queue){
    if(isEmpty(queue)){
        fprintf(stderr, "Queue is empty\n");
        return -1;
    }

    return queue->front->data;
}

void destroy_queue(Queue *queue){
    Node *p = queue->front;
    while(p){
        Node *t = p->next;
        free(p);
        p = t;
    }
    queue->end = queue->front = NULL;
}



