#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

typedef struct todo_item{
    char task_description[SIZE];
    int is_complete;
    struct todo_item *next;
} task;

typedef struct todo_list{
    task *head;
} list;

void init(list *list_of_tasks);
task *create_node(char *descript);
void add_to_front(task **head, task *task_to_add);
void display_tasks(task *head);
void remove_task_by_description(task **head, char *name);

int main(void) {
    list students_list;

    init(&students_list);

    task *t1 = create_node("task 1");
    task *t2 = create_node("task 2");

    add_to_front(&(students_list.head), t1);
    add_to_front(&(students_list.head), t2);

    display_tasks(students_list.head);

    remove_task_by_description(&(students_list.head), "task 1");
    
    display_tasks(students_list.head);
    return 0;
}

void init(list *list_of_tasks) {
    list_of_tasks->head = NULL;
}

task *create_node(char *descript) {
    task *new_node = (task*) malloc(sizeof(task));
    if(new_node == NULL) {
        return NULL;
    }
    strncpy(new_node->task_description, descript, sizeof(new_node->task_description));
    new_node->task_description[sizeof(new_node->task_description) - 1] = '\0';
    new_node->is_complete = 0;
    new_node->next = NULL;

    return new_node;
}

void add_to_front(task **head, task *task_to_add) {
    task_to_add->next = *head;
    *head = task_to_add;
}

void display_tasks(task *head) {
    task *current = head;
    if(head == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("________List of Tasks________\n");

    while(current != NULL) {
        printf("Description: %s\n", current->task_description);
        printf("Status: %s\n", current->is_complete ? "Complete" : "Incomplete");
        printf("\n");
        
        current = current->next;
    }
    printf("--------------------------------------\n");
}

void remove_task_by_description(task **head, char *name) {
    task *current = *head;
    task *prev = NULL;
    if(head == NULL) {
        printf("The list is empty\n");
        return;
    }

    while(current != NULL) {
        if(strcmp(current->task_description, name) == 0) {
            if(prev == NULL) {
                *head = current->next;
            }
            else {
                prev->next = current->next;
            }
            free(current);
            printf("task removed successfully\n");
            return;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}