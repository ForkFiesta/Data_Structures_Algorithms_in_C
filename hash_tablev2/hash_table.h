#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#define INIT_TABLE_SIZE 16
#define LOAD_FACTOR 0.75

typedef struct Node {
   char *key;
   int value;
   struct Node *next;
}Node;


typedef struct{
   Node **table;
   int size;
   int count;
}HashTable;

unsigned int hash_function(const char *key, int size);
Node *create_node(char *key, int value);
HashTable *create_table();
void resize(HashTable *tbl);
void insert(HashTable *tbl, char *key, int value);
void free_table(HashTable *tbl);

// Function prototypes for tests
void test_create_table();
void test_insert_and_search();
void test_resize();
void test_free_table();
void run_all_tests();





#endif