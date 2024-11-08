#ifndef QUEUE_H
#define QUEUE_H


#include <stdbool.h>
#define ARRAY_SIZE 100

typedef struct Queue {
    int data[ARRAY_SIZE];
    int front;
    int back;
}Queue;

//initializes and returns a pointer to an empty queue (where front and back is -1)
Queue *intialize_queue();

//Returns true if bool is full
bool isFull(Queue *queue);

//Returns true if bool is empty 
bool isEmpty(Queue *queue);

//Adds value to queue
void enqueue(Queue *queue, int value);



//Dequeues item and returns that value
int dequeue(Queue *queue);

//returns item at front of queue without removing it
int peek(Queue *queue);




#endif