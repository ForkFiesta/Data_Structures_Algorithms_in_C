#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/**
 * @file linkedlist.h
 * @brief Header file for a doubly linked list implementation with a tail pointer.
 *
 * This file contains the definitions and function prototypes for a doubly linked list
 * implementation. The list maintains pointers to both the head and tail nodes, and
 * supports various operations such as insertion, deletion, and search.
 */



#include <stdbool.h>

/**
 * @struct node
 * @brief A node in the doubly linked list.
 *
 * This structure represents a node in the doubly linked list, containing pointers
 * to the next and previous nodes, as well as the data stored in the node.
 */
typedef struct node {
    struct node *next; /**< Pointer to the next node in the list */
    struct node *prev; /**< Pointer to the previous node in the list */
    int data;          /**< Data stored in the node */
} node;

/**
 * @struct list
 * @brief A doubly linked list with head and tail pointers.
 *
 * This structure represents a doubly linked list, containing pointers to the head
 * and tail nodes, as well as the size of the list.
 */
typedef struct {
    struct node *head; /**< Pointer to the head node of the list */
    struct node *tail; /**< Pointer to the tail node of the list */
    int size;          /**< Size of the list */
} list;

/**
 * @brief Initialize a new doubly linked list.
 *
 * @return A pointer to the newly initialized list.
 */
list *initialize_list();

/**
 * @brief Destroy a doubly linked list and free its memory.
 *
 * @param lst A pointer to the list to be destroyed.
 */
void destroy_list(list *lst);

/**
 * @brief Insert a new node with the given value at the front of the list.
 *
 * @param lst A pointer to the list.
 * @param value The value to be inserted.
 */
void pushFront(list *lst, int value);

/**
 * @brief Insert a new node with the given value at the back of the list.
 *
 * @param lst A pointer to the list.
 * @param value The value to be inserted.
 */
void pushBack(list *lst, int value);

/**
 * @brief Remove and return the value of the node at the back of the list.
 *
 * @param lst A pointer to the list.
 * @return The value of the removed node.
 */
int popback(list *lst);

/**
 * @brief Find a node with the given key in the list.
 *
 * @param lst A pointer to the list.
 * @param key The key to be found.
 * @return true if the key is found, false otherwise.
 */
bool find(list *lst, int key);

/**
 * @brief Remove a node with the given key from the list.
 *
 * @param lst A pointer to the list.
 * @param key The key of the node to be removed.
 */
void erase(list *lst, int key);

/**
 * @brief Check if the list is empty.
 *
 * @param lst A pointer to the list.
 * @return true if the list is empty, false otherwise.
 */
bool is_empty(list *lst);

/**
 * @brief Get the nth node in the list.
 *
 * @param lst A pointer to the list.
 * @param n The index of the node to be retrieved (0-based).
 * @return A pointer to the nth node.
 */
node *getNthNode(list *lst, int n);

/**
 * @brief Add a new node with the given key after the specified node.
 *
 * @param nd A pointer to the node after which the new node will be added.
 * @param key The key of the new node to be added.
 */
void addAfter(node *nd, int key);

/**
 * @brief Add a new node with the given key before the specified node.
 *
 * @param nd A pointer to the node before which the new node will be added.
 * @param key The key of the new node to be added.
 */
void addBefore(node *nd, int key);

/**
 * @brief Run all tests for the linked list implementation.
 */
void run_all_tests();

/**
 * @brief Test the initialize_list function.
 */
void test_initialize_list();

/**
 * @brief Test the destroy_list function.
 */
void test_destroy_list();

/**
 * @brief Test the pushFront function.
 */
void test_pushFront();

/**
 * @brief Test the is_empty function.
 */
void test_is_empty();

/**
 * @brief Test the pushBack function.
 */
void test_pushBack();

/**
 * @brief Test the popback function.
 */
void test_popBack();

/**
 * @brief Test the find function.
 */
void test_find();

/**
 * @brief Test the erase function.
 */
void test_erase();

/**
 * @brief Test the getNthNode function.
 */
void test_getNthNode();

/**
 * @brief Test the addAfter function.
 */
void test_addAfter();

/**
 * @brief Test the addBefore function.
 */
void test_addBefore();

#endif