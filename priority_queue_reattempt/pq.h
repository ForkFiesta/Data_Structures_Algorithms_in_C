#ifndef PQ_H
#define PQ_H
#define MAX_SIZE 100

typedef struct PRIORITY_QUEUE{
    int heap[100];
    int size;
}PRIORITY_QUEUE;

PRIORITY_QUEUE *initialize_pq();

void siftUp(PRIORITY_QUEUE *pq, int i);

void siftDown(PRIORITY_QUEUE *pq, int i);

int extractMax(PRIORITY_QUEUE *pq);

void insert(PRIORITY_QUEUE *pq, int priority);

void removeItem(PRIORITY_QUEUE *pq, int target);

void changePriority(PRIORITY_QUEUE *pq, int index, int priority);

void heapSort(int arr[], int n);

void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);




#endif