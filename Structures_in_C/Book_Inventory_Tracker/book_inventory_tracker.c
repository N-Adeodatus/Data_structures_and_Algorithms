#include<stdio.h>
#define LENGTH 3

struct book {
    char title[100];
    char author[50];
    float price;
};

void print_books();
float total_inventory_value(struct book list_of_books[], int size);

int main(void) {
    float sum;
    struct book books_list[3] = {
        {"Essentialism", "Greg", 3.7},
        {"Atomic Habit", "James", 5.2},
        {"Art of War", "Sun Tzu", 7.0}
    };
    print_books(books_list, LENGTH);
    sum = total_inventory_value(books_list, LENGTH);
    printf("The sum of all books' prices is : %.2f\n", sum);
    return 0;
}

void print_books(struct book list_of_books[], int length) {
    for(int i = 0; i < length; i++) {
        printf("Book Name: %s\nAuthor: %s\nPrice: %.1f", list_of_books[i].title, list_of_books[i].author, list_of_books[i].price);
        printf("\n---------------------------------\n");
    }
}

float total_inventory_value(struct book list_of_books[], int size) {
    float total = 0;
    for(int i = 0; i < size; i++) {
        total = total + list_of_books[i].price;
    }
    return total;
}
