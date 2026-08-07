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