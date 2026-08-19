#include <stdio.h>
#include <stdlib.h>

/**
 * struct node - a single student record in the BST
 * @id: student ID number (used as the BST key)
 * @grade: student's grade
 * @left: pointer to left child (smaller IDs)
 * @right: pointer to right child (larger IDs)
 */
struct node
{
    int id;
    float grade;
    struct node *left;
    struct node *right;
};

/* Function prototypes */
struct node *new_node(int id, float grade);

int main(void)
{
    return (0);
}

/**
 * new_node - allocate and initialize a new BST node
 * @id: student ID to store
 * @grade: student grade to store
 *
 * Return: pointer to the new node, or NULL on allocation failure
 */
struct node *new_node(int id, float grade)
{
    struct node *n = malloc(sizeof(struct node));

    if (n == NULL)
        return (NULL);

    n->id = id;
    n->grade = grade;
    n->left = NULL;
    n->right = NULL;

    return (n);
}