#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct family_member{
    char name[80];
    struct family_member *left;
    struct family_member *right;
} member;

member *create_member(char *member_name);
void print_family(member *root);
void free_the_family_tree(member *root);
int count_members(member *root);
int count_generations(member *root);
int main() {
    // create root node(handle to the tree) and store the pointer to it
    member *root = create_member("Grandpa Joe");

    // add member to the tree
    root->left = create_member("Dad (Mike)");
    root->right = create_member("Uncle Steve");
    root->left->left = create_member("Alex");
    root->left->right = create_member("Ema");

    // print family members
    print_family(root);

    // total members
    printf("Total Members: %d\n", count_members(root));

    // total generations(tree height)
    printf("Total generations: %d\n", count_generations(root));

    // free the tree
    free_the_family_tree(root);

    return 0;
}

member *create_member(char *member_name) {
    member *new_member = malloc(sizeof(member));
    if(new_member == NULL) {
        return NULL;
    }
    strncpy(new_member->name, member_name, sizeof(new_member->name) - 1);
    new_member->name[sizeof(new_member->name) - 1] = '\0';
    new_member->left = NULL;
    new_member->right = NULL;

    return new_member;
}

void print_family(member *root) {
    if(root == NULL) {
        return;
    }
    print_family(root->left);
    print_family(root->right);
    printf("%s\n",root->name);
}

void free_the_family_tree(member *root) {
    if(root == NULL) {
        return;
    }
    free_the_family_tree(root->left);
    free_the_family_tree(root->right);
    free(root);
}

int count_members(member *root) {
    if(root == NULL) {
        return 0;
    }

    int sum_from_left_child = count_members(root->left);
    int sum_from_right_child = count_members(root->right);
    int total = 1 + sum_from_left_child + sum_from_right_child;
    return total;
}

int count_generations(member *root) {
    int left_height;
    int right_height;

    if(root == NULL) {
        return -1;
    }

    left_height = count_generations(root->left);
    right_height = count_generations(root->right);
    int longest_height_btw_left_and_right_tree = left_height > right_height ? left_height : right_height;
    int total_height = 1 + longest_height_btw_left_and_right_tree;
    return total_height;

}