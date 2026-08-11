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

    printf("Queue initialized. front=%p rear=%p\n", (void *)q.front, (void *)q.rear);

    return 0;
}

/* Initialize an empty queue by setting front and rear to NULL */
void queue_init(queue_t *q)
{
    q->front = NULL;
    q->rear = NULL;
}