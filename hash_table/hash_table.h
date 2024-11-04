#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_SIZE 256 // Maximum size for key and value strings
#define TABLE_SIZE 10 // Size of the hash table
#include <stdbool.h>

// Structure for items in the hash table
typedef struct element {
    char key[MAX_SIZE]; // Key of the element
    char value[MAX_SIZE]; // Value of the element
    struct element *next; // Pointer to the next element in case of collision (linked list)
} element;

// Structure for the hash table - an array of elements
typedef struct {
    element *hash_table[TABLE_SIZE]; // Array of pointers to elements
    int capacity; // Capacity of the hash table
} table;

// Function prototypes
table *initialize_table(); // Initialize the hash table
unsigned int hash_function(const char *key); // Hash function to map keys to table indices
void add_key(table *lst, char *key, char *val); // Add a key-value pair to the hash table
element *fetch_value(table *lst, char *key); // Fetch the value associated with a key
void destroy_table(table *tbl); // Destroy the hash table and free memory
bool remove_key(table *tbl, char *key); // Remove a key-value pair from the hash table
void error_exit(); // Handle errors

/* Tests */
void run_all_tests(); // Run all tests
void test_initialize_table(); // Test table initialization
void test_add_key(); // Test adding a key-value pair
void test_fetch_value(); // Test fetching a value
void test_remove_key(); // Test removing a key-value pair

#endif
