# Binary Search Implementation in C

This project implements the binary search algorithm in C and includes unit tests to verify its correctness.

## Files

- `binary_search.c`: Contains the implementation of the binary search algorithm.
- `binary_search.h`: Header file for the binary search function.
- `tests.c`: Contains unit tests for the binary search function.
- `tests.h`: Header file for the unit tests.
- `main.c`: Runs the unit tests.
- `README.md`: This file.

## Binary Search Algorithm

The binary search algorithm searches for a target value within a sorted array. It compares the target value to the middle element of the array. If they are not equal, it eliminates half of the array and repeats the process on the remaining half until the target value is found or the array is exhausted.

## Function

```c
int binary_search(int *arr, int n, int target);
```

This function takes a pointer to the array `arr`, the number of elements in the array `n`, and the `target` value to search for. It returns the index of the target value if found, otherwise, it returns -1.

## Running the Tests

To compile and run the tests, use the following commands:

```sh
gcc -o tests binary_search.c tests.c main.c
./tests
```

This will compile the source files and run the unit tests, printing the results to the console.
