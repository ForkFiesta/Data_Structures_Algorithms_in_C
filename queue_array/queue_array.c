#include <stdlib.h>
#include <stdio.h>
#include "queue_array.h"


Queue *initialize_queue(){
    Queue *qu = malloc(sizeof(Queue));
    if(!qu){
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }
    qu->data = malloc(sizeof(int) * QUEUE_SIZE);
    if(!qu->data){
        free(qu);
        fprintf(stderr, "Error allocating memory.\n");
        exit(1);
    }
    qu->front = -1;
    qu->back = -1;

    return qu;
}

bool isFull(Queue *qu){
    if((qu->back+1) % QUEUE_SIZE == qu->front){
        return true;
    }else return false;

}

bool isEmpty(Queue *qu){
    if(qu->front == -1 && qu->back == -1) return true;
    else return false;
}

void enqueue(Queue *qu, int data){
    if(isFull(qu)){
        fprintf(stderr, "List is full. Cannot insert new items.\n");
        return;
    }
    else if(isEmpty(qu)){
        qu->front = qu->back = 0;
    }else {
        qu->back = qu->back + 1;
    }
    qu->data[qu->back] = data;
}

int dequeue(Queue *qu){
    if(isEmpty(qu)){
        fprintf(stderr, "list is empty. No items to dequeue\n");
        return -1;
    }
    int dequeued_value = front(qu);
    if(qu->front == qu->back){
        qu->front = qu->back = -1;
    }else{
        qu->front = (qu->front + 1) % QUEUE_SIZE;
    }
    return dequeued_value;
}

int front(Queue *qu){
    return qu->data[qu->front];
}

int back(Queue *qu){
    return qu->data[qu->back];
}



