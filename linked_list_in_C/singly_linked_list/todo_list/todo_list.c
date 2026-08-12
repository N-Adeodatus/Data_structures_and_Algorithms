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
void add_to_front(task **head);
void display_tasks(task *head);
void remove_task_by_name(task *head);

int main(void) {

    return 0;
}