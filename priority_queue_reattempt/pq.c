#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "pq.h"

/* Static Function Prototypes */

static int getParentIndex(int i);

static int getLeftChildIndex(int i);

static int getRightChildIndex(int i);

static void swap(int *a, int *b);


/* Function Definitions */

PRIORITY_QUEUE *initialize_pq(){
    PRIORITY_QUEUE *pq = malloc(sizeof(PRIORITY_QUEUE));
    if(pq == NULL){
        fprintf(stderr, "Error allocating memory.\n");
        return NULL;
    }
    pq->size = 0;
    return pq;
}


void siftUp(PRIORITY_QUEUE *pq, int i){
    while(i>1 && pq->heap[getParentIndex(i)] < pq->heap[i]){
        swap(&pq->heap[getParentIndex(i)], &pq->heap[i]);
        i = getParentIndex(i);
    }
}

void siftDown(PRIORITY_QUEUE *pq, int i){
    int maxIndex = i;
    int leftChildIndex = getLeftChildIndex(i);
    if(leftChildIndex<=pq->size && pq->heap[leftChildIndex] > pq->heap[maxIndex]){
        maxIndex = leftChildIndex;
    }
    int rightChildIndex = getRightChildIndex(i);
    if(rightChildIndex <= pq->size && pq->heap[rightChildIndex] > pq->heap[maxIndex]){
        maxIndex = rightChildIndex;
    }
    if(maxIndex != i){
        swap(&pq->heap[i], &pq->heap[maxIndex]);
        siftDown(pq, maxIndex);
    }
}


void insert(PRIORITY_QUEUE *pq, int priority){
    pq->size++;
    pq->heap[pq->size] = priority;
    siftUp(pq, pq->size);
}

int extractMax(PRIORITY_QUEUE *pq){
    int result = pq->heap[1];
    pq->heap[1] = pq->heap[pq->size];
    pq->size--;
    siftDown(pq, 1);
    return result;
}

void removeItem(PRIORITY_QUEUE *pq, int target){
    pq->heap[target] = INT_MAX;
    siftUp(pq, target);
    extractMax(pq);
}

void changePriority(PRIORITY_QUEUE *pq, int index, int priority){
    int oldP = pq->heap[index];
    pq->heap[index] = priority;
    if(priority>oldP){
        siftUp(pq, index);
    }
    else{
        siftDown(pq, index);
    }
}

void heapSort(int arr[], int n){
    PRIORITY_QUEUE *pq = initialize_pq();
    if(pq == NULL){
        fprintf(stderr, "Memory allocation error.\n");
        return;
    }
    for(int i = 0; i < n; i++){
        insert(pq, arr[i]);
    }
    for(int j = n-1; j>=0; j--){
        arr[j] = extractMax(pq);
    }
    free(pq);
}


void heapify(int arr[], int n, int i){
    int largest = i;
    int left = getLeftChildIndex(i);
    int right = getRightChildIndex(i);

    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i){
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n){
    for (int i = n / 2; i>=1; i--){
        heapify(arr, n, i);
    }
}






/* Static Function Definitions */

static int getParentIndex(int index){
    if(index<=1){
        fprintf(stderr, "Cannot get parent of root node.\n");
        return -1;
    }
    return (index / 2);
}

static int getLeftChildIndex(int index){
    return (index * 2);
}

static int getRightChildIndex(int index){
    return (getLeftChildIndex(index) + 1);
}



static void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}