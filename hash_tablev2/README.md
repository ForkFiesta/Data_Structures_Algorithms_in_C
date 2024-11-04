# Hash Table Implementation in C

This repository contains an implementation of a hash table in C, along with a suite of tests to ensure its correctness.

## Files

- `hash_table.c`: Contains the implementation of the hash table functions.
- `hash_table.h`: Header file containing the declarations for the hash table functions and data structures.
- `main.c`: Entry point of the program, which runs all the tests.

## Data Structures

### Node

```c
struct Node {
    char *key;
    int value;
    struct Node *next;
};
```

### HashTable

```c
struct {
    Node **table;
    int size;
    int count;
};
```

## Functions

### Hash Table Functions

- `unsigned int hash_function(const char *key, int size)`: Computes the hash value for a given key.
- `Node *create_node(char *key, int value)`: Creates a new node with the given key and value.
- `HashTable *create_table()`: Creates a new hash table.
- `void resize(HashTable *tbl)`: Resizes the hash table when the load factor exceeds a certain threshold.
- `void insert(HashTable *tbl, char *key, int value)`: Inserts a key-value pair into the hash table.
- `int search(HashTable *tbl, char *key)`: Searches for a key in the hash table and returns its value.
- `void free_table(HashTable *tbl)`: Frees the memory allocated for the hash table.

### Test Functions

- `void test_create_table()`: Tests the creation of a hash table.
- `void test_insert_and_search()`: Tests the insertion and searching of key-value pairs in the hash table.
- `void test_resize()`: Tests the resizing functionality of the hash table.
- `void test_free_table()`: Tests the freeing of the hash table.
- `void run_all_tests()`: Runs all the test functions.

## Usage

To compile and run the tests, use the following commands:

```sh
gcc -o hash_table hash_table.c main.c
./hash_table
```

## License

This project is licensed under the MIT License.
