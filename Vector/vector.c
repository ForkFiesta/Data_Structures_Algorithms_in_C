#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include <stdbool.h>
#include <assert.h>

vec *initialize_vector(){
    vec *rvec = malloc(sizeof(vec));
    if(check_null(rvec)) return NULL;
    rvec->capacity=INITIAL_CAPAITY;
    rvec->size = 0;
    rvec->data = malloc(sizeof(int)*(rvec->capacity));
    return rvec;

}


bool check_null(vec *ptr){
    if (ptr == NULL){
        return true;
    }else {
        return false;
    }
}

int get_size(vec *rvec){
    return rvec->size;
}

void resize(vec *rvec){
    int *new_data = malloc(sizeof(int)*rvec->capacity);
        if(new_data == NULL) return;
        for(int i = 0; i<rvec->size; i++){
            new_data[i] = rvec->data[i];
        }
        free(rvec->data);
        rvec->data = new_data;
}

void check_for_resize(vec *rvec){
    if(rvec->size >= .75 * (float)rvec->capacity){
        rvec->capacity *= 2;
       resize(rvec);
    }
    else if ((rvec->size <=.25 * (float)rvec->capacity) && rvec->capacity>INITIAL_CAPAITY){
        rvec->capacity /= 2;
        resize(rvec);
    }
}

void append(vec *rvec, int value){
    rvec->data[rvec->size] = value;
    rvec->size++;
    check_for_resize(rvec);
}

int pop(vec *rvec){
    if(rvec->size == 0){
        printf("cannot pop from empty list.\n");
        return -1;
    }
    int value = rvec->data[(rvec->size)-1];
    rvec->size--;
    check_for_resize(rvec);
    return value;
}

void insert_at_pos(vec *rvec, int index, int value){
    if (index < 0 || index > rvec->size){
        printf("Index out of range");
    }
    else if (index == rvec->size){
        append(rvec, value);
        return;
    }
    

    for(int i = rvec->size ; i>=index ; i--){
        rvec->data[i] = rvec->data[i-1];
    }
    rvec->data[index] = value;
    rvec->size++;
    check_for_resize(rvec);
}

void insert_at_beginning(vec *rvec, int value){
    insert_at_pos(rvec, 0, value);
}

void remove_value(vec *rvec, int value){
    if (rvec->size == 0){
        printf("Cannot remove items from empty list.\n");
        return;
    }

    for(int i=0; i< rvec->size; i++){
        if(rvec->data[i] == value){
            remove_index(rvec, i);
            i--; // check value again in case there's a repeat number.
        }
    }
    check_for_resize(rvec);


}


void remove_index(vec *rvec, int index){
    if (index >= rvec->size || index < 0){
        printf("Index out of range");
        return;
    }

    for(int i=index; i<rvec->size-1; i++){
        rvec->data[i] = rvec->data[i+1];
    } 

    rvec->size--;
    check_for_resize(rvec);
}




// tests



void do_all_tests(){
    printf("Starting tests....\n");
    test_initialize_vector();
    test_check_if_null();
    test_get_size();
    test_append();
    test_pop();
    test_resize();
    test_insert_at_beginning();
    test_insert_at_pos();
    test_remove_value();
    test_remove_index();
    printf("Passed all tests\n");
}

void test_initialize_vector(){
    vec *test = initialize_vector();
    assert(test->size == 0 && test->capacity == 16);
    free(test->data);
    free(test);
}

void test_check_if_null(){
    vec *test = NULL;
    assert(check_null(test));
}

void test_get_size(){
    vec *test = initialize_vector();
    assert(get_size(test) == 0);
    free(test->data);
    free(test);

}

void test_append(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 8);
    append(test, 5);
    int index_1 = test->data[1];
    assert(get_size(test)==3 && index_1 == 8);
    free(test->data);
    free(test);
}


void test_pop(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 8);
    append(test, 5);
    assert(pop(test)==5);
    free(test->data);
    free(test);

}

void test_resize(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    assert(test->capacity == 32);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    pop(test);
    assert(test->capacity == 16);
    free(test->data);
    free(test);
}


void test_insert_at_pos(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    insert_at_pos(test, 2, 96);
    assert(test->data[2]==96);
    free(test->data);
    free(test);
}

void test_remove_value(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 5);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    remove_value(test, 4);
    assert(test->data[0] == 5);
    free(test->data);
    free(test);

}

void test_insert_at_beginning(){
    vec *test = initialize_vector();
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 5);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    append(test, 4);
    insert_at_beginning(test, 87);
    assert(test->data[0]==87);
    free(test->data);
    free(test);
}

void test_remove_index(){
    vec *test = initialize_vector();
    append(test, 8);
    append(test, 8);
    append(test, 8);
    append(test, 8);
    append(test, 8);
    append(test, 8);
    append(test, 8);
    insert_at_beginning(test, 2);
    insert_at_beginning(test, 3);
    insert_at_pos(test, 1, 77);
    remove_index(test, 2);
    assert(test->data[2] == 8);
    free(test->data);
    free(test);
}





