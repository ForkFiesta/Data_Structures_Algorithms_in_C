#include <stdio.h>
#include <assert.h>
#include "queue.h"
#include "tests.h"

void test_initialize_queue() {
    Queue *q = initialize_list();
    assert(q != NULL);
    assert(isEmpty(q) == true);
    free(q);
}

void test_enqueue() {
    Queue *q = initialize_list();
    enqueue(q, 10);
    assert(isEmpty(q) == false);
    assert(q->head->data == 10);
    assert(q->tail->data == 10);
    
    enqueue(q, 20);
    assert(q->head->data == 10);
    assert(q->tail->data == 20);
    assert(q->head->next->data == 20);
    
    destroy_list(q);
    free(q);
}

void test_is_empty() {
    Queue *q = initialize_list();
    assert(isEmpty(q) == true);
    
    enqueue(q, 10);
    assert(isEmpty(q) == false);
    
    dequeue(q);
    assert(isEmpty(q) == true);
    destroy_list(q);
    
    free(q);
}

void run_tests() {
    test_initialize_list();
    test_enqueue();
    test_is_empty();
    printf("All tests passed!\n");
}

