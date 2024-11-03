/**
 * @file linked_list.h
 * @brief Header file for a singly linked list implementation in C.
 *
 * This file contains the declarations of the functions and data structures
 * used for implementing a singly linked list. The linked list supports
 * various operations such as initialization, insertion, deletion, searching,
 * and utility functions. Additionally, it includes a set of test functions
 * to verify the correctness of the linked list operations.
 */

#ifndef LINKED_H
#define LINKED_H
#include <stdbool.h>

/**
 * @brief Node structure for the linked list.
 *
 * This structure represents a node in the linked list, containing an integer
 * data value and a pointer to the next node in the list.
 */
typedef struct node{
    struct node *next; /**< Pointer to the next node in the list */
    int data; /**< Data value stored in the node */
} node;

/**
 * @brief List structure for the linked list.
 *
 * This structure represents the linked list, containing a pointer to the head
 * node and the size of the list.
 */
typedef struct{
    struct node *head; /**< Pointer to the head node of the list */
    int size; /**< Size of the list */
} list;

/**
 * @brief Initializes a new linked list.
 *
 * This function allocates memory for a new linked list and initializes its
 * head node and size.
 *
 * @return Pointer to the newly initialized list.
 */
list *initialize_list(); 

/**
 * @brief Pushes an element at the beginning of the list.
 *
 * This function inserts a new element with the given value at the beginning
 * of the linked list.
 *
 * @param lst Pointer to the list.
 * @param value Value to be inserted.
 */
void push(list *lst, int value); 

/**
 * @brief Pops and returns the element at the head of the list.
 *
 * This function removes and returns the element at the head of the linked list.
 *
 * @param lst Pointer to the list.
 * @return Value of the popped element.
 */
int pop(list *lst); 

/**
 * @brief Searches for a value in the list.
 *
 * This function searches for the given value in the linked list and returns
 * 1 if the value is found, or -1 if it is not found.
 *
 * @param lst Pointer to the list.
 * @param value Value to be searched.
 * @return 1 if value is found, -1 if not found.
 */
int search(list *lst, int value); 

/**
 * @brief Removes the first occurrence of a value from the list.
 *
 * This function removes the first occurrence of the given value from the
 * linked list.
 *
 * @param lst Pointer to the list.
 * @param value Value to be removed.
 */
void remove_value(list *lst, int value); 

/**
 * @brief Removes all occurrences of a value from the list.
 *
 * This function removes all occurrences of the given value from the linked list.
 *
 * @param lst Pointer to the list.
 * @param value Value to be removed.
 */
void remove_values(list *lst, int value); 

/**
 * @brief Inserts an element at the end of the list.
 *
 * This function inserts a new element with the given value at the end of the
 * linked list.
 *
 * @param lst Pointer to the list.
 * @param value Value to be inserted.
 */
void insert_at_end(list *lst, int value); 

/**
 * @brief Removes and returns the element from the end of the list.
 *
 * This function removes and returns the element from the end of the linked list.
 *
 * @param lst Pointer to the list.
 * @return Value of the removed element.
 */
int remove_from_end(list *lst); 

/**
 * @brief Frees the memory for all elements in the list.
 *
 * This function frees the memory allocated for all elements in the linked list.
 *
 * @param lst Pointer to the list.
 */
void destroy_list(list *lst); 

/**
 * @brief Finds the largest value in the list.
 *
 * This function searches for and returns the largest value in the linked list.
 *
 * @param lst Pointer to the list.
 * @return Largest value in the list.
 */
int find_largest(list *lst); 

/**
 * @brief Finds the smallest value in the list.
 *
 * This function searches for and returns the smallest value in the linked list.
 *
 * @param lst Pointer to the list.
 * @return Smallest value in the list.
 */
int find_smallest(list *lst); 

/**
 * @brief Removes and returns the element at a specific index in the list.
 *
 * This function removes and returns the element at the specified index in the
 * linked list.
 *
 * @param lst Pointer to the list.
 * @param index Index of the element to be removed.
 * @return Value of the removed element.
 */
