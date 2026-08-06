#include <stdio.h>

void swap(int *a, int *b);
int my_strlen(const char *s);

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