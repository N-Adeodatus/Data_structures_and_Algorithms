#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int my_strlen(const char *s);
char *my_strcpy(char *dest, const char *src);
void reverse_array(int *arr, int size);
int find_max(int *arr, int size);
int *create_array(int size);

int main(void)
{
    printf("Pointer Toolkit initialized.\n");

    int x = 5;
    int y = 10;

    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap:  x = %d, y = %d\n", x, y);

    const char *word = "pointers";
    printf("Length of \"%s\" is %d\n", word, my_strlen(word));

    char buffer[20];
    my_strcpy(buffer, word);
    printf("Copied string: %s\n", buffer);

    int numbers[5] = {1, 2, 3, 4, 5};
    int i;

    printf("Before reverse:");
    for (i = 0; i < 5; i++)
        printf(" %d", numbers[i]);
    printf("\n");

    reverse_array(numbers, 5);

    printf("After reverse: ");
    for (i = 0; i < 5; i++)
        printf(" %d", numbers[i]);
    printf("\n");

    int scores[6] = {42, 17, 99, 3, 88, 56};
    printf("Max value: %d\n", find_max(scores, 6));

    int *dynamic = create_array(4);
    if (dynamic != NULL)
    {
        printf("Dynamic array:");
        for (i = 0; i < 4; i++)
            printf(" %d", dynamic[i]);
        printf("\n");
        free(dynamic);
        dynamic = NULL;
    }

    return (0);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int my_strlen(const char *s)
{
    int len = 0;

    while (*s != '\0')
    {
        len++;
        s++;
    }
    return (len);
}

char *my_strcpy(char *dest, const char *src)
{
    char *original_dest = dest;

    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (original_dest);
}

void reverse_array(int *arr, int size)
{
    int *left = arr;
    int *right = arr + (size - 1);
    int temp;

    while (left < right)
    {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int find_max(int *arr, int size)
{
    int *p = arr;
    int max = *p;
    int *end = arr + size;

    while (p < end)
    {
        if (*p > max)
            max = *p;
        p++;
    }
    return (max);
}

int *create_array(int size)
{
    int *arr = malloc(size * sizeof(int));
    int i;

    if (arr == NULL)
        return (NULL);

    for (i = 0; i < size; i++)
        arr[i] = i;

    return (arr);
}