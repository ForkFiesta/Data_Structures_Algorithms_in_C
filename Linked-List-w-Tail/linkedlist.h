#include <stdbool.h>


typedef struct node{
    struct node *next;
    struct node *prev;
    int data;
}node;


typedef struct{
    struct node *head;
    struct node *tail;
    int size;

}list;


//Prototypes using coursera DSA definitions for naming functions

list *initialize_list();

void destroy_list(list *lst);
void pushFront(list *lst, int value);
void pushBack(list *lst, int value);
int popback(list *lst);






//Tests
void run_all_tests();


void test_initialize_list();

void test_destroy_list();

void test_pushFront();

void test_pushBack();

void test_popBack();