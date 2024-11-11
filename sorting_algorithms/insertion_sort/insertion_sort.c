#include "insertion_sort.h"
#include <stdio.h>
#include <assert.h>

void test_insertion_sort_ascending();
void test_insertion_sort_descending();
void run_all_tests();


void insertion_sort_descending(int *arr, int n){
    int key;
    int j;
    int i;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] < key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}
void insertion_sort_ascending(int *arr, int n){
    int key;
    int j;
    int i;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
    }
}

void run_all_tests(){
    printf("\033[1;33mCommencing Tests...\033[0m\n");
    test_insertion_sort_ascending();
    test_insertion_sort_descending();
    printf("\033[1;32mPassed Tests.\033[0m\n");
}

void test_insertion_sort_ascending(){
    printf("\033[0;33mTesting Insertion Sort Ascending.....\033[0m");
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insertion_sort_ascending(arr, n);
    assert(arr[0] == 1);
    assert(arr[5] == 6);
    printf("\033[0;32mPassed\033[0m\n");


}
void test_insertion_sort_descending(){
    printf("\033[0;33mTesting Insertion Sort Descending....\033[0m");
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insertion_sort_descending(arr, n);
    assert(arr[0] == 6);
    assert(arr[5] == 1);
    printf("\033[0;32mPassed\033[0m\n");


}


int main(){
    run_all_tests();

    return 0;
}