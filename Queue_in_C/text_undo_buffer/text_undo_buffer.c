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
    stack_t s;
    stack_init(&s);

    push(&s, "typed_hello");
    push(&s, "deleted_line");
    push(&s, "pasted_text");

    if (is_empty(&s))
        printf("Stack is empty.\n");
    else
        printf("Stack has actions. Top: %s\n", s.top->action);

    return 0;
}

/* Initialize an empty stack by setting top to NULL */
void stack_init(stack_t *s)
{
    s->top = NULL;
}

/* Check whether the stack has no actions in it */
int is_empty(stack_t *s)
{
    return s->top == NULL;
}

/* Add a new action to the top of the stack */
void push(stack_t *s, char *action)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node == NULL)
        return;

    strncpy(new_node->action, action, ACTION_LEN - 1);
    new_node->action[ACTION_LEN - 1] = '\0';

    new_node->next = s->top;
    s->top = new_node;
}