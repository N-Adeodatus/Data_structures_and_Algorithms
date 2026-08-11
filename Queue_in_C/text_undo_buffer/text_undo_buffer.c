#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ACTION_LEN 50

/* Node structure - represents one action in the undo history */
typedef struct node {
    char action[ACTION_LEN];
    struct node *next;
} node_t;

/* Stack structure - tracks only the top of the stack */
typedef struct stack {
    node_t *top;
} stack_t;

/* Function prototypes */
void stack_init(stack_t *s);
int is_empty(stack_t *s);
void push(stack_t *s, char *action);
void print_stack(stack_t *s);
void pop(stack_t *s);
void peek(stack_t *s);
void free_stack(stack_t *s);

int main(void)
{
    printf("Stack program skeleton compiled successfully.\n");
    return 0;
}