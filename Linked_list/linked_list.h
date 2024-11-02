#ifndef LINKED_H
#define LINKED_H
#include <stdbool.h>


typedef struct node{
    struct node *next;
    int data;
}node;

typedef struct{
    struct node *head;
    int size;

}list;


list *initialize_list(); // initializes list object with pointer to head
void push(list *lst, int value); // pushes element at beginning of list
int pop(list *lst); // pops and returns element at head or top of list
int search(list *lst, int value); // Returns 1 if value found, -1 if not found
void remove_value(list *lst); // removes first found value 
void remove_values(list *lst); // removes all found values
void insert_at_end(list *lst, int value); // inserts element at end of list
int remove_from_end(list *lst); // removes element from end of list and returns it
void destroy_list(list *lst); // frees data for all elements in list
void find_largest(list *lst); // finds largest value in list
void find_smallest(list *lst); // find smallest value in list
void remove_from_index(list *lst, int index); // indices list and removes item at index n







//Tests

void run_all_tests();
void test_initalize_list();
void test_push();
void test_pop();
void test_search();
void test_remove_value();
void test_remove_values();
void test_insert_at_end();
void test_remove_from_end();
void test_destroy_list();
void test_find_smallest();
void test_find_largest();
void test_remove_from_index();






#endif