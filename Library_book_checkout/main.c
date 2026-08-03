#include<stdio.h>

#define NUMBER_OF_BOOKS 5

void display_books(int books_arr[], int size);
int checkout_book(int books_arr[], int size, int book_id);

int main(void) {
    int books[NUMBER_OF_BOOKS] = {0};
    int result;
    int choice;
    int book_ID;

    do {
        switch (choice){
            case 1:
                display_books(books, NUMBER_OF_BOOKS);
                break;
            
            case 2:
                printf("Please enter the book ID");
                scanf("%d", &book_ID);
                result = checkout_book(books, NUMBER_OF_BOOKS, book_ID);
                if (result == 1) {
                    printf("Book with id %d checked out successfully\n", book_ID);
                }
                else if (result == 0) {
                    printf("Book with id %d is already checked out\n", book_ID);
                }
                else {
                    printf("Invalid\n");
                }
    
            default:
                printf("Good bye!\n");
        }

    } while (choice >= 0 && choice < 2);

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
    
    if (index == 0) {
        books_arr[index] = 1;
        return 1;
    }

    books_arr[index] = 1;

    return 0;

}