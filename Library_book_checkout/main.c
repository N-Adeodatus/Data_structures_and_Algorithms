#include<stdio.h>

#define NUMBER_OF_BOOKS = 5

void display_books(int books_arr[], int size);

int main(void) {
    int books[NUMBER_OF_BOOKS] = {0};

    return 0;
}

void display_books(int books_arr[], int size) {
    for(int i = 0; i < size -1; i++ ) {
        printf("book ID %d is %s", i + 1, books[i] == 0 ? "available" : "not available");
    }
}