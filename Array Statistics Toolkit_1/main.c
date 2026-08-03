#include <stdio.h>

#define ARRAY_SIZE 5

void print_array(int arr[], int size);
int sum_array(int arr[], int size);
float average_array(int arr[], int size);
int min_array(int arr[], int size);
int max_array(int arr[], int size);
int linear_search(int arr[], int size, int target);
void sort_array(int arr[], int size);

int main(void)
{
    int numbers[ARRAY_SIZE];
    int i;
    int total;
    float avg;
    int smallest;
    int largest;
    int index;
    int target;

    printf("Enter %d integers:\n", ARRAY_SIZE);
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        scanf("%d", &numbers[i]);
    }

    printf("You entered: ");
    print_array(numbers, ARRAY_SIZE);

    total = sum_array(numbers, ARRAY_SIZE);
    printf("Sum: %d\n", total);

    avg = average_array(numbers, ARRAY_SIZE);
    printf("Average: %.2f\n", avg);

    smallest = min_array(numbers, ARRAY_SIZE);
    printf("Min: %d\n", smallest);

    largest = max_array(numbers, ARRAY_SIZE);
    printf("Max: %d\n", largest);

    printf("Enter a value to search for: ");
    scanf("%d", &target);

    index = linear_search(numbers, ARRAY_SIZE, target);
    if (index != -1)
    {
        printf("Found %d at index %d\n", target, index);
    }
    else
    {
        printf("%d not found\n", target);
    }

    sort_array(numbers, ARRAY_SIZE);
    printf("Sorted: ");
    print_array(numbers, ARRAY_SIZE);

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

float average_array(int arr[], int size)
{
    int total = sum_array(arr, size);
    return (float)total / size;
}

int min_array(int arr[], int size)
{
    int i;
    int smallest = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }

    return smallest;
}

int max_array(int arr[], int size)
{
    int i;
    int largest = arr[0];

    for (i = 1; i < size; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    return largest;
}

int linear_search(int arr[], int size, int target)
{
    int i;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

void sort_array(int arr[], int size)
{
    int i, j, min_idx, temp;

    for (i = 0; i < size - 1; i++)
    {
        min_idx = i;

        for (j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}