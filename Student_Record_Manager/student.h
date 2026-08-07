#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    char name[50];
    int age;
    float grade;
};

void print_student(struct student s);

#endif /* STUDENT_H */