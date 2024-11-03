#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

list *initialize_list(){
    list *lst = malloc(sizeof(list));
    if(lst==NULL){
        printf("Error allocating memory. Ending program\n");
        exit(EXIT_FAILURE);
    }

    lst->size = 0;
    lst->head = NULL;
}









/* Tests */

void run_all_tests(){
    printf("\033[1;33m Running all tests\033[0m\n");
    test_initalize_list();
    test_push();
    test_destroy_list();
    test_pop();
    test_search();
    test_remove_values();
    test_remove_value();
    test_remove_values();
    test_remove_from_end();
    test_insert_at_end();
    test_find_smallest();
    test_find_largest();
    test_get_value_from_index();
    test_remove_from_index();
    printf("\033[1;32mPassed All Tests Succesfully\033[0m\n");

}

void test_initalize_list(){
    printf("\033[0;33mTesting initalize list...\n");
    list *test = initialize_list();
    assert(test != NULL && test->head == NULL && test->size==0);
    destroy_list(test);


}

void test_push(){
    printf("Testing push ...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(test->size==7 && test->head->data==55 && test->head->next->data == 12);
    destroy_list(test);

}


void test_destroy_list(){
    printf("Testing Destroy List...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    destroy_list(test);
    assert(test->head == NULL);
}

void test_pop(){
    printf("Testing pop()...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(pop(test)==55);
    destroy_list(test);

}

void test_search(){
    printf("Testing search ... \n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 55);
    assert(search(test, 2) == 1);
    destroy_list(test);

}

void test_remove_values(){
    printf("Testing Remove_Values...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(search(test, 3)==1);
    remove_values(test, 3);
    assert(search(test, 3)== -1);
    destroy_list(test);
}


void test_remove_value(){
    printf("Testing Remove First Value Found...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    remove_value(test, 3);
    assert(test->head->data==12 && search(test, 3) == 1);
    destroy_list(test);

}


void test_remove_from_end(){
    printf("Testing Removing from End...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);

    int tv = remove_from_end(test);
    assert(tv == 3);

}

void test_insert_at_end(){
    printf("Testing Insert at end...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    insert_at_end(test, 96);
    remove_value(test, 3);
    assert(test->head->data==12 && search(test, 3) == 1);
    destroy_list(test);
}


void test_find_smallest(){
     printf("Testing Find Smallest...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(find_smallest(test)==2);
    destroy_list(test);
}


void test_find_largest(){
     printf("Testing Find Largest...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(find_smallest(test)==12);
    destroy_list(test);

}


void test_remove_from_index(){
    printf("Testing Remove from Index...\033[0m\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(remove_from_index(test, 1) == 12);
    destroy_list(test);

}

void test_get_value_from_index(){
    printf("Testing Get Value from Index...\n");
    list *test = initialize_list();
    push(test, 3);
    push(test, 5);
    push(test, 9);
    push(test, 2);
    push(test, 7);
    push(test, 12);
    push(test, 3);
    assert(get_value_from_index(test, 3) == 2);
    destroy_list(test);

}





