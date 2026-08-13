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

int main(void) {
    

    return 0;
}