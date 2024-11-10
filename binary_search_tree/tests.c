#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "bst.h"
#include "tests.h"

void run_all_tests() {
    printf("\033[1;33m Running all tests\033[0m\n");
    test_create_node();
    test_insert_and_search();
    test_find_min_max();
    test_find_height();
    test_bfs_traversal();
    test_dfs_traversal();
    test_is_binary_search_tree();
    test_delete_node();
    test_destroy_tree();
    printf("\033[1;32mPassed All Tests Successfully\033[0m\n");
}

void test_create_node() {
    printf("\033[0;33mTesting create_node...\033[0m");
    BSTNode *node = create_node();
    assert(node != NULL);
    free(node);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_insert_and_search() {
    printf("\033[0;33mTesting insert and search...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    assert(root != NULL);
    assert(search(root, 10) == true);
    assert(search(root, 5) == true);
    assert(search(root, 15) == true);
    assert(search(root, 20) == false);
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_find_min_max() {
    printf("\033[0;33mTesting findMin and findMax...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 20);
    assert(findMin(root) == 2);
    assert(findMax(root) == 20);
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_find_height() {
    printf("\033[0;33mTesting findHeight...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    assert(findHeight(root) == 2);
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_bfs_traversal() {
    printf("\033[0;33mTesting BFSTraversal...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    BFSTraversal(root); // Manually verify printed output
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_dfs_traversal() {
    printf("\033[0;33mTesting DFS Traversals...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    DFS_PreOrder(root);  // Manually verify printed output
    DFS_InOrder(root);   // Manually verify printed output
    DFS_PostOrder(root); // Manually verify printed output
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_is_binary_search_tree() {
    printf("\033[0;33mTesting isBinarySearchTree...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    assert(isBinarySearchTree(root) == true);
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_delete_node() {
    printf("\033[0;33mTesting delete...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    root = delete(root, 5);
    assert(search(root, 5) == false);
    root = delete(root, 10);
    assert(search(root, 10) == false);
    destroyTree(root);
    printf("\033[0;32mpassed.\033[0m\n");
}

void test_destroy_tree() {
    printf("\033[0;33mTesting destroyTree...\033[0m");
    BSTNode *root = create_node();
    root->data = 10;
    insert(root, 5);
    insert(root, 15);
    destroyTree(root); // Should free all memory
    printf("\033[0;32mpassed.\033[0m\n");
}
