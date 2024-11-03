# Linked List Implementation in C

This repository contains an implementation of a singly linked list in C. The implementation includes functions for initialization, insertion, deletion, searching, and other utility operations. Additionally, a set of test functions is provided to verify the correctness of the linked list operations.

## Files

- `linked_list.c`: Contains the implementation of the singly linked list and its associated functions.
- `linked_list.h`: Header file that declares the linked list structure and function prototypes.
- `main.c`: Contains the `main` function that runs all the test functions.

## Functions

### Initialization

- `list *initialize_list()`: Initializes a new linked list.

### Insertion

- `void push(list *lst, int value)`: Inserts a new value at the beginning of the list.
- `void insert_at_end(list *lst, int value)`: Inserts a new value at the end of the list.

### Deletion

- `void destroy_list(list *lst)`: Destroys the list and frees all allocated memory.
- `int pop(list *lst)`: Removes and returns the value at the beginning of the list.
- `void remove_value(list *lst, int value)`: Removes the first occurrence of a value from the list.
- `void remove_values(list *lst, int value)`: Removes all occurrences of a value from the list.
- `int remove_from_end(list *lst)`: Removes and returns the value at the end of the list.
- `int remove_from_index(list *lst, int index)`: Removes and returns the value at a specified index in the list.

### Searching

- `int search(list *lst, int value)`: Searches for a value in the list.
- `int find_largest(list *lst)`: Finds and returns the largest value in the list.
- `int find_smallest(list *lst)`: Finds and returns the smallest value in the list.
- `int get_value_from_index(list *lst, int index)`: Returns the value at a specified index in the list.

### Testing

- `void run_all_tests()`: Runs all test functions to verify the correctness of the linked list operations.
- Individual test functions for each operation (e.g., `test_push()`, `test_pop()`, `test_search()`, etc.).

## How to Run

1. Clone the repository:

   ```sh
   git clone https://github.com/yourusername/linked_list_c.git
   ```

2. Navigate to the project directory:

   ```sh
   cd linked_list_c
   ```

3. Compile the program:

   ```sh
   gcc -o linked_list main.c linked_list.c
   ```

4. Run the program:
   ```sh
   ./linked_list
   ```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Author

Raul Resendez
