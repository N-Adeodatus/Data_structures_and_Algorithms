#include<stdio.h>

#define NUMBER_OF_BOOKS 5

void display_books(int books_arr[], int size);
int checkout_book(int books_arr[], int size, int book_id);

int main(void) {
    int books[NUMBER_OF_BOOKS] = {0};

    return 0;
}

void display_books(int books_arr[], int size) {
    for(int i = 0; i < size -1; i++ ) {
        printf("book ID %d is %s", i + 1, books_arr[i] == 0 ? "available" : "not available");
    }
}

int checkout_book(int books_arr[], int size, int book_id) {
    int index = book_id - 1;

    if (index < 0 || index > 4) {
        return -1;
    }
    
    if (index == 1) {
        books_arr[index] = 0;
        return 0;
    }

    books_arr[index] = 1;

    return 1;

}