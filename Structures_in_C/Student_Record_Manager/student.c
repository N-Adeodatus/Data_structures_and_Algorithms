#include <stdio.h>
#include <string.h>
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

/**
 * find_student_by_name - searches an array of students by name
 * @arr: the array of students
 * @count: number of students in the array
 * @name: the name to search for
 *
 * Return: pointer to the matching student, or NULL if not found
 */
struct student *find_student_by_name(struct student arr[], int count, char *name)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(arr[i].name, name) == 0)
            return (&arr[i]);
    }
    return (NULL);
}