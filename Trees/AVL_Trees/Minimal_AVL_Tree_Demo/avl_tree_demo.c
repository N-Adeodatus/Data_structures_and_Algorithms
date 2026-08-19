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
int max(int a, int b);
struct node *right_rotate(struct node *y);
struct node *left_rotate(struct node *x);
struct node *insert(struct node *root, int data);
void print_tree(struct node *root, int space);

int main(void)
{
    struct node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);

    printf("After inserting 30, 20:");
    print_tree(root, 0);

    printf("\n--------------------\n");
    printf("Inserting 10 (this will force a rotation)...\n");

    root = insert(root, 10);

    printf("After inserting 10:");
    print_tree(root, 0);

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

/**
 * max - return the larger of two integers
 * @a: first value
 * @b: second value
 *
 * Return: the larger of a and b
 */
int max(int a, int b)
{
    return (a > b ? a : b);
}

/**
 * right_rotate - rotate a left-heavy subtree right
 * @y: root of the unbalanced subtree
 *
 * Return: new root of the subtree after rotation
 */
struct node *right_rotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return (x);
}

/**
 * left_rotate - rotate a right-heavy subtree left
 * @x: root of the unbalanced subtree
 *
 * Return: new root of the subtree after rotation
 */
struct node *left_rotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return (y);
}

/**
 * insert - insert a value into the AVL tree, rebalancing as needed
 * @root: root of the (sub)tree to insert into
 * @data: value to insert
 *
 * Return: pointer to the (possibly new) root of this subtree
 */
struct node *insert(struct node *root, int data)
{
    int balance;

    if (root == NULL)
        return (new_node(data));

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return (root);

    root->height = 1 + max(height(root->left), height(root->right));

    balance = get_balance(root);

    if (balance > 1 && data < root->left->data)
        return (right_rotate(root));

    if (balance < -1 && data > root->right->data)
        return (left_rotate(root));

    if (balance > 1 && data > root->left->data)
    {
        root->left = left_rotate(root->left);
        return (right_rotate(root));
    }

    if (balance < -1 && data < root->right->data)
    {
        root->right = right_rotate(root->right);
        return (left_rotate(root));
    }

    return (root);
}

/**
 * print_tree - print the tree sideways to visualize its shape
 * @root: root of the (sub)tree to print
 * @space: current indentation level
 */
void print_tree(struct node *root, int space)
{
    int i;

    if (root == NULL)
        return;

    space += 6;

    print_tree(root->right, space);

    printf("\n");
    for (i = 6; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    print_tree(root->left, space);
}