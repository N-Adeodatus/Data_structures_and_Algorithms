/* Implement Browser History using Doubly Linked List*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

typedef struct visited_page{
    char name[SIZE];
    struct visited_page *prev;
    struct visited_page *next;
} page;

typedef struct list{
    page *head;
    page *tail;
} list;

void init(list *the_list);
page *create_page_node(char *page_name);
void add_page_to_front(list *the_list, page *page_to_add);
void display_from_beginning_to_end(page *the_head);
void display_from_end_to_beginning(page *the_tail);
int delete_page_by_name(list *the_list, char *page_name_to_delete);

int main(void) {
    

    return 0;
}

void init(list *the_list) {
    the_list->head = NULL;
    the_list->tail = NULL;
}

page *create_page_node(char *page_name) {
    page *new_node = (page*) malloc(sizeof(page));
    if(new_node == NULL) {
        return NULL;
    }
    strncpy(new_node->name, page_name, sizeof(new_node->name));
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

void add_page_to_front(list *the_list, page *page_to_add) {
    page_to_add->next = the_list->head;
    page_to_add->prev = NULL;

    if(the_list->head != NULL) {
        the_list->head->prev = page_to_add;
    }
    else {
        the_list->tail = page_to_add;
    }

    the_list->head = page_to_add;
}

void display_from_beginning_to_end(page *the_head) {
    if(the_head == NULL) {
        printf("The history is empty.\n");
        return;
    }
    page *current = the_head;
    while(current != NULL ) {
        printf("Page: %s\n",current->name);
        printf("\n");
        current = current->next;
    }
    printf("-----------------------------\n");
}

void display_from_end_to_beginning(page *the_tail) {
    if(the_tail == NULL) {
        printf("The history is empty.\n");
        return;
    }
    page *current = the_tail;
    while(current != NULL ) {
        printf("Page: %s\n",current->name);
        printf("\n");
        current = current->prev;
    }
    printf("-----------------------------\n");
}

int delete_page_by_name(list *the_list, char *page_name_to_delete) {
    if(the_list == NULL) {
        printf("The history is empty.\n");
        return 0;
    }
    page *current = the_list->head;
    while(current != NULL ) {
        if(strcmp(current->name, page_name_to_delete) == 0) {
            /* Case 1: current is the only node */
            if (current->prev == NULL && current->next == NULL)
            {
                the_list->head = NULL;
                the_list->tail = NULL;
            }

            /* Case 2: current is the first node */
            else if (current->prev == NULL)
            {
                the_list->head = current->next;
                current->next->prev = NULL;
            }

            /* Case 3: current is the last node */
            else if (current->next == NULL)
            {
                the_list->tail = current->prev;
                current->prev->next = NULL;
            }

            /* Case 4: current is somewhere in the middle */
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            printf("Deletion successful\n");
            return 1;
        }
        current = current->next;
    }
    return 0;
}