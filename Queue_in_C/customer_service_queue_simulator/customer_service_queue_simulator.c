#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 50

/* Node structure - represents one customer in line */
typedef struct node {
    char name[NAME_LEN];
    struct node *next;
} node_t;

/* Queue structure - tracks front and rear of the line */
typedef struct queue {
    node_t *front;
    node_t *rear;
} queue_t;

/* Function prototypes */
void queue_init(queue_t *q);
int is_empty(queue_t *q);
void enqueue(queue_t *q, char *name);
void print_queue(queue_t *q);
void dequeue(queue_t *q);
void free_queue(queue_t *q);

int main(void)
{
    queue_t q;
    queue_init(&q);

    enqueue(&q, "Alice");
    enqueue(&q, "Bob");
    enqueue(&q, "Charlie");

    print_queue(&q);

    dequeue(&q);
    print_queue(&q);

    return 0;
}

/* Initialize an empty queue by setting front and rear to NULL */
void queue_init(queue_t *q)
{
    q->front = NULL;
    q->rear = NULL;
}

/* Check whether the queue has no customers in it */
int is_empty(queue_t *q)
{
    return q->front == NULL;
}

/* Add a new customer to the rear of the queue */
void enqueue(queue_t *q, char *name)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return;

    strncpy(new_node->name, name, NAME_LEN - 1);
    new_node->name[NAME_LEN - 1] = '\0';
    new_node->next = NULL;

    if (is_empty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }
}

/* Print all customers currently in the queue, from front to rear */
void print_queue(queue_t *q)
{
    node_t *current = q->front;

    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue (front to rear): ");
    while (current != NULL) {
        printf("%s", current->name);
        if (current->next != NULL)
            printf(" -> ");
        current = current->next;
    }
    printf("\n");
}

/* Remove and serve the customer at the front of the queue */
void dequeue(queue_t *q)
{
    node_t *temp;

    if (is_empty(q)) {
        printf("Queue is empty. No one to serve.\n");
        return;
    }

    temp = q->front;
    printf("Serving: %s\n", temp->name);

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}