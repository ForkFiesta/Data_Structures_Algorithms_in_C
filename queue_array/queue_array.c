#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
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

void run_all_tests(){
    test_enqueue();
    test_dequeue();
    test_front_back();


}

void test_enqueue(){
    Queue *qu = initialize_queue();
    enqueue(qu, 2);
    assert(front(qu)==2 && back(qu) == 2);
    free(qu->data);
    free(qu);
    printf("Test Enqueu passed.\n");
}

void test_dequeue(){
    Queue *qu = initialize_queue();
    enqueue(qu, 2);
    enqueue(qu, 7);
    enqueue(qu, 9);
    enqueue(qu, 4);
    assert(dequeue(qu)==2);
    assert(dequeue(qu)==7);
    assert(dequeue(qu)==9);
    assert(dequeue(qu)==4);
    free(qu->data);
    free(qu);
    printf("Test dequeu passed.\n");    
}


void test_front_back(){
    Queue *qu = initialize_queue();
    enqueue(qu, 2);
    enqueue(qu, 7);
    enqueue(qu, 9);
    enqueue(qu, 4);
    assert(front(qu) == 2 && back(qu) == 4);
    free(qu->data);
    free(qu);
    printf("Test front back peek passed.\n");
}

int main(){
    run_all_tests();
    return 0;

    
}


