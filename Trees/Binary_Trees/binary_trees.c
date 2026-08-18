#include <stdio.h>
#include <stdlib.h>

/* Struct definition */
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node_t;

/* Prototypes */
node_t *create_node(int data);
void preorder(node_t *root);
void inorder(node_t *root);
void postorder(node_t *root);
int height(node_t *root);
int count_nodes(node_t *root);
int count_leaves(node_t *root);
int sum_tree(node_t *root);
node_t *search(node_t *root, int target);
void free_tree(node_t *root);

int main(void)
{
    node_t *root = create_node(1);

    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->right = create_node(6);

    return (0);
}

/* Function definitions */

node_t *create_node(int data)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return (NULL);

    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return (new_node);
}