/**
 * @file linked_list.c
 * @brief Implementation of a singly linked list in C.
 *
 * This file contains the implementation of a singly linked list, including
 * functions for initialization, insertion, deletion, searching, and other
 * utility operations. It also includes a set of test functions to verify
 * the correctness of the linked list operations.
 */

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>



list *initialize_list(){
    list *lst = malloc(sizeof(list));
    if(lst==NULL){
        printf("Error allocating memory. Ending program\n");
        exit(EXIT_FAILURE);
    }
    lst->head = malloc(sizeof(node));
    if(lst->head == NULL){
        printf("Error allocating memory. Ending program\n");
        free(lst);
        exit(EXIT_FAILURE);
    }

    lst->size = 0;
    lst->head->next = NULL;
    return lst;
}


void push(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL){
        printf("Error allocating memory. Ending program\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;

    new_node->next = lst->head->next;
    lst->head->next = new_node;
    lst->size++;

}

void destroy_list(list *lst){
    node *p = lst->head;
    while(p != NULL){
        node *t = p;
        p = p->next;
        free(t);
    }
    lst->size = 0;
    lst->head = NULL;
}

int pop(list *lst){
    if (lst->head->next == NULL){
        printf("Cannot pop from empty list\n");
        return -1;
    }
    
    int popped_value = lst->head->next->data;
    node *p = lst->head->next->next;
    free(lst->head->next);
    lst->head->next = p;
    lst->size--;

    return popped_value;
}

int search(list *lst, int value){
    if(lst->head->next==NULL){
        printf("Cannot search an empty list.\n");
        return -1;
    }

    node *p = lst->head->next;
    while(p != NULL){
        if(p->data == value){
            return 1;
        }
        p = p->next;
    }
    return -1;
}

void remove_value(list *lst, int value){

    if(lst->head->next == NULL){
        printf("Cannot remove values from empty list.\n");
        return;
    }

    node *p = lst->head;

    while(p->next != NULL && p->next->data != value){
        p = p->next;
    }
    if(p->next != NULL && p->next->data == value){
        node *t = p->next->next;
        free(p->next);
        p->next = t;
        lst->size--;
    }


}

void remove_values(list *lst, int value){
    if(lst->head->next == NULL){
            printf("Cannot remove values from empty list.\n");
            return;
        }

    node *p = lst->head;

    while (p->next != NULL){
        if(p->next->data == value){
            node *t = p->next;
            p->next = t->next;
            free(t);
            lst->size--;
            
        }else{
            p = p->next;
        }
    }
}


void insert_at_end(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = value;
    new_node->next = NULL;

    node *p = lst->head;
    for(;p->next != NULL; p = p->next); // traverse through the list until the current node's next pointer is null
    p->next = new_node;
    lst->size++;
    
}

int remove_from_end(list *lst){
    if(lst->head->next == NULL){
        printf("cannot remove values from empty list.\n");
        return -1;
    }

    node *p = lst->head;
    //traverse through list until second the last element
    for(;p->next->next!= NULL; p = p->next);
    // assign last node to temp pointer
    node *t =p->next;
    // get value to be removed
    int removed_value = t->data;
    // free last node
    free(t);
    //make seond to last pointer last node
    p->next = NULL;
    // decrement list size
    lst->size--;
    //return removed value
    return removed_value;
}


int find_largest(list *lst){
    if(lst->head->next == NULL){
        printf("Cannot search empty list\n");
        return -1;
    }

    node *p = lst->head->next;
    int largest = p->data;
    for(;p->next != NULL; p = p->next){
        if(p->data > largest){
            largest = p->data;
        }
    }

    return largest;
}

int find_smallest(list *lst){
    if(lst->head->next == NULL){
    printf("Cannot search empty list\n");
    return -1;
    }

    node *p = lst->head->next;
    int smallest = p->data;
    for(;p->next!=NULL;p=p->next){
        if(p->data < smallest){
            smallest = p->data;
        }
    }

    return smallest;
}


int remove_from_index(list *lst, int index){
    if(index < 0 || index >= lst->size){
        printf("Index out of range\n");
        return -1;
    }
    if(index == 0){
       return pop(lst);
    }else if (index == (lst->size)-1){
        return remove_from_end(lst);
    }
    int counter = 0;
    node *p = lst->head;
    while(counter != index){
        p = p->next;
        counter++;
    }

    node *t = p->next;
    int return_val = t->data;
    p->next = t->next;
    free(t);
    lst->size--;
    return return_val;


}


int get_value_from_index(list *lst, int index){

    if(index < 0 || index >= lst->size){
        printf("Index out of range\n");
        return -1;
    }
    int counter = 0;
    node *p = lst->head->next; // start at first value
    while(counter != index){
        p = p->next;
        counter++;
    }

    return p->data;

    

}






/* Tests */

void run_all_tests(){
    printf("\033[1;33m Running all tests\033[0m\n");
    test_initalize_list();
    test_push();
    test_destroy_list();
    test_pop();
    test_pop_empty();  // New test for pop on empty list
    test_search();
    test_remove_values();
    test_remove_value();
    test_remove_from_end();
    test_insert_at_end();
    test_find_smallest();
    test_find_largest();
    test_find_largest_empty();  // New test for find_largest on empty list
    test_find_smallest_single();  // New test for find_smallest on single-element list
    test_get_value_from_index();
    test_remove_from_index();
    test_remove_from_index_edge_cases();  // New edge case test for remove_from_index
    printf("\033[1;32mPassed All Tests Successfully\033[0m\n");
}


void test_initalize_list(){
    printf("\033[0;33mTesting initalize list...\n");
    list *test = initialize_list();
    assert(test != NULL && test->head != NULL && test->head->next == NULL && test->size==0);
    destroy_list(test);
    free(test);


}

void test_push(){
    printf("Testing push ...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(test->size==7 && test->head->next->data==55 && test->head->next->next->data == 12);
    destroy_list(test);
    free(test);

}


void test_destroy_list(){
    printf("Testing Destroy List...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    destroy_list(test);
    assert(test->head == NULL);
    free(test);
}

void test_pop(){
    printf("Testing pop()...\n");
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
    printf("Testing search ... \n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(search(test, 2) == 1);
    destroy_list(test);

}

void test_remove_values(){
    printf("Testing Remove_Values...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(search(test, 3)==1);
    remove_values(test, 3);
    assert(search(test, 3)== -1);
    destroy_list(test);
}


void test_remove_value(){
    printf("Testing Remove First Value Found...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    remove_value(test, 3);
    assert(test->head->next->data == 12 && search(test, 3) == 1);
    destroy_list(test);

}


void test_remove_from_end(){
    printf("Testing Removing from End...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);

    int tv = remove_from_end(test);
    assert(tv == 3);

}

void test_insert_at_end(){
    printf("Testing Insert at end...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    insert_at_end(test, 96);
    remove_value(test, 3);
    assert(test->head->next->data==12 && search(test, 3) == 1);
    destroy_list(test);
}


void test_find_smallest(){
     printf("Testing Find Smallest...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(find_smallest(test)==2);
    destroy_list(test);
}


void test_find_largest(){
     printf("Testing Find Largest...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(find_largest(test) == 12);
    destroy_list(test);

}


void test_remove_from_index(){
    printf("Testing Remove from Index...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(remove_from_index(test,2)==7);
    destroy_list(test);

}

void test_get_value_from_index(){
    printf("Testing Get Value from Index...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(get_value_from_index(test, 3) == 2);
    destroy_list(test);

}

void test_remove_from_index_edge_cases(){
    printf("Testing Remove from Index edge cases...\033[0m\n");
    list *test = initialize_list();
    assert(remove_from_index(test, 0) == -1);  // Out-of-bounds on empty list
    
    push(test, 10);
    assert(remove_from_index(test, 1) == -1);  // Out-of-bounds on single-element list
    assert(remove_from_index(test, 0) == 10);  // Valid case
    
    destroy_list(test);
    free(test);
}

void test_pop_empty(){
    printf("Testing pop() on an empty list...\n");
    list *test = initialize_list();
    assert(pop(test) == -1);  // Ensure it returns -1 and handles gracefully
    destroy_list(test);
    free(test);
}

void test_find_largest_empty(){
    printf("Testing Find Largest with an empty list...\n");
    list *test = initialize_list();
    assert(find_largest(test) == -1);
    destroy_list(test);
    free(test);
}

void test_find_smallest_single(){
    printf("Testing Find Smallest with a single-element list...\n");
    list *test = initialize_list();
    push(test, 42);
    assert(find_smallest(test) == 42);
    destroy_list(test);
    free(test);
}








