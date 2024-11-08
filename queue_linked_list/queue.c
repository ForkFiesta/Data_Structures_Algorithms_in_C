#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "queue.h"


Node *create_node(){
    Node *new_node = malloc(sizeof(Node));
    if(!new_node){
        fprintf(stderr, "Memory allocation memory.\n");
        exit(1);
    }

    return new_node;
}

Queue *initialize_list(){
    Queue *new_queue = malloc(sizeof(Queue));
    if(!new_queue){
        fprintf(stderr, "Memory allocation error.\n");
    }
    new_queue->head = NULL;
    new_queue->tail = NULL;

}

bool isEmpty(Queue *q){
    return(q->head == NULL && q->tail == NULL);
}

void enqueue(Queue *q, int value){
    Node *new_node = create_node();
    new_node->data = value;
    if(isEmpty(q)){
        new_node->next = NULL;
        q->head = q->tail = new_node;
    }
    q->tail->next = new_node;
    q->tail = new_node;
    
}

int dequeue(Queue *q){
    Node *temp = q->head;
    if(isEmpty(q)){
        fprintf(stderr, "Cannot dequeue emptly list.\n");
        return -1;
    }

    if(q->head == q->tail){ // checking to see there's one element
        q->head = q->tail = NULL;
    }
    else{
        q->head = q->head->next;
    }
    free(temp);

}

void destroy_list(Queue *q){
    Node *p = q->head;
    while(p){
        Node *t = p;
        p = p->next;
        free(t);
    }
    free(q->head);
    free(q->tail);
    
}