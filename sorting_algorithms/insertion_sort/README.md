# Insertion Sort

This repository contains an implementation of the Insertion Sort algorithm in C. The implementation includes functions to sort arrays in both ascending and descending order, as well as test functions to verify the correctness of the sorting functions.

## Files

- `insertion_sort.c`: Contains the implementation of the insertion sort algorithm and test functions.
- `insertion_sort.h`: Header file with function declarations for the insertion sort functions.

## Functions

### `void insertion_sort_ascending(int *arr, int n)`

Sorts an array of integers in ascending order using the insertion sort algorithm.

- `arr`: Pointer to the array of integers to be sorted.
- `n`: Number of elements in the array.

### `void insertion_sort_descending(int *arr, int n)`

Sorts an array of integers in descending order using the insertion sort algorithm.

- `arr`: Pointer to the array of integers to be sorted.
- `n`: Number of elements in the array.

### `void run_all_tests()`

Runs all test functions to verify the correctness of the insertion sort functions.

## Usage

To use the insertion sort functions, include the `insertion_sort.h` header file in your program and call the desired sorting function with the appropriate arguments.

Example:

```c
#include "insertion_sort.h"

int main() {
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = 6;

    insertion_sort_ascending(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

## Testing

The `run_all_tests` function runs the test cases for both ascending and descending insertion sort functions. The test results are printed to the console.

To run the tests, simply call the `run_all_tests` function in your `main` function.

Example:

```c
#include "insertion_sort.h"

int main() {
    run_all_tests();
    return 0;
}
```

## License

This project is licensed under the MIT License.
