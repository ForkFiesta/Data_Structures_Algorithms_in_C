#include <assert.h>
#include <stdio.h>
#include "pq.h"
#include "tests.h"
#include <stdlib.h>

void test_initialize_pq() {
    PRIORITY_QUEUE *pq = initialize_pq();
    assert(pq != NULL);
    assert(pq->size == 0);
    free(pq);
}

void test_siftUp() {
    PRIORITY_QUEUE *pq = initialize_pq();
    pq->heap[1] = 10;
    pq->heap[2] = 20;
    pq->size = 2;
    siftUp(pq, 2);
    assert(pq->heap[1] == 20);
    assert(pq->heap[2] == 10);
    free(pq);
}

void test_siftDown() {
    PRIORITY_QUEUE *pq = initialize_pq();
    pq->heap[1] = 10;
    pq->heap[2] = 20;
    pq->size = 2;
    siftDown(pq, 1);
    assert(pq->heap[1] == 20);
    assert(pq->heap[2] == 10);
    free(pq);
}

void test_extractMax() {
    PRIORITY_QUEUE *pq = initialize_pq();
    insert(pq, 10);
    insert(pq, 20);
    int max = extractMax(pq);
    assert(max == 20);
    assert(pq->size == 1);
    free(pq);
}

void test_insert() {
    PRIORITY_QUEUE *pq = initialize_pq();
    insert(pq, 10);
    assert(pq->size == 1);
    assert(pq->heap[1] == 10);
    insert(pq, 20);
    assert(pq->size == 2);
    assert(pq->heap[1] == 20);
    free(pq);
}

void test_removeItem() {
    PRIORITY_QUEUE *pq = initialize_pq();
    insert(pq, 10);
    insert(pq, 20);
    removeItem(pq, 1);
    assert(pq->size == 1);
    assert(pq->heap[1] == 10);
    free(pq);
}

void test_changePriority() {
    PRIORITY_QUEUE *pq = initialize_pq();
    insert(pq, 10);
    insert(pq, 20);
    changePriority(pq, 1, 5);
    assert(pq->heap[1] == 10);
    changePriority(pq, 1, 25);
    assert(pq->heap[1] == 25);
    free(pq);
}

void test_heapSort() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;
    heapSort(arr, n);
    for (int i = 0; i < n - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
}

void test_heapify() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;
    heapify(arr, n, 0);
    assert(arr[0] == 10);
}

void test_buildHeap() {
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;
    buildHeap(arr, n);
    assert(arr[1] == 10);
}

int main() {
    test_initialize_pq();
    test_siftUp();
    test_siftDown();
    test_extractMax();
    test_insert();
    test_removeItem();
    test_changePriority();
    test_heapSort();
    test_heapify();
    test_buildHeap();
    printf("All tests passed!\n");
    return 0;
}