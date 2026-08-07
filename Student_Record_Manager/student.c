#include <stdio.h>
#include "student.h"

/**
 * print_student - prints the details of a single student
 * @s: the student struct to print
 */
void print_student(struct student s)
{
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}

/**
 * print_all_students - prints every student in an array
 * @arr: the array of students
 * @count: number of students in the array
 */
void print_all_students(struct student arr[], int count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        print_student(arr[i]);
        printf("---\n");
    }
}