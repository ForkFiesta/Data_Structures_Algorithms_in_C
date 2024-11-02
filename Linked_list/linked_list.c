#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



void test_initalize_list(){
    list *test = initialize_list();
    assert(test != NULL && test->head == NULL && test->size==0);
    destroy_list(test);

}

void test_push(){
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(test->size==7 && test->head->data==55 && test->head->next->data == 12);
    destroy_list(test);
}

void test_pop(){
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(pop(test)==55);
    destroy_list(test);

}

void test_search(){
    
}