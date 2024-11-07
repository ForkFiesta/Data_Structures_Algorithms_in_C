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

## Unit Tests

The following unit tests are included to verify the correctness of the binary search implementation:

- `test_binary_search_found`: Tests if the function correctly finds an element in the array.
- `test_binary_search_not_found`: Tests if the function correctly returns -1 when the element is not in the array.
- `test_binary_search_empty_array`: Tests if the function correctly handles an empty array.
- `test_binary_search_null_array`: Tests if the function correctly handles a null array.
- `test_binary_search_single_element_found`: Tests if the function correctly finds an element in a single-element array.
- `test_binary_search_single_element_not_found`: Tests if the function correctly returns -1 when the single element is not the target.
- `test_binary_search_first_element`: Tests if the function correctly finds the first element in the array.
- `test_binary_search_last_element`: Tests if the function correctly finds the last element in the array.
- `test_binary_search_duplicates`: Tests if the function correctly handles arrays with duplicate elements.
- `test_binary_search_negative_numbers`: Tests if the function correctly handles arrays with negative numbers.
- `test_binary_search_large_array`: Tests if the function correctly handles a large array.
- `test_binary_search_middle_element`: Tests if the function correctly finds the middle element in the array.

## Running the Tests

To compile and run the tests, use the following commands:

```sh
gcc -o tests binary_search.c tests.c main.c
./tests
```

This will compile the source files and run the unit tests, printing the results to the console.
