#include<stdio.h>

struct book {
    char title[100];
    char author[50];
    float price;
}

void print_book(void);

int main(void) {
    struct book books_list[5] = {
        struct book b1 = {"Essentialism", "Greg", 3.7};
        struct book b2 = {"Atomic Habit", "James", 5.2};
        struct book b3 = {"Art of War", "Sun Tzu", 7.0};
    } 
    return 0;
}

void print_book(void) {
    
}
