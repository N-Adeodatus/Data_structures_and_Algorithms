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
    list browser_history;

    /* Initialize the browser history */
    init(&browser_history);

    /* Create page nodes */
    page *page1 = create_page_node("Google");
    page *page2 = create_page_node("YouTube");
    page *page3 = create_page_node("GitHub");
    page *page4 = create_page_node("Stack Overflow");

    /* Check that all nodes were created successfully */
    if (page1 == NULL || page2 == NULL ||
        page3 == NULL || page4 == NULL)
    {
        printf("Failed to create a page node.\n");
        return 1;
    }

    /* Add pages to the front of the history */
    add_page_to_front(&browser_history, page1);
    add_page_to_front(&browser_history, page2);
    add_page_to_front(&browser_history, page3);
    add_page_to_front(&browser_history, page4);

    /* Display history from beginning to end */
    printf("History from beginning to end:\n");
    display_from_beginning_to_end(browser_history.head);

    /* Display history from end to beginning */
    printf("History from end to beginning:\n");
    display_from_end_to_beginning(browser_history.tail);

    /* Delete a page */
    printf("Deleting YouTube...\n");
    if (delete_page_by_name(&browser_history, "YouTube") == 0)
    {
        printf("Page not found.\n");
    }

    /* Display history after deletion */
    printf("\nHistory after deletion:\n");
    display_from_beginning_to_end(browser_history.head);

    /* Display backwards again to verify prev links */
    printf("History backwards after deletion:\n");
    display_from_end_to_beginning(browser_history.tail);

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