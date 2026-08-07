#ifndef STUDENT_H
#define STUDENT_H

struct student
{
    char name[50];
    int age;
    float grade;
};

void print_student(struct student s);
void print_all_students(struct student arr[], int count);
struct student *find_student_by_name(struct student arr[], int count, char *name);

#endif /* STUDENT_H */