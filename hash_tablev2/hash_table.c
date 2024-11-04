#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hash_table.h"





unsigned int hash_function(const char *key, int size) {
   unsigned int hash = 0;
   while (*key) {
      hash = (hash << 5) + *key++;  // Ensure you're adding *key to the hash
   }
   return hash % size;
}

Node *create_node(char *key, int value){
	Node *new_node = malloc(sizeof(Node));
	if(!new_node){
		fprintf(stderr, "%s\n", "Memory allocation failure");
		exit(1);
	}
	new_node->key = strdup(key);
	new_node->value = value;
	new_node->next = NULL;
    return new_node;
}

HashTable *create_table(){
    HashTable *tbl = malloc(sizeof(HashTable));
    if(!tbl){
        fprintf(stderr, "Memory allocation error.\n");
        exit(1);
    }

    tbl->size = INIT_TABLE_SIZE;
    tbl->table = (Node**)calloc(tbl->size, sizeof(Node *));
    tbl->count = 0;

    return tbl;
}


void resize(HashTable *tbl){
    // tbl->size *= 2;
    int new_size = tbl->size * 2;
    Node **new_array = (Node **)calloc(new_size, sizeof(Node *));
    if(!new_array){
        fprintf(stderr, "Memory allocation failure\n");
        exit(1);
    }

    for(int i = 0; i<tbl->size; i++){
        Node *curr = tbl->table[i];
        while(curr){
            Node *next_node = curr->next;
            unsigned int new_hash = hash_function(curr->key, new_size);
            curr->next = new_array[new_hash];
            new_array[new_hash] = curr;
            curr = next_node;
        }
    }
    free(tbl->table);
    tbl->table = new_array;
    tbl->size = new_size;

}

void insert(HashTable *tbl, char *key, int value){
    if(((float)tbl->count / (float)tbl->size) >= LOAD_FACTOR){
        resize(tbl);
    }

    unsigned int hash = hash_function(key, tbl->size);
    Node *p = tbl->table[hash];
    while(p && strcmp(p->key, key)!=0){
        p=p->next;
    }
    if(p){
        p->value = value;
        return;
    }else{
        Node *new_node = malloc(sizeof(Node));
        if(!new_node){
            fprintf(stderr, "Memory allocation error.\n");
            exit(1);
        }
        new_node->key = strdup(key);
        new_node->value = value;
        new_node->next = tbl->table[hash];
        tbl->table[hash] = new_node;
        tbl->count++;

    }
}

int search(HashTable *tbl, char *key){
    unsigned int hash = hash_function(key, tbl->size);
    Node *p = tbl->table[hash];
    while(p && strcmp(p->key, key)!= 0){
        p = p->next;
    }
    if(p){
        return p->value;
    }else{
        fprintf(stderr, "Key not found.\n");
        return -1;
    }
}

void free_table(HashTable *tbl){
    for(int i = 0; i < tbl->size; i++){
        Node *p = tbl->table[i];
        while(p){
            Node *delete = p;
            p = p->next;
            free(delete->key);
            free(delete);
        }
    }
    free(tbl->table);
    free(tbl);
}



void run_all_tests() {
    printf("\033[1;33m Running all tests\033[0m\n");
    test_create_table();
    test_insert_and_search();
    test_resize();
    test_free_table();
    printf("\033[1;32mPassed All Tests Successfully\033[0m\n");
}

void test_create_table() {
    printf("\033[0;33mTesting create_table...\033[0m");
    HashTable *tbl = create_table();
    assert(tbl != NULL);
    assert(tbl->size == INIT_TABLE_SIZE);
    assert(tbl->count == 0);
    for (int i = 0; i < tbl->size; i++) {
        assert(tbl->table[i] == NULL);
    }
    free_table(tbl);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_insert_and_search() {
    printf("\033[0;33mTesting insert and search...\033[0m");
    HashTable *tbl = create_table();

    // Insert key-value pairs
    insert(tbl, "apple", 10);
    insert(tbl, "banana", 20);
    insert(tbl, "cherry", 30);

    // Test searching for existing keys
    assert(search(tbl, "apple") == 10);
    assert(search(tbl, "banana") == 20);
    assert(search(tbl, "cherry") == 30);

    // Test searching for a non-existing key
    assert(search(tbl, "pear") == -1);

    free_table(tbl);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_resize() {
    printf("\033[0;33mTesting resize...\033[0m");
    HashTable *tbl = create_table();

    // Insert more items than the initial table size to trigger resizing
    for (int i = 0; i < 20; i++) {
        char key[10];
        sprintf(key, "key%d", i);
        insert(tbl, key, i * 5);
    }

    // Check that all inserted items are still present after resizing
    for (int i = 0; i < 20; i++) {
        char key[10];
        sprintf(key, "key%d", i);
        assert(search(tbl, key) == i * 5);
    }

    assert(tbl->size >= 32); // Check that the table size has increased

    free_table(tbl);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_free_table() {
    printf("\033[0;33mTesting free_table...\033[0m");
    HashTable *tbl = create_table();

    insert(tbl, "test1", 1);
    insert(tbl, "test2", 2);
    insert(tbl, "test3", 3);

    // Free the table and check that no segmentation faults occur
    free_table(tbl);

    printf("\033[0;32mpassed.\033[0m\n");
}
