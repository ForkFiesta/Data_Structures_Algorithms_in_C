#include <stdio.h>
#include <assert.h>
#include "binary_search.h"
#include "tests.h"

void test_binary_search_found() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = binary_search(arr, 5, 3);
    assert(result == 2);
    printf("test_binary_search_found passed.\n");
}

void test_binary_search_not_found() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = binary_search(arr, 5, 6);
    assert(result == -1);
    printf("test_binary_search_not_found passed.\n");
}

void test_binary_search_empty_array() {
    int arr[] = {};
    int result = binary_search(arr, 0, 3);
    assert(result == -1);
    printf("test_binary_search_empty_array passed.\n");
}

void test_binary_search_null_array() {
    int *arr = NULL;
    int result = binary_search(arr, 5, 3);
    assert(result == -1);
    printf("test_binary_search_null_array passed.\n");
}

