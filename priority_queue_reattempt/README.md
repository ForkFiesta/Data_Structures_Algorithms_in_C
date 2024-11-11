# Priority Queue Implementation in C

This project implements a priority queue using a binary heap in C. It includes functions for common heap operations such as insertion, extraction of the maximum element, and heap sort. The project also includes a set of tests to verify the correctness of the implementation.

## Files

- `pq.h`: Header file containing the declarations of the priority queue functions and the `PRIORITY_QUEUE` structure.
- `pq.c`: Implementation of the priority queue functions.
- `tests.h`: Header file containing the declarations of the test functions.
- `tests.c`: Implementation of the test functions.
- `README.md`: This file, providing an overview of the project.

## Functions

### Priority Queue Functions

- `PRIORITY_QUEUE *initialize_pq()`: Initializes a new priority queue.
- `void siftUp(PRIORITY_QUEUE *pq, int i)`: Sifts up the element at index `i` to maintain the heap property.
- `void siftDown(PRIORITY_QUEUE *pq, int i)`: Sifts down the element at index `i` to maintain the heap property.
- `int extractMax(PRIORITY_QUEUE *pq)`: Extracts and returns the maximum element from the priority queue.
- `void insert(PRIORITY_QUEUE *pq, int priority)`: Inserts a new element with the given priority into the priority queue.
- `void removeItem(PRIORITY_QUEUE *pq, int target)`: Removes the element at the given index from the priority queue.
- `void changePriority(PRIORITY_QUEUE *pq, int index, int priority)`: Changes the priority of the element at the given index.
- `void heapSort(int arr[], int n)`: Sorts an array using heap sort.
- `void heapify(int arr[], int n, int i)`: Maintains the heap property for the subtree rooted at index `i`.
- `void buildHeap(int arr[], int n)`: Builds a heap from an array.

### Test Functions

- `void test_initialize_pq()`: Tests the `initialize_pq` function.
- `void test_siftUp()`: Tests the `siftUp` function.
- `void test_siftDown()`: Tests the `siftDown` function.
- `void test_extractMax()`: Tests the `extractMax` function.
- `void test_insert()`: Tests the `insert` function.
- `void test_removeItem()`: Tests the `removeItem` function.
- `void test_changePriority()`: Tests the `changePriority` function.
- `void test_heapSort()`: Tests the `heapSort` function.
- `void test_heapify()`: Tests the `heapify` function.
- `void test_buildHeap()`: Tests the `buildHeap` function.

## Running the Tests

To compile and run the tests, use the following commands:

```sh
gcc -o tests pq.c tests.c
./tests
```
