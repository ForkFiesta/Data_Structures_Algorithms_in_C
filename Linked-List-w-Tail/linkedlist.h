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
bool find(list *lst, int key);
void erase(list *lst, int key);
bool is_empty(list *lst);
node *getNthNode(list *lst, int n);
void addAfter(node *nd, int key);
void addBefore(node *nd, int key);






//Tests
void run_all_tests();


void test_initialize_list();

void test_destroy_list();

void test_pushFront();

void test_is_empty();

void test_pushBack();

void test_popBack();

void test_find();

void test_erase();

void test_getNthNode();

void test_addAfter();

void test_addBefore();


