#include <stdio.h>

#define ARRAY_SIZE 5

void print_array(int arr[], int size);
int sum_array(int arr[], int size);

int main(void)
{
    int numbers[ARRAY_SIZE] = {23, 4, 67, 12, 89};
    int total;

    print_array(numbers, ARRAY_SIZE);

    total = sum_array(numbers, ARRAY_SIZE);
    printf("Sum: %d\n", total);

    return 0;
}

void print_array(int arr[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sum_array(int arr[], int size)
{
    int i;
    int total = 0;

    for (i = 0; i < size; i++)
    {
        total += arr[i];
    }

    return total;
}