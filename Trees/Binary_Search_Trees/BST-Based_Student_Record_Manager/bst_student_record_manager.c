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