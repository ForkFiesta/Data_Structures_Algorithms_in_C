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
        // fprintf(stderr,"Cannot pop from empty list.\n");
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



bool find(list *lst, int key){
    if(lst->head->next == lst->tail){
        // printf("Cannot search an empty list.\n");
        return false;
    }
    

    node *p = lst->head;

    while(p != lst->tail){
        if (p->data == key){
            return true;
        }
        p = p->next;
    }
    return false;

}

void erase(list *lst, int key){
    if(is_empty(lst)){
        // fprintf(stderr, "Cannot erase from empty list.\n");
        return;
    }

    node *p = lst->head;
    while(p != lst->tail){
        if(p->next->data == key){
            node *t = p->next;
            p->next = t->next;
            p->next->prev = p;
            free(t);
        }
        else{
            p = p->next;
        }
    }

}

bool is_empty(list *lst){
    return (lst->head->next == lst->tail);
}


node *getNthNode(list *lst, int n){
    if(is_empty(lst)){
        // fprintf(stderr, "Cannot search an empty list\n");
        return NULL;
    }

    int count = 0;
    node *p = lst->head->next;
    while(count != n){
        p = p->next;
        count++;
    }

    return p;
}



void addAfter(node *nd, int key){
    if(nd == NULL){
        fprintf(stderr, "Inputted node is empty. Exiting program.\n");
        exit(1);
    }
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        fprintf(stderr, "Error allocating memory for new node. Terminating program.\n");
        exit(1);
    }

    new_node->data = key;
    new_node->next = nd->next;
    new_node->prev = nd;
    nd->next->prev = new_node;
    nd->next = new_node;
}

void addBefore(node *nd, int key){
    if(nd == NULL){
        fprintf(stderr, "Inputted node is empty. Exiting program.\n");
        exit(1);
    }
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        fprintf(stderr, "Error allocating memory for new node. Terminating program.\n");
        exit(1);
    }

    new_node->data = key;
    new_node->next = nd;
    new_node->prev = nd->prev;
    nd->prev->next = new_node;
    nd->prev = new_node;
}




/* Tests */
void run_all_tests(){
    printf("\033[0;33mCommencing Tests...\033[0m\n");
    test_initialize_list();
    test_destroy_list();
    test_pushFront();
    test_is_empty();
    test_pushBack();
    test_popBack();
    test_find();
    test_erase();
    test_getNthNode();
    test_addAfter();
    test_addBefore();
    printf("\033[1;32mPassed All Tests\033[0m\n");
}

void test_initialize_list(){
    printf("\033[0;33mTesting Initialize List ..... \033[0m");
    list *lst = initialize_list();
    assert(lst != NULL);
    assert(lst->head != NULL);
    assert(lst->tail != NULL);
    assert(lst->head->next == lst->tail);
    assert(lst->tail->prev == lst->head);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");
}

void test_destroy_list(){
    printf("\033[0;33mTesting Destroy List ........ \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    destroy_list(lst);
    assert(lst->head == NULL);
    assert(lst->tail == NULL);
    free(lst);

    printf("\033[0;32mPassed.\033[0m\n");

}

void test_pushFront(){
    printf("\033[0;33mTesting Push Front .......... \033[0m");
    list *lst = initialize_list();
    pushFront(lst, 1);
    assert(lst->head->next->data == 1);
    pushFront(lst, 2);
    assert(lst->head->next->data == 2);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");


}

void test_pushBack(){
    printf("\033[0;33mTesting PushBack ............ \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    assert(lst->tail->prev->data == 1);
    pushBack(lst, 2);
    assert(lst->tail->prev->data == 2);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");

}

void test_popBack(){
    printf("\033[0;33mTesting popBack ............. \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    assert(popback(lst) == 2);
    assert(popback(lst) == 1);
    assert(popback(lst) == -1); // Edge case: popping from empty list
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");

    
}


void test_find(){
    printf("\033[0;33mTesting find ................ \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    assert(find(lst, 1) == true);
    assert(find(lst, 3) == false);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");



}


void test_erase(){
    printf("\033[0;33mTesting Erase ............... \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    erase(lst, 2);
    assert(find(lst, 2) == false);
    erase(lst, 1);
    assert(find(lst, 1) == false);
    erase(lst, 3);
    assert(find(lst, 3) == false);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");


}


void test_getNthNode(){
    printf("\033[0;33mTesting Get Nth Node ........ \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    node *n = getNthNode(lst, 1);
    assert(n->data == 2);
    n = getNthNode(lst, 0);
    assert(n->data == 1);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");

}

void test_addAfter(){
    printf("\033[0;33mTesting AddAfter ............ \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    node *n = getNthNode(lst, 0);
    addAfter(n, 3);
    assert(n->next->data == 3);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");

}

void test_addBefore(){
    printf("\033[0;33mTesting AddBefore ........... \033[0m");
    list *lst = initialize_list();
    pushBack(lst, 1);
    pushBack(lst, 2);
    node *n = getNthNode(lst, 1);
    addBefore(n, 3);
    assert(n->prev->data == 3);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");    
}


void test_is_empty(){
 printf("\033[0;33mTesting is_Empty ............ \033[0m");
    list *lst = initialize_list();
    assert(is_empty(lst) == true);
    pushBack(lst, 1);
    assert(is_empty(lst) == false);
    destroy_list(lst);
    free(lst);
    printf("\033[0;32mPassed.\033[0m\n");    


}