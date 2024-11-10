#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tests.h"
#include "queue.h"



void run_all_tests(){
    printf("\033[1;33mRunning all tests...\033\n");
    test_initialize_queue();
    test_enqueue();
    test_dequeue();
    test_peek();
    test_destroy_queue();
    printf("\033[1;32mPassed All Tests\033[0m\n");
}


void test_initialize_queue(){
    printf("\033[0;33mTesting Initialize Queue...\033[0m");
    Queue *queue = initialize_queue();
    assert(queue->front == NULL);
    assert(queue->end == NULL);
    destroy_queue(queue);
    free(queue);
    printf("\033[0;32mPassed\033[0m\n");
}
void test_enqueue(){
    printf("\033[0;33mTesting Enqueue............\033[0m");
    Queue *queue = initialize_queue();
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 4);
    assert(queue->front->data==3);
    assert(queue->end->data==4);
    destroy_queue(queue);
    free(queue);
    printf("\033[0;32mPassed\033[0m\n");
}
void test_dequeue(){
    printf("\033[0;33mTesting Dequeue............\033[0m");
    Queue *queue = initialize_queue();
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 4);
    assert(dequeue(queue) == 3);
    assert(dequeue(queue) == 8);
    assert(dequeue(queue) == 4);
    free(queue);
    printf("\033[0;32mPassed\033[0m\n");
}


void test_peek(){
    printf("\033[0;33mTesting peek...............\033[0m");
    Queue *queue = initialize_queue();
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 4);
    assert(peek(queue) == 3);
    dequeue(queue);
    assert(peek(queue)== 8);
    free(queue);
    printf("\033[0;32mPassed\033[0m\n");
}

void test_destroy_queue(){
    printf("\033[0;33mTesting Destory Queue......\033[0m");
    Queue *queue = initialize_queue();
    enqueue(queue, 3);
    enqueue(queue, 8);
    enqueue(queue, 4);
    destroy_queue(queue);
    assert(queue->end == NULL && queue->front == NULL);
    printf("\033[0;32mPassed\033[0m\n");

}



