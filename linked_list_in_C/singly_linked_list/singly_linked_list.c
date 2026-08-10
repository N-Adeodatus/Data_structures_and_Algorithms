#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct node - represents a single contact in the linked list
 * @name: contact's name
 * @phone: contact's phone number
 * @next: pointer to the next node in the list
 */
typedef struct node
{
    char name[50];
    char phone[20];
    struct node *next;
} node_t;

/* prototypes */
node_t *create_node(char *name, char *phone);
void insert_front(node_t **head, char *name, char *phone);
void print_list(node_t *head);
node_t *search_by_name(node_t *head, char *name);
int delete_by_name(node_t **head, char *name);
void free_list(node_t *head);

int main(void)
{
    node_t *head = NULL;
    node_t *found;

    insert_front(&head, "Alice", "555-1111");
    insert_front(&head, "Bob", "555-2222");
    insert_front(&head, "Carol", "555-3333");

    printf("-- Contact list after inserts --\n");
    print_list(head);

    found = search_by_name(head, "Bob");
    if (found != NULL)
        printf("\nFound Bob: %s\n", found->phone);
    else
        printf("\nBob not found.\n");

    printf("\n-- Deleting Bob --\n");
    delete_by_name(&head, "Bob");
    print_list(head);

    free_list(head);
    head = NULL;

    return (0);
}

/**
 * create_node - allocates and initializes a new contact node
 * @name: contact's name
 * @phone: contact's phone number
 *
 * Return: pointer to the new node, or NULL on allocation failure
 */
node_t *create_node(char *name, char *phone)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (new_node == NULL)
        return (NULL);

    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';

    strncpy(new_node->phone, phone, sizeof(new_node->phone) - 1);
    new_node->phone[sizeof(new_node->phone) - 1] = '\0';

    new_node->next = NULL;

    return (new_node);
}

/**
 * insert_front - inserts a new contact at the front of the list
 * @head: pointer to the head pointer of the list
 * @name: contact's name
 * @phone: contact's phone number
 */
void insert_front(node_t **head, char *name, char *phone)
{
    node_t *new_node = create_node(name, phone);

    if (new_node == NULL)
        return;

    new_node->next = *head;
    *head = new_node;
}

/**
 * print_list - prints all contacts in the list
 * @head: pointer to the first node
 */
void print_list(node_t *head)
{
    node_t *current = head;

    if (current == NULL)
    {
        printf("The contact list is empty.\n");
        return;
    }

    while (current != NULL)
    {
        printf("Name: %s | Phone: %s\n", current->name, current->phone);
        current = current->next;
    }
}

/**
 * search_by_name - finds a contact node by name
 * @head: pointer to the first node
 * @name: name to search for
 *
 * Return: pointer to the matching node, or NULL if not found
 */
node_t *search_by_name(node_t *head, char *name)
{
    node_t *current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
            return (current);

        current = current->next;
    }

    return (NULL);
}

/**
 * delete_by_name - removes a contact node by name
 * @head: pointer to the head pointer of the list
 * @name: name to search for and delete
 *
 * Return: 1 if a node was deleted, 0 if no match was found
 */
int delete_by_name(node_t **head, char *name)
{
    node_t *current = *head;
    node_t *prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (prev == NULL)
                *head = current->next;
            else
                prev->next = current->next;

            free(current);
            return (1);
        }

        prev = current;
        current = current->next;
    }

    return (0);
}

/**
 * free_list - frees every node in the list
 * @head: pointer to the first node
 */
void free_list(node_t *head)
{
    node_t *current = head;
    node_t *tmp;

    while (current != NULL)
    {
        tmp = current->next;
        free(current);
        current = tmp;
    }
}