#include<stdio.h>
#define SIZE 5

void reverse_arr(int *arr, int size);

int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5};
    printf("Before reversing:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    
    reverse_arr(array, SIZE);
    printf("\nAfter reversing:\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void reverse_arr(int *arr, int size) {
    int temp;
    int *left = arr;
    int *right = arr + size - 1;

    while(left < right) {
        temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}