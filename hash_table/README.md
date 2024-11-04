# Hash Table Implementation in C

This repository contains an implementation of a hash table in C. The hash table supports basic operations such as adding a key-value pair, fetching a value by key, and removing a key. Additionally, it includes a set of tests to verify the correctness of the implementation.

## Files

- `hash_table.h`: Header file containing the declarations of the hash table structures and functions.
- `hash_table.c`: Source file containing the implementation of the hash table functions.
- `main.c`: Main file to run the tests.

## Data Structures

### Element

```c
struct element {
    char key[MAX_SIZE];
    char value[MAX_SIZE];
    struct element *next;
};
```

### Table

```c
struct {
    element *hash_table[TABLE_SIZE];
    int capacity;
};
```

## Functions

### Initialization

- `table *initialize_table()`: Initializes a new hash table.

### Hash Function

- `unsigned int hash_function(const char *key)`: Computes the hash value for a given key.

### Add Key

- `void add_key(table *lst, char *key, char *val)`: Adds a key-value pair to the hash table.

### Fetch Value

- `element *fetch_value(table *lst, char *key)`: Fetches the value associated with a given key.

### Remove Key

- `bool remove_key(table *tbl, char *key)`: Removes a key from the hash table.

### Destroy Table

- `void destroy_table(table *tbl)`: Frees all memory associated with the hash table.

### Error Handling

- `void error_exit()`: Prints an error message and exits the program.

## Tests

The implementation includes a set of tests to verify the correctness of the hash table operations. The tests are defined in `hash_table.c` and can be run using the `main` function in `main.c`.

### Test Functions

- `void run_all_tests()`: Runs all the test functions.
- `void test_initialize_table()`: Tests the initialization of the hash table.
- `void test_add_key()`: Tests adding key-value pairs to the hash table.
- `void test_fetch_value()`: Tests fetching values by key.
- `void test_remove_key()`: Tests removing keys from the hash table.

## Running the Tests

To compile and run the tests, use the following commands:

```sh
gcc -o hash_table hash_table.c main.c
./hash_table
```

## License

This project is licensed under the MIT License.
