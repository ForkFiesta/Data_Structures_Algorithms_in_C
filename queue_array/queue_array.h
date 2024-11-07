#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H
#include <stdbool.h>

#define QUEUE_SIZE 16

/* Structure Definitions */
typedef struct Queue{
    int *data;
    int front;
    int back;


}Queue;
/* Prototypes */
Queue *initialize_queue();

void enqueue(Queue *qu, int data);
bool isFull(Queue *qu);
int dequeue(Queue *qu);
bool isEmpty(Queue *qu);
int front(Queue *qu);
int back(Queue *qu);

/* Tests */
void run_all_tests();
void test_enqueue();
void test_dequeue();
void test_front_back();

#endif