int remove_from_index(list *lst, int index); 

/**
 * @brief Returns the value of the element at a specific index in the list.
 *
 * This function returns the value of the element at the specified index in the
 * linked list.
 *
 * @param lst Pointer to the list.
 * @param index Index of the element.
 * @return Value of the element at the specified index.
 */
int get_value_from_index(list *lst, int index); 

/* Tests */

/**
 * @brief Runs all test functions.
 *
 * This function runs all the test functions to verify the correctness of the
 * linked list operations.
 */
void run_all_tests();

/**
 * @brief Tests the initialize_list function.
 *
 * This function tests the initialize_list function to ensure it correctly
 * initializes a new linked list.
 */
void test_initalize_list();

/**
 * @brief Tests the push function.
 *
 * This function tests the push function to ensure it correctly inserts elements
 * at the beginning of the linked list.
 */
void test_push();

/**
 * @brief Tests the pop function.
 *
 * This function tests the pop function to ensure it correctly removes and
 * returns the element at the head of the linked list.
 */
void test_pop();

/**
 * @brief Tests the search function.
 *
 * This function tests the search function to ensure it correctly searches for
 * a value in the linked list.
 */
void test_search();

/**
 * @brief Tests the remove_value function.
 *
 * This function tests the remove_value function to ensure it correctly removes
 * the first occurrence of a value from the linked list.
 */
void test_remove_value();

/**
 * @brief Tests the remove_values function.
 *
 * This function tests the remove_values function to ensure it correctly removes
 * all occurrences of a value from the linked list.
 */
void test_remove_values();

/**
 * @brief Tests the insert_at_end function.
 *
 * This function tests the insert_at_end function to ensure it correctly inserts
 * elements at the end of the linked list.
 */
void test_insert_at_end();

/**
 * @brief Tests the remove_from_end function.
 *
 * This function tests the remove_from_end function to ensure it correctly
 * removes and returns the element from the end of the linked list.
 */
void test_remove_from_end();

/**
 * @brief Tests the destroy_list function.
 *
 * This function tests the destroy_list function to ensure it correctly frees
 * the memory for all elements in the linked list.
 */
void test_destroy_list();

/**
 * @brief Tests the find_smallest function.
 *
 * This function tests the find_smallest function to ensure it correctly finds
 * and returns the smallest value in the linked list.
 */
void test_find_smallest();

/**
 * @brief Tests the find_largest function.
 *
 * This function tests the find_largest function to ensure it correctly finds
 * and returns the largest value in the linked list.
 */
void test_find_largest();

/**
 * @brief Tests the remove_from_index function.
 *
 * This function tests the remove_from_index function to ensure it correctly
 * removes and returns the element at a specific index in the linked list.
 */
void test_remove_from_index();

/**
 * @brief Tests the get_value_from_index function.
 *
 * This function tests the get_value_from_index function to ensure it correctly
 * returns the value of the element at a specific index in the linked list.
 */
void test_get_value_from_index();

/**
 * @brief Tests edge cases for the remove_from_index function.
 *
 * This function tests edge cases for the remove_from_index function to ensure
 * it correctly handles out-of-bounds indices and other edge cases.
 */
void test_remove_from_index_edge_cases();

/**
 * @brief Tests the pop function on an empty list.
 *
 * This function tests the pop function to ensure it correctly handles the case
 * when the linked list is empty.
 */
void test_pop_empty();

/**
 * @brief Tests the find_largest function on an empty list.
 *
 * This function tests the find_largest function to ensure it correctly handles
 * the case when the linked list is empty.
 */
void test_find_largest_empty();

/**
 * @brief Tests the find_smallest function on a single-element list.
 *
 * This function tests the find_smallest function to ensure it correctly handles
 * the case when the linked list contains only a single element.
 */
void test_find_smallest_single();

#endif