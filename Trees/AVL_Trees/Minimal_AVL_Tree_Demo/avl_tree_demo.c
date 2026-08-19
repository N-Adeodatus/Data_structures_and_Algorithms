#include <stdio.h>
#include <stdlib.h>

/**
 * struct node - a node in the AVL tree
 * @data: the value stored (also the BST ordering key)
 * @height: height of the subtree rooted at this node
 * @left: pointer to left child (smaller values)
 * @right: pointer to right child (larger values)
 */
struct node
{
    int data;
    int height;
    struct node *left;
    struct node *right;
};