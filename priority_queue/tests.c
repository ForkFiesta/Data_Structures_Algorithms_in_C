#include "tests.h"
#include "priority_queue.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>



void run_all_tests(){
    printf("\033[1;33mCommencing Tests\033[0m\n");
    test_initialize_pq();
    test_swap();
    test_insert();
    test_extractMax();
    test_removeItem();
    test_changePriority();
    test_heapSort();
    test_buildHeap();
    printf("\033[1;32mPassed All Tests\033[0m\n");
}

void test_initialize_pq(){
    printf("\033[0;33mTesting Initialize PQ....\033[0m");
    PriorityQueue *pq = initialize_priority_queue();
    assert(pq != NULL);
    assert(pq->size == 0);
    free(pq);
    printf("\033[0;32mPassed\033[0m\n");

}

void test_swap(){
    printf("\033[0;33mTesting Swap.............\033[0m");
    int a = 43;
    int b = 54;
    swap(&a, &b);
    assert(a == 54);
    assert(b == 43);
    printf("\033[0;32mPassed\033[0m\n");

}

void test_insert(){
    printf("\033[0;33mTesting Insert...........\033[0m");
    PriorityQueue *pq = initialize_priority_queue();
    insert(pq, 10);
    insert(pq, 20);
    assert(pq->size == 2);
    assert(pq->binary_heap[1] == 20);
    free(pq);
    printf("\033[0;32mPassed\033[0m\n");
}

void test_extractMax(){
    printf("\033[0;33mTesting Extract Max......\033[0m");
    PriorityQueue *pq = initialize_priority_queue();
    insert(pq, 10);
    insert(pq, 20);
    int max = extractMax(pq);
    assert(max == 20);
    assert(pq->size == 1);
    free(pq);
    printf("\033[0;32mPassed\033[0m\n");
}

void test_removeItem(){
    printf("\033[0;33mTesting Remove Item......\033[0m");
    PriorityQueue *pq = initialize_priority_queue();
    insert(pq, 10);
    insert(pq, 20);
    removeItem(pq, 1);
    assert(pq->size == 1);
    assert(pq->binary_heap[1] == 10);
    free(pq);
    printf("\033[0;32mPassed\033[0m\n");
}

void test_changePriority(){
    printf("\033[0;33mTesting Change Priority..\033[0m");
    PriorityQueue *pq = initialize_priority_queue();
    insert(pq, 10);
    insert(pq, 20);
    changePriority(pq, 1, 5);
    assert(pq->binary_heap[1] == 10);
    free(pq);
    printf("\033[0;32mPassed\033[0m\n");
}

void test_heapSort(){
    printf("\033[0;33mTesting Heap Sort........\033[0m");
    int arr[] = {0, 3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = 10;
    heapSort(arr, n);
    for(int i = 1; i < n-1; i++){
        assert(arr[i] <= arr[i+1]);
    }
    printf("\033[0;32mPassed\033[0m\n");
}


void printArray(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



void test_buildHeap(){
    printf("\033[0;33mTesting Build Heap.......\033[0m");
    int arr[] = {0, 3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = 9;
    buildHeap(arr, n+1);
    for(int i = 1; i <= n/2; i++){
        assert(arr[i] >= arr[2*i]);
        if(2*i+1 <= n) assert(arr[i] >= arr[2*i+1]);
    }
    printf("\033[0;32mPassed\033[0m\n");
}
