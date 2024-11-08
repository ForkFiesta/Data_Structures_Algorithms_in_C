#include <stdio.h>
#include <stdlib.h>
#include "queue.h"



Queue *intialize_queue(){
    Queue *queue = malloc(sizeof(Queue));
    queue->back = -1;
    queue->front = -1;
    return queue;
}


bool isFull(Queue *queue){
    return ((queue->back + 1) % ARRAY_SIZE == queue->front);
}


bool isEmpty(Queue *queue){
    return ((queue->front) == -1);
}

void enqueue(Queue *queue, int value){
    if(isFull(queue)){
        fprintf(stderr, "Cannot enqueue items to full queue\n");
        return;
    }
    if(isEmpty(queue)){
        queue->front = queue->back = 0;
        queue->data[queue->front] = value;
        return;
    }
    queue->back = (queue->back + 1) % ARRAY_SIZE;
    queue->data[queue->back] = value;
}




int dequeue(Queue *queue){
    if(isEmpty(queue)){
        fprintf(stderr, "Cannot dequeue from empty queue\n");
        return -1;
    }
    int value = queue->data[queue->front];
    if(queue->front == queue->back){
        value = queue->data[queue->front];
        queue->front = queue->back = -1;
        return value;
    }
    else{
        queue->front = (queue -> front + 1) % ARRAY_SIZE;

    }
    return value;
}

int peek(Queue *queue){
    if(isEmpty(queue)){
        fprintf(stderr, "List is empty.\n");
        return -1;
    }else{
        return queue->data[queue->front];
    }
}

