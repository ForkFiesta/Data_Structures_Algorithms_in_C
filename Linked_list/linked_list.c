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

/**
 * @brief Initializes a new linked list.
 *
 * Allocates memory for a new list and its head node. Initializes the head node
 * and sets the size of the list to 0.
 *
 * @return A pointer to the newly initialized list.
 */
list *initialize_list();

/**
 * @brief Inserts a new value at the beginning of the list.
 *
 * Allocates memory for a new node, sets its value, and inserts it at the
 * beginning of the list. Increments the size of the list.
 *
 * @param lst A pointer to the list.
 * @param value The value to be inserted.
 */
void push(list *lst, int value);

/**
 * @brief Destroys the list and frees all allocated memory.
 *
 * Traverses the list and frees all nodes. Resets the size of the list to 0
 * and sets the head pointer to NULL.
 *
 * @param lst A pointer to the list to be destroyed.
 */
void destroy_list(list *lst);

/**
 * @brief Removes and returns the value at the beginning of the list.
 *
 * Removes the first node in the list and returns its value. Decrements the
 * size of the list.
 *
 * @param lst A pointer to the list.
 * @return The value of the removed node, or -1 if the list is empty.
 */
int pop(list *lst);

/**
 * @brief Searches for a value in the list.
 *
 * Traverses the list to find the specified value.
 *
 * @param lst A pointer to the list.
 * @param value The value to search for.
 * @return 1 if the value is found, -1 otherwise.
 */
int search(list *lst, int value);

/**
 * @brief Removes the first occurrence of a value from the list.
 *
 * Traverses the list to find the first occurrence of the specified value and
 * removes it. Decrements the size of the list.
 *
 * @param lst A pointer to the list.
 * @param value The value to be removed.
 */
void remove_value(list *lst, int value);

/**
 * @brief Removes all occurrences of a value from the list.
 *
 * Traverses the list to find all occurrences of the specified value and
 * removes them. Decrements the size of the list for each removal.
 *
 * @param lst A pointer to the list.
 * @param value The value to be removed.
 */
void remove_values(list *lst, int value);

/**
 * @brief Inserts a new value at the end of the list.
 *
 * Allocates memory for a new node, sets its value, and inserts it at the
 * end of the list. Increments the size of the list.
 *
 * @param lst A pointer to the list.
 * @param value The value to be inserted.
 */
void insert_at_end(list *lst, int value);

/**
 * @brief Removes and returns the value at the end of the list.
 *
 * Removes the last node in the list and returns its value. Decrements the
 * size of the list.
 *
 * @param lst A pointer to the list.
 * @return The value of the removed node, or -1 if the list is empty.
 */
int remove_from_end(list *lst);

/**
 * @brief Finds and returns the largest value in the list.
 *
 * Traverses the list to find the largest value.
 *
 * @param lst A pointer to the list.
 * @return The largest value in the list, or -1 if the list is empty.
 */
int find_largest(list *lst);

/**
 * @brief Finds and returns the smallest value in the list.
 *
 * Traverses the list to find the smallest value.
 *
 * @param lst A pointer to the list.
 * @return The smallest value in the list, or -1 if the list is empty.
 */
int find_smallest(list *lst);

/**
 * @brief Removes and returns the value at a specified index in the list.
 *
 * Removes the node at the specified index and returns its value. Decrements
 * the size of the list.
 *
 * @param lst A pointer to the list.
 * @param index The index of the node to be removed.
 * @return The value of the removed node, or -1 if the index is out of range.
 */
int remove_from_index(list *lst, int index);

/**
 * @brief Returns the value at a specified index in the list.
 *
 * Traverses the list to find the node at the specified index and returns its
 * value.
 *
 * @param lst A pointer to the list.
 * @param index The index of the node.
 * @return The value of the node at the specified index, or -1 if the index is out of range.
 */
int get_value_from_index(list *lst, int index);

/**
 * @brief Runs all test functions to verify the correctness of the linked list operations.
 *
 * Calls each test function and prints the results. If all tests pass, prints a success message.
 */
void run_all_tests();

/**
 * @brief Tests the initialize_list function.
 *
 * Verifies that a new list is correctly initialized.
 */
void test_initalize_list();

/**
 * @brief Tests the push function.
 *
 * Verifies that values are correctly inserted at the beginning of the list.
 */
void test_push();

/**
 * @brief Tests the destroy_list function.
 *
 * Verifies that the list is correctly destroyed and all memory is freed.
 */
void test_destroy_list();

/**
 * @brief Tests the pop function.
 *
 * Verifies that values are correctly removed from the beginning of the list.
 */
void test_pop();

/**
 * @brief Tests the search function.
 *
 * Verifies that values are correctly found in the list.
 */
void test_search();

/**
 * @brief Tests the remove_values function.
 *
 * Verifies that all occurrences of a value are correctly removed from the list.
 */
void test_remove_values();

/**
 * @brief Tests the remove_value function.
 *
 * Verifies that the first occurrence of a value is correctly removed from the list.
 */
void test_remove_value();

/**
 * @brief Tests the remove_from_end function.
 *
 * Verifies that values are correctly removed from the end of the list.
 */
void test_remove_from_end();

/**
 * @brief Tests the insert_at_end function.
 *
 * Verifies that values are correctly inserted at the end of the list.
 */
void test_insert_at_end();

/**
 * @brief Tests the find_smallest function.
 *
 * Verifies that the smallest value in the list is correctly found.
 */
void test_find_smallest();

/**
 * @brief Tests the find_largest function.
 *
 * Verifies that the largest value in the list is correctly found.
 */
void test_find_largest();

/**
 * @brief Tests the remove_from_index function.
 *
 * Verifies that values are correctly removed from specified indices in the list.
 */
void test_remove_from_index();

/**
 * @brief Tests the get_value_from_index function.
 *
 * Verifies that values are correctly retrieved from specified indices in the list.
 */
void test_get_value_from_index();

/**
 * @brief Tests edge cases for the remove_from_index function.
 *
 * Verifies that the function handles out-of-bounds indices and other edge cases correctly.
 */
void test_remove_from_index_edge_cases();

/**
 * @brief Tests the pop function on an empty list.
 *
 * Verifies that the function handles popping from an empty list correctly.
 */
void test_pop_empty();

/**
 * @brief Tests the find_largest function on an empty list.
 *
 * Verifies that the function handles finding the largest value in an empty list correctly.
 */
void test_find_largest_empty();

/**
 * @brief Tests the find_smallest function on a single-element list.
 *
 * Verifies that the function correctly finds the smallest value in a single-element list.
 */
void test_find_smallest_single();

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








