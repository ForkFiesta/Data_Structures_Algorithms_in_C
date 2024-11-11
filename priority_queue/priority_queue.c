#include "priority_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>



PriorityQueue *initialize_priority_queue(){
    PriorityQueue *pq = malloc(sizeof(PriorityQueue));
    if(pq==NULL){
        fprintf(stderr,"Memory allocation error.\n");
        return NULL;
    }
    pq->size = 0;
    return pq;

}
void siftUp(PriorityQueue *pq, int index){
    while(index>1 && pq->binary_heap[getParent(index)] < pq->binary_heap[index]){
        swap(&pq->binary_heap[getParent(index)], &pq->binary_heap[index]);
        index = getParent(index);
    }
}
void siftDown(PriorityQueue *pq, int index){
    int maxIndex = index;
    int leftChildIndex = getLeftChild(index);
    if (leftChildIndex <= pq->size && pq->binary_heap[leftChildIndex]>pq->binary_heap[maxIndex]){
        maxIndex = leftChildIndex;
    }
    int rightChildIndex = getRightChild(index);
    if(rightChildIndex <= pq->size && pq->binary_heap[rightChildIndex]>pq->binary_heap[maxIndex]){
        maxIndex = rightChildIndex;
    }
    if (index != maxIndex){
        swap(&pq->binary_heap[index], &pq->binary_heap[maxIndex]);
        siftDown(pq, maxIndex);
    }
}
void insert(PriorityQueue *pq, int value){
    if(pq->size == MAX_SIZE){
        fprintf(stderr, "Queue is full\n");
        return;
    }
    pq->size++;
    pq->binary_heap[pq->size] = value;
    siftUp(pq, pq->size); 
}
int extractMax(PriorityQueue *pq){
    int result = pq->binary_heap[1];
    pq->binary_heap[1] = pq->binary_heap[pq->size];
    pq->size--;
    siftDown(pq, 1);
    return result;
}
void removeItem(PriorityQueue *pq, int target){
    pq->binary_heap[target] = INT_MAX;
    siftUp(pq, target);
    extractMax(pq);
}

void changePriority(PriorityQueue *pq, int index, int priority){
    int oldP = pq->binary_heap[index];
    pq->binary_heap[index] = priority;
    if(priority > oldP){
        siftUp(pq, index);
    }else{
        siftDown(pq, index);
    }
}
void heapSort(int *arr, int n){
    PriorityQueue *pq = initialize_priority_queue();
    for(int i = 1; i < n; i++){
        insert(pq, arr[i]);
    }
    for(int i = n-1; i >= 1; i--){
        arr[i] = extractMax(pq);
    }
    free(pq);
}
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}
int getParent(int i){
    if (i<=1){
        fprintf(stderr, "Cannot get parent of Index.\n");
        return -1;
    }
    return (i/2);
}
int getLeftChild(int i){
    return (2*i);
}
int getRightChild(int i){
    return getLeftChild(i)+1;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

