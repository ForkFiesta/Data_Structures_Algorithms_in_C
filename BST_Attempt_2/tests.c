#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Helper function to check if an array matches expected values for traversal tests
void assert_array_equal(int *array, int *expected, int size) {
    for (int i = 0; i < size; i++) {
        assert(array[i] == expected[i]);
    }
}

// 1. Test tree creation
void test_create_tree() {
    BinarySearchTree *tree = create_tree();
    assert(tree != NULL);
    assert(tree->root == NULL);
    destroyTree(tree);
}

void test_create_node() {
    BSTNode *node = create_node(10);
    assert(node != NULL);
    assert(node->data == 10);
    assert(node->left == NULL);
    assert(node->right == NULL);
    free(node);
}

// 2. Test insertion and structure
void test_insert_and_structure() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 3);
    insert(tree, 7);
    assert(tree->root->data == 10);
    assert(tree->root->left->data == 5);
    assert(tree->root->right->data == 15);
    assert(tree->root->left->left->data == 3);
    assert(tree->root->left->right->data == 7);
    destroyTree(tree);
}

// 3. Test search function
void test_search_existing_and_nonexisting_nodes() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    assert(search(tree, 10) == true);
    assert(search(tree, 5) == true);
    assert(search(tree, 15) == true);
    assert(search(tree, 20) == false);
    destroyTree(tree);
}

// 4. Test finding min and max
void test_find_min() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    assert(findMin(tree) == 5);
    destroyTree(tree);
}

void test_find_max() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    assert(findMax(tree) == 15);
    destroyTree(tree);
}

// 5. Test height calculation
void test_find_height() {
    BinarySearchTree *tree = create_tree();
    assert(findHeight(tree) == -1); // empty tree
    insert(tree, 10);
    assert(findHeight(tree) == 0);  // single node
    insert(tree, 5);
    insert(tree, 15);
    assert(findHeight(tree) == 1);  // two levels
    destroyTree(tree);
}

// 6. Test BST property validation
void test_is_binary_search_tree() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    assert(isBinarySearchTree(tree) == true);
    destroyTree(tree);
}

// 7. Test traversals
void test_bfs_traversal() {
    // Manual verification for BFS output may be required, or you could capture printed output.
    // For example, by redirecting stdout or using a traversal callback to collect data.
}

void test_dfs_traversals() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 3);
    insert(tree, 7);

    printf("PreOrder: ");
    DFS_PreOrder(tree);
    printf("\nInOrder: ");
    DFS_InOrder(tree);
    printf("\nPostOrder: ");
    DFS_PostOrder(tree);
    printf("\n");

    destroyTree(tree);
}

// 8. Test deletion
void test_delete_leaf_node() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    delete(tree, 5);
    assert(search(tree, 5) == false);
    destroyTree(tree);
}

void test_delete_node_with_one_child() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 12);
    delete(tree, 15);
    assert(search(tree, 15) == false);
    assert(search(tree, 12) == true);
    destroyTree(tree);
}

void test_delete_node_with_two_children() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    insert(tree, 12);
    insert(tree, 18);
    delete(tree, 15);
    assert(search(tree, 15) == false);
    assert(search(tree, 12) == true);
    assert(search(tree, 18) == true);
    destroyTree(tree);
}

void test_delete_root_node() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    delete(tree, 10);
    assert(search(tree, 10) == false);
    assert(isBinarySearchTree(tree) == true);
    destroyTree(tree);
}

// 9. Test memory cleanup
void test_destroy_tree() {
    BinarySearchTree *tree = create_tree();
    insert(tree, 10);
    insert(tree, 5);
    insert(tree, 15);
    destroyTree(tree);
    // No assertions here, just verifying no memory leaks with tools like Valgrind
}

// Run all tests
void run_all_tests() {
    printf("Running all tests...\n");
    test_create_tree();
    test_create_node();
    test_insert_and_structure();
    test_search_existing_and_nonexisting_nodes();
    test_find_min();
    test_find_max();
    test_find_height();
    test_is_binary_search_tree();
    test_bfs_traversal();
    test_dfs_traversals();
    test_delete_leaf_node();
    test_delete_node_with_one_child();
    test_delete_node_with_two_children();
    test_delete_root_node();
    test_destroy_tree();
    printf("All tests passed successfully.\n");
}

int main(){
    run_all_tests();
    return 0;
}
