#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct product {
    int id;
    char name[30];
    float price;
    int quantity;
} Product;

int add_product(Product *inventory, int *count, int id,
        const char *name, float price, int quantity);
void display_products(const Product *inventory, int count);
int find_product_by_id(const Product *inventory, int count, int id);
int update_quantity(Product *inventory, int count, int id, int new_quantity);
int delete_product(Product *inventory, int *count, int id);
float calculate_total_value(const Product *inventory, int count);
void sort_by_name(Product *inventory, int count);

int main(void)
{
    Product inventory[MAX_PRODUCTS];
    int count = 0;
    int choice, id, quantity, index;
    float price;
    char name[30];

    do
    {
        printf("\n--- Inventory Menu ---\n");
        printf("1. Add product\n");
        printf("2. Display all products\n");
        printf("3. Search product by ID\n");
        printf("4. Update product quantity\n");
        printf("5. Delete product\n");
        printf("6. Show total inventory value\n");
        printf("7. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter id: ");
                scanf("%d", &id);
                printf("Enter name: ");
                scanf("%29s", name);
                printf("Enter price: ");
                scanf("%f", &price);
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                if (add_product(inventory, &count, id, name, price, quantity))
                    printf("Product added.\n");
                else
                    printf("Inventory full, could not add product.\n");
                break;

            case 2:
                display_products(inventory, count);
                break;

            case 3:
                printf("Enter id to search: ");
                scanf("%d", &id);
                index = find_product_by_id(inventory, count, id);
                if (index != -1)
                    printf("Found: ID %d | %s | $%.2f | Qty %d\n",
                           inventory[index].id, inventory[index].name,
                           inventory[index].price, inventory[index].quantity);
                else
                    printf("Product not found.\n");
                break;

            case 4:
                printf("Enter id to update: ");
                scanf("%d", &id);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                if (update_quantity(inventory, count, id, quantity))
                    printf("Quantity updated.\n");
                else
                    printf("Product not found.\n");
                break;

            case 5:
                printf("Enter id to delete: ");
                scanf("%d", &id);
                if (delete_product(inventory, &count, id))
                    printf("Product deleted.\n");
                else
                    printf("Product not found.\n");
                break;

            case 6:
                printf("Total inventory value: $%.2f\n",
                       calculate_total_value(inventory, count));
                break;

            case 7:
                printf("Exiting.\n");
                break;
            
            case 8:
                sort_by_name(inventory, count);
                printf("Products sorted by name.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    return (0);
}

/**
 * add_product - inserts a new product into the inventory array
 * @inventory: pointer to the array of Products
 * @count: pointer to the current number of products in use
 * @id: product id
 * @name: product name
 * @price: product price
 * @quantity: product quantity
 *
 * Return: 1 on success, 0 if the array is full
 */
int add_product(Product *inventory, int *count, int id,
        const char *name, float price, int quantity)
{
    if (*count >= MAX_PRODUCTS)
        return (0);

    inventory[*count].id = id;
    strncpy(inventory[*count].name, name, sizeof(inventory[*count].name) - 1);
    inventory[*count].name[sizeof(inventory[*count].name) - 1] = '\0';
    inventory[*count].price = price;
    inventory[*count].quantity = quantity;

    (*count)++;

    return (1);
}

/**
 * display_products - prints all products currently in the inventory
 * @inventory: pointer to the array of Products (read-only)
 * @count: number of products currently in use
 */
void display_products(const Product *inventory, int count)
{
    int i;

    if (count == 0)
    {
        printf("Inventory is empty.\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("ID: %d | Name: %-10s | Price: $%.2f | Qty: %d\n",
               inventory[i].id, inventory[i].name,
               inventory[i].price, inventory[i].quantity);
    }
}

/**
 * find_product_by_id - searches the inventory for a product by id
 * @inventory: pointer to the array of Products (read-only)
 * @count: number of products currently in use
 * @id: the id to search for
 *
 * Return: index of the matching product, or -1 if not found
 */
int find_product_by_id(const Product *inventory, int count, int id)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (inventory[i].id == id)
            return (i);
    }

    return (-1);
}

/**
 * update_quantity - updates the quantity of a product found by id
 * @inventory: pointer to the array of Products (writable)
 * @count: number of products currently in use
 * @id: the id of the product to update
 * @new_quantity: the new quantity value to set
 *
 * Return: 1 on success, 0 if the product was not found
 */
int update_quantity(Product *inventory, int count, int id, int new_quantity)
{
    int index;

    index = find_product_by_id(inventory, count, id);
    if (index == -1)
        return (0);

    inventory[index].quantity = new_quantity;

    return (1);
}

/**
 * delete_product - removes a product from the inventory by id,
 * shifting subsequent elements left to close the gap
 * @inventory: pointer to the array of Products (writable)
 * @count: pointer to the current number of products in use
 * @id: the id of the product to delete
 *
 * Return: 1 on success, 0 if the product was not found
 */
int delete_product(Product *inventory, int *count, int id)
{
    int index;
    int j;

    index = find_product_by_id(inventory, *count, id);
    if (index == -1)
        return (0);

    for (j = index; j < *count - 1; j++)
        inventory[j] = inventory[j + 1];

    (*count)--;

    return (1);
}

/**
 * calculate_total_value - sums price * quantity across all products
 * @inventory: pointer to the array of Products (read-only)
 * @count: number of products currently in use
 *
 * Return: total value of the inventory
 */
float calculate_total_value(const Product *inventory, int count)
{
    float total;
    int i;

    total = 0;

    for (i = 0; i < count; i++)
        total += inventory[i].price * inventory[i].quantity;

    return (total);
}

/**
 * sort_by_name - sorts the inventory array alphabetically by name
 * using the selection sort algorithm
 * @inventory: pointer to the array of Products (writable)
 * @count: number of products currently in use
 */
void sort_by_name(Product *inventory, int count)
{
    int i, j, min_index;
    Product temp;

    for (i = 0; i < count - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < count; j++)
        {
            if (strcmp(inventory[j].name, inventory[min_index].name) < 0)
                min_index = j;
        }

        if (min_index != i)
        {
            temp = inventory[i];
            inventory[i] = inventory[min_index];
            inventory[min_index] = temp;
        }
    }
}