#ifndef VECTOR_H
#define VECTOR_H
#include <stdbool.h>

#define INITIAL_CAPAITY 16

typedef struct {
    int *data;
    int size;
    int capacity;
}vec;

vec *initialize_vector();
bool check_null(vec *ptr);
void resize(vec *rvec);
void check_for_resize(vec *rvec);
void append(vec *rvec, int value);
int pop(vec *rvec);
void insert_at_pos(vec *rvec, int index, int value);
void insert_at_beginning(vec *rvec, int value);
void remove_value(vec *rvec, int value);
void remove_index(vec *rvec, int index);


/* Tests */

void do_all_tests();
void test_initialize_vector();
void test_check_if_null();
void test_get_size();
void test_append();
void test_pop();
void test_resize();
void test_insert_at_pos();
void test_remove_value();
void test_insert_at_beginning();
void test_remove_index();

#endif