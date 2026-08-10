#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int my_strlen(const char *s);
char *my_strcpy(char *dest, const char *src);
void reverse_array(int *arr, int size);
int find_max(int *arr, int size);
int *create_array(int size);
int resize_array(int **arr, int old_size, int new_size);

int main(void)
{
    int i;

    printf("=== Pointer Toolkit ===\n\n");

    /* Pass-by-reference: modifying caller's variables via single pointers */
    printf("-- swap (pass-by-reference) --\n");
    int x = 5;
    int y = 10;
    printf("Before: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After:  x = %d, y = %d\n\n", x, y);

    /* Single pointer walking a string until it hits '\0' */
    printf("-- my_strlen (pointer walking a string) --\n");
    const char *word = "pointers";
    printf("Length of \"%s\" is %d\n\n", word, my_strlen(word));

    /* Two pointers walking together, one reading, one writing */
    printf("-- my_strcpy (two pointers in parallel) --\n");
    char buffer[20];
    my_strcpy(buffer, word);
    printf("Copied string: %s\n\n", buffer);

    /* Two pointers closing inward from opposite ends */
    printf("-- reverse_array (two pointers closing inward) --\n");
    int numbers[5] = {1, 2, 3, 4, 5};
    printf("Before:");
    for (i = 0; i < 5; i++)
        printf(" %d", numbers[i]);
    printf("\n");
    reverse_array(numbers, 5);
    printf("After: ");
    for (i = 0; i < 5; i++)
        printf(" %d", numbers[i]);
    printf("\n\n");

    /* Single pointer walking forward once, accumulating a result */
    printf("-- find_max (walk and accumulate) --\n");
    int scores[6] = {42, 17, 99, 3, 88, 56};
    printf("Max value: %d\n\n", find_max(scores, 6));

    /* Heap allocation: a pointer as the sole owner of memory */
    printf("-- create_array / free (heap allocation) --\n");
    int *dynamic = create_array(4);
    if (dynamic != NULL)
    {
        printf("Dynamic array:");
        for (i = 0; i < 4; i++)
            printf(" %d", dynamic[i]);
        printf("\n");

        /* Pointer-to-pointer: reassigning the caller's pointer itself */
        printf("-- resize_array (pointer-to-pointer) --\n");
        if (resize_array(&dynamic, 4, 8))
        {
            printf("Resized array:");
            for (i = 0; i < 8; i++)
                printf(" %d", dynamic[i]);
            printf("\n");
        }

        free(dynamic);
        dynamic = NULL;
    }

    printf("\n=== Done ===\n");
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

int resize_array(int **arr, int old_size, int new_size)
{
    int *new_block = malloc(new_size * sizeof(int));
    int i;

    if (new_block == NULL)
        return (0);

    for (i = 0; i < old_size && i < new_size; i++)
        new_block[i] = (*arr)[i];
    for (; i < new_size; i++)
        new_block[i] = 0;

    free(*arr);
    *arr = new_block;

    return (1);
}