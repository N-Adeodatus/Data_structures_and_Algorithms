#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Classroom:
    Student:
        Quizzes
*/

typedef struct quiz{
    char quiz_name[100];
    int score;
} quiz;

typedef struct student {
    int id;
    char name[100];
    quiz quizzes[20];
    int num_quizzes;
} student;

typedef struct classroom {
    int count;
    student students[50];
} classroom;

void add_student(char *name, classroom *class) {
    student new_student;
    new_student.id = class->count;
    new_student.num_quizzes = 0;
    strncpy(new_student.name, name, sizeof(new_student.name) - 1);
    new_student.name[sizeof(new_student.name) - 1] = '\0';

    class->students[class->count] = new_student;
    class->count++;
 
}

void add_quiz(char *name, int score, student *student) {
    quiz new_quiz;
    strncpy(new_quiz.quiz_name, name, sizeof(new_quiz.quiz_name) - 1);
    new_quiz.quiz_name[sizeof(new_quiz.quiz_name) - 1] = '\0';
    new_quiz.score = score;

    student->quizzes[student->num_quizzes] = new_quiz;
    student->num_quizzes++;
}

void print_book(classroom *class) {
    printf("________GradeBook________\n");
    printf("Students:\n");
    if(class->count == 0){
        printf("No students\n");
        return;
    }
    for(int i = 0; i < class->count; i++) {
        printf("Student Name: %s\n", class->students[i].name);
        printf("Student ID: %d\n", class->students[i].id);
        if(class->students[i].num_quizzes == 0) {
            printf("No Quizzes Done\n");
        }
        else {
            printf("Quizzes:\n");
            for(int j = 0; j < class->students[i].num_quizzes; j++) {
                printf("Quiz Name: %s\n", class->students[i].quizzes[j].quiz_name);
                printf("Quiz Score: %d\n", class->students[i].quizzes[j].score);
                printf("-------\n");
            }
        }
        printf("----------------------------------------------\n");

    }
}
int main(void) {
    classroom *class = (classroom *)malloc(sizeof(classroom));
    class->count = 0;
    add_student("john", class);
    add_student("Ana", class);

    add_quiz("Mathematics", 90, &(class->students[0]));
    add_quiz("Physics", 95, &(class->students[0]));
    add_quiz("Mathematics", 60, &(class->students[1]));
    add_quiz("Chemistry", 85, &(class->students[1]));
    print_book(class);

    free(class);
    
    return 0;
}

