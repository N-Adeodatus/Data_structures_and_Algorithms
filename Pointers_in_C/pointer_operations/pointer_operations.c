#include <stdio.h>

void swap(int *a, int *b);
int my_strlen(const char *s);
char *my_strcpy(char *dest, const char *src);

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