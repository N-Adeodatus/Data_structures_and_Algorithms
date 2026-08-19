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
struct node *insert(struct node *root, int id, float grade);
void inorder_print(struct node *root);
struct node *search(struct node *root, int id);
struct node *find_min(struct node *root);

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

/**
 * insert - insert a new student record into the BST
 * @root: root of the (sub)tree to insert into
 * @id: student ID to insert (BST key)
 * @grade: student grade to store
 *
 * Return: pointer to the (possibly new) root of this subtree
 */
struct node *insert(struct node *root, int id, float grade)
{
    if (root == NULL)
        return (new_node(id, grade));

    if (id < root->id)
        root->left = insert(root->left, id, grade);
    else if (id > root->id)
        root->right = insert(root->right, id, grade);

    return (root);
}

/**
 * inorder_print - print all records in sorted order by id
 * @root: root of the (sub)tree to print
 */
void inorder_print(struct node *root)
{
    if (root == NULL)
        return;

    inorder_print(root->left);
    printf("ID: %d, Grade: %.2f\n", root->id, root->grade);
    inorder_print(root->right);
}

/**
 * search - find a student record by id
 * @root: root of the (sub)tree to search
 * @id: student id to find
 *
 * Return: pointer to the matching node, or NULL if not found
 */
struct node *search(struct node *root, int id)
{
    if (root == NULL || root->id == id)
        return (root);

    if (id < root->id)
        return (search(root->left, id));

    return (search(root->right, id));
}

/**
 * find_min - find the node with the smallest id in a (sub)tree
 * @root: root of the (sub)tree to search
 *
 * Return: pointer to the node with the smallest id, or NULL if empty
 */
struct node *find_min(struct node *root)
{
    if (root == NULL)
        return (NULL);

    while (root->left != NULL)
        root = root->left;

    return (root);
}