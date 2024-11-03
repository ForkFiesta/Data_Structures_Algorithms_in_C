#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"
#include <assert.h>
#include <stdio.h>


list *initialize_list(){
    list *lst = malloc(sizeof(list));

    if(lst == NULL){
        exit(EXIT_FAILURE);
    }

    lst->head = malloc(sizeof(node));

    if(lst->head == NULL){
        free(lst);
        exit(EXIT_FAILURE);
    }

    lst->tail = malloc(sizeof(node));

    if(lst->tail == NULL){
        free(lst->head);
        free(lst);
        exit(EXIT_FAILURE);
    }

    lst->head->prev = NULL;
    lst->head->next = lst->tail;
    lst->tail->prev = lst->head;
    lst->tail->next = NULL;

    return lst;



}

void destroy_list(list *lst){
    node *p = lst->head->next;
    while(p != lst->tail){
        node *t = p;
        p = t->next;
        free(t);
    }

    free(lst->head);
    free(lst->tail);
    

    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
}

void pushFront(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data=value;

    new_node->next = lst->head->next;
    new_node->prev = lst->head;
    lst->head->next->prev = new_node;
    lst->head->next = new_node;
}


void pushBack(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = value;
    new_node->prev = lst->tail->prev;
    new_node->next = lst->tail;

    lst->tail->prev->next = new_node;
    lst->tail->prev = new_node;
}

int popback(list *lst){
    if(lst->head->next == lst->tail){
        printf("Cannot pop from empty list.\n");
        return -1;
    }

    int popped_value;

    node *p = lst->tail->prev;
    p->prev->next = lst->tail;

    lst->tail->prev = p->prev;
    popped_value = p->data;

    free(p);

    return popped_value;
}




/* Tests */
void run_all_tests(){
    printf("\033[0;33mCommencing Tests...\033[0m\n");
    test_initialize_list();
    test_destroy_list();
    test_pushFront();
    test_pushBack();
    test_popBack();
    printf("\033[1;32mPassed All Tests\033[0m\n");
}

void test_initialize_list(){
    printf("\033[0;33mTesting Initialize List ..... \033[0m");
    list *test = initialize_list();
    assert(test != NULL && test->head!= NULL && test->tail != NULL && test->size == 0);
    free(test->head);
    free(test->tail);
    free(test);
    printf("\033[0;32mPassed.\033[0m\n");
}

void test_destroy_list(){
    printf("\033[0;33mTesting Destroy List ........ \033[0m");
    list *test = initialize_list();
    assert(test != NULL && test->head!= NULL && test->tail != NULL && test->size == 0);
    destroy_list(test);
    assert(test->head == NULL && test->tail == NULL && test->size == 0);
    free(test);

    printf("\033[0;32mPassed.\033[0m\n");

}

void test_pushFront(){
    printf("\033[0;33mTesting Push Front .......... \033[0m");
    list *test = initialize_list();
    pushFront(test, 4);
    pushFront(test, 6);
    pushFront(test, 7);
    pushFront(test, 3);
    assert(test->head->next->data == 3 && test->tail->prev->data == 4);
    destroy_list(test);
    free(test);
    printf("\033[0;32mPassed.\033[0m\n");


}

void test_pushBack(){
    printf("\033[0;33mTesting PushBack ............ \033[0m");
    list *test = initialize_list();
    pushBack(test, 8);
    pushBack(test, 4);
    pushBack(test, 62);
    pushBack(test, 83);
    pushBack(test, 24);
    pushBack(test, 82);
    pushBack(test, 9);
    pushBack(test, 4);
    assert(test->head->next->data == 8 && test->tail->prev->data == 4);
    destroy_list(test);
    free(test);
    printf("\033[0;32mPassed.\033[0m\n");

}

void test_popBack(){
    printf("\033[0;33mTesting popBack ............. \033[0m");
    list *test = initialize_list();
    pushBack(test, 8);
    pushBack(test, 4);
    pushBack(test, 62);
    pushBack(test, 83);
    pushBack(test, 24);
    pushBack(test, 82);
    pushBack(test, 9);
    pushBack(test, 4);
    assert(popback(test) == 4 && popback(test) == 9 && popback(test) == 82);
    destroy_list(test);
    free(test);
    printf("\033[0;32mPassed.\033[0m\n");

    
}
