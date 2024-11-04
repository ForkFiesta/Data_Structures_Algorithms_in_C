#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define MAX_SIZE 256
#define TABLE_SIZE 10
#include <stdbool.h>

// structure for items in hash table
typedef struct element{
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    struct element *next; //how fixed array size is possible
}element;

// structure for hash table - an array of elements
typedef struct {
    element *hash_table[TABLE_SIZE];
    int capacity;
}table;


table *initialize_table();
unsigned int hash_function(const char *key);
void add_key(table *lst, char *key, char *val);
element *fetch_value(table *lst, char *key);
void destroy_table(table *tbl);
bool remove_key(table *tbl, char *key);
void error_exit();


/* Tests */

// void run_all_tests();
// void test_initialize_table();
// void test_add_key();
// void test_fetch_value();



#endif