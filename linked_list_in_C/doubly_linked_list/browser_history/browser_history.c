/* Implement Browser History using Doubly Linked List*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

typedef struct visite_page{
    char name[SIZE];
    struct visite_page *prev;
    struct visite_page *next;
} page;

typedef struct list{
    page *head;
    page *tail;
}

void add_page_to_front(list **the_head, page *page_to_add);
void display_from_beginning_to_end(page *the_head);
void display_from_end_to_beginning(page *the_tail);
int delete_page_by_name(list **the_head, page *page_to_delete);

int main(void) {
    

    return 0;
}