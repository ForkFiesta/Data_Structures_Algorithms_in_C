#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hash_table.h"
#include <string.h>

#define MAX_STRING_SIZE 256
#define INIT_TBL_CAP 16


typedef struct key_value_pair{
    char key[MAX_STRING_SIZE];
    char value[MAX_STRING_SIZE];
    struct key_value_pair *next;
}key_value_pair;

typedef struct {
    key_value_pair *array;
    int size;
    int capacity;
}hash_table;

hash_table *initialize_table();

void memory_error_close();

unsigned int hash_function(const char *key, const int tbl_cap);

bool hasKey(hash_table *tbl, char *key);

char *get(hash_table *tbl, char *key);

bool set(key_value_pair *data, const int capacity, char *key, char *value);


hash_table *initialize_table(){
    hash_table *tbl = malloc(sizeof(hash_table));
    if(tbl == NULL) memory_error_close();
    tbl->capacity = INIT_TBL_CAP;
    tbl->size = 0;
    tbl->array = malloc(sizeof(key_value_pair)*tbl->capacity);
    if(tbl->array == NULL){
        free(tbl);
        memory_error_close();
    }
    for(int i = 0; i < tbl->capacity; i++){
        strcpy(tbl->array[i].key, "");
        strcpy(tbl->array[i].key, "");
        tbl->array[i].next = NULL;
    }

}

unsigned int hash_function(const char *key, const int tbl_cap){
    unsigned int hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % tbl_cap;

}


bool hasKey(hash_table *tbl, char *key){
    if(strcmp("", key)==0){
        return false;
    }

    unsigned int hash = hash_function(key, tbl->capacity);
    key_value_pair kv = tbl->array[hash];
    if(strcmp(kv.key, "")== 0){
        return false;
    }else{
        key_value_pair *curr = &kv;
        key_value_pair *prev = NULL;
        while(curr!=NULL && strcmp(curr->key, key)!=0){
            prev = curr;
            curr = curr->next;
        }
        if(curr != NULL && strcmp(curr->key, key)==0){
            return true;
        }
    }

    return false;

}


char *get(hash_table *tbl, char *key){
    if(strcmp("", key)==0){
        return NULL;
    }

    key_value_pair kv = tbl->array[hash_function(key,tbl->capacity)];
    if(strcmp(kv.key, "")== 0){
        return NULL;
    }else{
        key_value_pair *curr = &kv;
        key_value_pair *prev = NULL;
        while(curr!=NULL && strcmp(curr->key, key)!=0){
            prev = curr;
            curr = curr->next;
        }
        if(curr != NULL && strcmp(curr->key, key)==0){
            return curr->value;
        }
    }

    return NULL;
    

}

bool set(key_value_pair *data, const int capacity, char *key, char *value){
    if(strcmp(key, "") == 0) return;
    if(strcmp(value, "") == 0) return;
    key_value_pair kv = data[hash_function(key , capacity)];
    if(strcmp(kv.key, "")==0){
        strcpy(kv.key, key);
        strcpy(kv.value, value);
        kv.next = NULL;
        return true;
    }else{
        key_value_pair *curr = &kv;
        key_value_pair *prev = NULL;

        while(curr!=NULL){
            prev = curr;
            curr = curr->next;
        }
        if(curr == NULL){
            strcpy(prev->key, key);
            strcpy(prev->value, value);
            prev->next = NULL;
            return false;
        }
    }
}

bool check_for_resize(hash_table *tbl){
    if(((float)tbl->size / (float)tbl->capacity)>=.75){
        upsize(tbl);
    }
}

void upsize(hash_table *tbl){
    tbl->capacity *= 2;
    key_value_pair *new_data = malloc(sizeof(key_value_pair)*(tbl->capacity));
    for(int i = 0; i<tbl->size; i++){
        if(strcmp(tbl->array[i].key, "") != 0){
            key_value_pair *p = &tbl->array[i];
            while(p->next != NULL){
                set(new_data, tbl->capacity, p->key, p->value);
            }
        }
    }

}


void memory_error_close(){
    fprintf(stderr, "Error allocating memeory. Closing Program.\n");
    exit(EXIT_FAILURE);
}