# Linked List with Tail

This repository contains an implementation of a doubly linked list with a tail pointer in C. The list supports various operations such as insertion, deletion, and search.

## Files

- `linkedlist.h`: Header file containing the definitions and function prototypes for the linked list.
- `linkedlist.c`: Source file containing the implementation of the linked list functions.
- `main.c`: Source file containing the main function to run all tests.

## Data Structures

### Node

```c
struct node {
    struct node *next; /**< Pointer to the next node in the list */
    struct node *prev; /**< Pointer to the previous node in the list */
    int data;          /**< Data stored in the node */
};
```

### List

```c
struct list {
    struct node *head; /**< Pointer to the head node of the list */
    struct node *tail; /**< Pointer to the tail node of the list */
    int size;          /**< Size of the list */
};
```

## Functions

### Initialization and Destruction

- `list *initialize_list()`: Initialize a new doubly linked list.
- `void destroy_list(list *lst)`: Destroy a doubly linked list and free its memory.

### Insertion

- `void pushFront(list *lst, int value)`: Insert a new node with the given value at the front of the list.
- `void pushBack(list *lst, int value)`: Insert a new node with the given value at the back of the list.
- `void addAfter(node *nd, int key)`: Add a new node with the given key after the specified node.
- `void addBefore(node *nd, int key)`: Add a new node with the given key before the specified node.

### Deletion

- `int popback(list *lst)`: Remove and return the value of the node at the back of the list.
- `void erase(list *lst, int key)`: Remove a node with the given key from the list.

### Search

- `bool find(list *lst, int key)`: Find a node with the given key in the list.
- `node *getNthNode(list *lst, int n)`: Get the nth node in the list.

### Utility

- `bool is_empty(list *lst)`: Check if the list is empty.

## Tests

The repository includes a set of tests to verify the correctness of the linked list implementation. The tests are defined in `linkedlist.c` and can be run using the `main` function in `main.c`.

### Test Functions

- `void run_all_tests()`: Run all tests for the linked list implementation.
- `void test_initialize_list()`: Test the `initialize_list` function.
- `void test_destroy_list()`: Test the `destroy_list` function.
- `void test_pushFront()`: Test the `pushFront` function.
- `void test_pushBack()`: Test the `pushBack` function.
- `void test_popBack()`: Test the `popback` function.
- `void test_find()`: Test the `find` function.
- `void test_erase()`: Test the `erase` function.
- `void test_getNthNode()`: Test the `getNthNode` function.
- `void test_addAfter()`: Test the `addAfter` function.
- `void test_addBefore()`: Test the `addBefore` function.
- `void test_is_empty()`: Test the `is_empty` function.

## Running the Tests

To run the tests, compile the source files and execute the resulting binary:

```sh
gcc -o linkedlist linkedlist.c main.c
./linkedlist
```

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
