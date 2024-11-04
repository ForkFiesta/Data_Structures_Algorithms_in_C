#include "hash_table.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


table *initialize_table(){
    table *tbl = malloc(sizeof(table));
    if(tbl == NULL) error_exit();
    tbl->capacity = TABLE_SIZE;
    for(int i = 0; i<TABLE_SIZE; i++){
        tbl->hash_table[i] = NULL;
    }
    return tbl;

}

unsigned int hash_function(const char *key){
    unsigned int hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}


void add_key(table *lst, char *key, char *val){
    element *existing = fetch_value(lst, key);
    if(existing != NULL){
        strcpy(existing->value, val);
    }else{
        element *item = malloc(sizeof(element));
        if(item == NULL){
            error_exit();
        }
        strcpy(item->key, key);
        strcpy(item->value, val);
        item->next = NULL;
        unsigned int hash = hash_function(key);
        if (lst->hash_table[hash] == NULL){
            lst->hash_table[hash] = item;
        } else {
            element *p = lst->hash_table[hash];
            while(p->next != NULL){
                p = p->next;
            }
            p->next = item;
        }
    

    }

    

}

element *fetch_value(table *lst, char *key){
    unsigned int hash = hash_function(key);
    if(lst->hash_table[hash]!= NULL){
        if(strcmp(lst->hash_table[hash]->key, key) == 0){
                return lst->hash_table[hash];
            }else{
                element *p = lst->hash_table[hash];
                while(p!= NULL && strcmp(p->key, key)!= 0){
                    p = p->next;
                }
                if(p != NULL && strcmp(p->key, key)==0){
                    return p;
                }else{
                    return NULL;
                }
            }
    }else return NULL;
    
}

bool remove_key(table *tbl, char *key){
    if (fetch_value(tbl, key) != NULL){
        unsigned int hash = hash_function(key);
        element *p = tbl->hash_table[hash];
        element *prev = NULL;

        while(p != NULL && strcmp(p->key, key) != 0){
            prev = p;
            p = p->next;
        }

        if(p == NULL){
            return false;
        }
        if (prev == NULL) {
            tbl->hash_table[hash] = p->next;
        } else{
            prev->next = p->next;
        }

        free(p);

        return true;
    
    }
    return false;
}





void destroy_table(table *tbl){
    for(int i = 0; i<TABLE_SIZE; i++){
        if(tbl->hash_table[i]!=NULL){
            element *p = tbl->hash_table[i];
            while(p!=NULL){
                element *t = p;
                p=t->next;
                free(t);
            }
        }
        tbl->hash_table[i] = NULL;
    }
}


void error_exit(){
    fprintf(stderr, "Error allocating memory.\n");
    exit(EXIT_FAILURE);
}





// /* Tests */
void run_all_tests(){
    printf("\033[0;33mCommencing Tests...\033[0m\n");
    test_initialize_table();
    test_add_key();
    test_fetch_value();
    test_remove_key();
    printf("\033[1;32mPassed All Tests\033[0m\n");


}

void test_initialize_table() {
    printf("\033[0;33mTesting Initialize Table ..... \033[0m");
    table *tbl = initialize_table();
    assert(tbl != NULL);
    assert(tbl->capacity == TABLE_SIZE);
    for (int i = 0; i < tbl->capacity; i++) {
        assert(tbl->hash_table[i] == NULL);
    }
    free(tbl);
    printf("\033[0;32mPassed.\033[0m\n");
}

void test_add_key() {
    printf("\033[0;33mTesting Add Key .............. \033[0m");
    table *tbl = initialize_table();
    add_key(tbl, "key1", "value1");
    add_key(tbl, "key2", "value2");

    assert(tbl->hash_table[hash_function("key1")] != NULL);
    assert(strcmp(fetch_value(tbl, "key1")->value, "value1") == 0);
    assert(strcmp(fetch_value(tbl, "key2")->value, "value2") == 0);

    destroy_table(tbl);
    free(tbl);
    printf("\033[0;32mPassed.\033[0m\n");
}

void test_fetch_value() {
    printf("\033[0;33mTesting Fetch Value .......... \033[0m");
    table *tbl = initialize_table();
    add_key(tbl, "key1", "value1");
    add_key(tbl, "key2", "value2");

    assert(strcmp(fetch_value(tbl, "key1")->value, "value1") == 0);
    assert(strcmp(fetch_value(tbl, "key2")->value, "value2") == 0);
    assert(fetch_value(tbl, "key3") == NULL);

    destroy_table(tbl);
    free(tbl);
    printf("\033[0;32mPassed.\033[0m\n");
}

void test_remove_key() {
    printf("\033[0;33mTesting Remove Key ........... \033[0m");
    table *tbl = initialize_table();
    add_key(tbl, "key1", "value1");
    add_key(tbl, "key2", "value2");

    assert(remove_key(tbl, "key1") == true);
    assert(fetch_value(tbl, "key1") == NULL);
    assert(remove_key(tbl, "key3") == false);

    destroy_table(tbl);
    free(tbl);
    printf("\033[0;32mPassed.\033[0m\n");
}

