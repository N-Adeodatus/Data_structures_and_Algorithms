#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int number;
    struct node *next;

} t_node;

t_node *create_node(int value);
void insert_front(t_node **head, int value);
void print_all_values(t_node *head);
int sum_list(t_node *head);
int count_nodes(t_node *head);

int main(void) {
    t_node *head = NULL;
    insert_front(&head, 2);
    insert_front(&head, 5);
    insert_front(&head, 7);

    print_all_values(head);
    printf("Sum: %d\n", sum_list(head));
    printf("Total number of nodes: %d\n", count_nodes(head));
    return 0;
}

t_node *create_node(int value) {
    t_node *new_node = malloc(sizeof(t_node));
    new_node->number = value;
    new_node->next = NULL;
    return new_node;
}

void insert_front(t_node **head, int value) {
    t_node *new_node = create_node(value);
    if(new_node == NULL) {
        return;
    }
    new_node->next = *head;
    *head = new_node;
}

void print_all_values(t_node *head) {
    t_node *current = head;
    if(current == NULL) {
        printf("the list is empty\n");
        return;
    }
    while(current != NULL) {
        printf("Value: %d\n", current->number);
        current = current->next;
    }
}

int sum_list(t_node *head) {
    int total = 0;
    t_node *current = head;
    if(current == NULL) {
        printf("the list is empty\n");
        return total;
    }

    while(current != NULL) {
        total = total + current->number;
        current = current->next;
    }
    return total;
}

int count_nodes(t_node *head) {
    int total_count = 0;
    t_node *current = head;
    if(current == NULL) {
        printf("the list is empty\n");
        return total_count;
    }

    while(current != NULL) {
        total_count = total_count + 1;
        current = current->next;
    }
    return total_count;
}