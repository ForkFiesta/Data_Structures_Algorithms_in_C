#include "tests.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


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
