#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    int id;
    char name[30];
    float price;
    int quantity;
} Product;

/* Function prototypes will go here as we add them */

int main(void)
{
    Product inventory[MAX_PRODUCTS];
    int count = 0;

    printf("Inventory system initialized. Capacity: %d, Current count: %d\n",
           MAX_PRODUCTS, count);

    return (0);
}

/* Function definitions will go here as we add them */