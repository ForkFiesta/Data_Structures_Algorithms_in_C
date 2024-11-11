#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#define MAX_SIZE 100

typedef struct PriorityQueue{
    int binary_heap[MAX_SIZE];
    int size;
}PriorityQueue;


PriorityQueue *initialize_priority_queue();
void siftUp(PriorityQueue *pq, int index);
void siftDown(PriorityQueue *pq, int index);
void insert(PriorityQueue *pq, int value);
int extractMax(PriorityQueue *pq);
void removeItem(PriorityQueue *pq, int target);
void changePriority(PriorityQueue *pq, int index, int priority);
void heapSort(int *arr, int n);
void buildHeap(int *arr, int n);
void swap(int *a, int *b);

int getParent(int i);
int getLeftChild(int i);
int getRightChild(int i);



#endif