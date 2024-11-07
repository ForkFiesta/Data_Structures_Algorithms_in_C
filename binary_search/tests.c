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

void test_binary_search_single_element_found() {
    int arr[] = {5};
    int result = binary_search(arr, 1, 5);
    assert(result == 0);
    printf("test_binary_search_single_element_found passed.\n");
}

void test_binary_search_single_element_not_found() {
    int arr[] = {5};
    int result = binary_search(arr, 1, 3);
    assert(result == -1);
    printf("test_binary_search_single_element_not_found passed.\n");
}

void test_binary_search_first_element() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = binary_search(arr, 5, 1);
    assert(result == 0);
    printf("test_binary_search_first_element passed.\n");
}

void test_binary_search_last_element() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = binary_search(arr, 5, 5);
    assert(result == 4);
    printf("test_binary_search_last_element passed.\n");
}

void test_binary_search_duplicates() {
    int arr[] = {1, 2, 2, 2, 3};
    int result = binary_search(arr, 5, 2);
    assert(result >= 1 && result <= 3);  // Accept any valid index of `2`
    printf("test_binary_search_duplicates passed.\n");
}

void test_binary_search_negative_numbers() {
    int arr[] = {-3, -2, -1, 0, 1};
    int result = binary_search(arr, 5, -2);
    assert(result == 1);
    printf("test_binary_search_negative_numbers passed.\n");
}

void test_binary_search_large_array() {
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    int result = binary_search(arr, 1000, 500);
    assert(result == 500);
    printf("test_binary_search_large_array passed.\n");
}

void test_binary_search_middle_element() {
    int arr[] = {1, 2, 3, 4, 5};
    int result = binary_search(arr, 5, 3);
    assert(result == 2);
    printf("test_binary_search_middle_element passed.\n");
}

void run_all_tests() {
    test_binary_search_found();
    test_binary_search_not_found();
    test_binary_search_empty_array();
    test_binary_search_null_array();
    test_binary_search_single_element_found();
    test_binary_search_single_element_not_found();
    test_binary_search_first_element();
    test_binary_search_last_element();
    test_binary_search_duplicates();
    test_binary_search_negative_numbers();
    test_binary_search_large_array();
    test_binary_search_middle_element();
    printf("All binary search tests passed.\n");
}
