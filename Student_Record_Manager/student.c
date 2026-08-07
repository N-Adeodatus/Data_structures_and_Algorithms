#include <stdio.h>
#include "student.h"

/**
 * main - entry point, builds a student array, prints all, then searches
 *
 * Return: 0 on success
 */
int main(void)
{
    struct student students[3] = {
        {"Alice", 20, 87.5},
        {"Bob", 22, 91.0},
        {"Carol", 19, 76.25}
    };
    struct student *found;

    print_all_students(students, 3);

    found = find_student_by_name(students, 3, "Bob");

    if (found != NULL)
    {
        printf("Found:\n");
        print_student(*found);
    }
    else
    {
        printf("Student not found.\n");
    }

    return (0);
}