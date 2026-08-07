#include<stdio.h>
#define LENGTH 5

struct book {
    char title[100];
    char author[50];
    float price;
}

void print_books(void);

int main(void) {
    struct book books_list[3] = {
        struct book b1 = {"Essentialism", "Greg", 3.7};
        struct book b2 = {"Atomic Habit", "James", 5.2};
        struct book b3 = {"Art of War", "Sun Tzu", 7.0};
    } 
    print_books(books_list, 3);
    return 0;
}

void print_books(struct book list_of_books[], int length) {
    for(int i = 0; i < length; i++) {
        printf("Book Name: %s\nAuthor: %s\nPrice: %f", list_of_books[i].title list_of_books[i].author list_of_books[i].price);
    }
}
