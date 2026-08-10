#include "student.h"

/**
 * main - entry point, creates an array of students and prints all of them
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

    print_all_students(students, 3);

    return (0);
}