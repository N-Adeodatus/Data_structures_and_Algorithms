#include<stdio.h>
#include<stdlib.h>

typedef struct number_node{
    int number;
    struct number_node *left;
    struct number_node *right;
} node_n;

node_n *create_node(int num);
void insert(node_n **root, int num);
void inorder(node_n *root);
node_n *search(node_n *root, int target);
node_n *find_min(node_n *root);
node_n *find_max(node_n *root);
void delete(node_n **root, int num);
void free_tree(node_n *root);
int main(void) {
    // Create the root node
    node_n *root = create_node(50);

    // Insert nodes in the tree
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);
    insert(&root, 75);

    // Print in ascending order
    inorder(root);

    // Search for a node
    node_n *found = search(root, 60);
    if(found == NULL) {
        printf("Value Not Found.\n");
    }
    else {
        printf("value %d is found\n", found->number);
    }

    // Finding the min and max values from the tree
    node_n *min = find_min(root);
    node_n *max = find_max(root);

    if(min == NULL) {
        printf("Tree is empty");
    }
    else {
        printf("The minimum value in the tree is %d\n", min->number);
    }

    if(max == NULL) {
        printf("Tree is empty");
    }
    else {
        printf("The maximum value in the tree is %d\n", max->number);
    }

    // Delete a node with value 70
    delete(&(root), 70);
    printf("After deleting 70:\n");
    inorder(root);

    // Free the tree
    free_tree(root);
    printf("Tree Freed Successfully\n");
    return 0;
}

node_n *create_node(int num) {
    node_n *new_node = malloc(sizeof(node_n));
    if(new_node == NULL) {
        return NULL;
    }

    new_node->number = num;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void insert(node_n **root, int num) {
    if(*root == NULL) {
        *root = create_node(num);
        return;
    }

    if(num < (*root)->number) {
        insert(&((*root)->left), num);
    }
    else if(num > (*root)->number) {
        insert(&((*root)->right), num);
    }
}

void inorder(node_n *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d\n",root->number);
    inorder(root->right);
}

node_n *search(node_n *root, int target) {
    if(root == NULL) {
        return NULL;
    }

    if(target < root->number) {
        search(root->left, target);
    }
    else if(target > root->number) {
        search(root->right, target);
    }
    else {
        return root;
    }
    
}

node_n *find_min(node_n *root) {
    if(root == NULL) {
        return NULL;
    }
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

node_n *find_max(node_n *root) {
    if(root == NULL) {
        return NULL;
    }

    while(root->right != NULL) {
        root = root->right;
    }
    return root;
}

void delete(node_n **root, int num) {
    if(*root == NULL) {
        return;
    }

    if(*root == NULL) {
        return;
    }

    if(num < (*root)->number) {
        delete(&((*root)->left), num);
    }
    else if(num > (*root)->number) {
        delete(&((*root)->right), num);
    }
    else {
        if((*root)->right == NULL) {
            node_n *temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else if((*root)->left == NULL) {
            node_n *temp = *root;
            *root = (*root)->right;
            free(temp);
        }
        else {
            node_n *min = find_min((*root)->right);
            (*root)->number = min->number;
            delete(&((*root)->right), min->number);
        }
    }

    
}

void free_tree(node_n *root) {
    if(root == NULL){
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
