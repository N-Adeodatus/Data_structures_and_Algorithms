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

/* Function prototypes */
struct node *new_node(int data);
int height(struct node *n);
int get_balance(struct node *n);

int main(void)
{
    return (0);
}

/**
 * new_node - allocate and initialize a new AVL node
 * @data: value to store
 *
 * Return: pointer to the new node, or NULL on allocation failure
 */
struct node *new_node(int data)
{
    struct node *n = malloc(sizeof(struct node));

    if (n == NULL)
        return (NULL);

    n->data = data;
    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return (n);
}

/**
 * height - safely get the height of a subtree
 * @n: root of the subtree (may be NULL)
 *
 * Return: height of the subtree, or 0 if n is NULL
 */
int height(struct node *n)
{
    if (n == NULL)
        return (0);

    return (n->height);
}

/**
 * get_balance - compute the balance factor of a node
 * @n: node to check (may be NULL)
 *
 * Return: height(left) - height(right), or 0 if n is NULL
 */
int get_balance(struct node *n)
{
    if (n == NULL)
        return (0);

    return (height(n->left) - height(n->right));
}