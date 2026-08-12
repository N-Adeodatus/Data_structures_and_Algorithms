#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 80

typedef struct node {
    char name[SIZE];
    float grade;
    struct node *next;
} s_node;

typedef struct head {
    struct node *head;
} h_struct;

s_node *create_node(char *name, float *grades);
void init(h_struct *node);
void add_to_beginning(s_node **head, s_node *node);
void print_all_students(s_node *head);
s_node *search_student(s_node *head, char *name);

int main(void) {
    // create a linked list
    h_struct student_list_entry_point;

    // initialize list
    init(&student_list_entry_point);

    //create student nodes
    char s1_name[SIZE] = "Grace";
    float s1_grade = 56.9;
    char s2_name[SIZE] = "George";
    float s2_grade = 97.2;
    char s3_name[SIZE] = "Dave";
    float s3_grade = 60.3;

    s_node *s1 = create_node(s1_name, &s1_grade);
    s_node *s2 = create_node(s2_name, &s2_grade);
    s_node *s3 = create_node(s3_name, &s3_grade);

    //add students
    add_to_beginning(&(student_list_entry_point.head), s1);
    add_to_beginning(&(student_list_entry_point.head), s2);
    add_to_beginning(&(student_list_entry_point.head), s3);

    // print all students
    print_all_students(student_list_entry_point.head);

    // search student
    s_node *ptr = search_student(student_list_entry_point.head, "George");
    if(ptr != NULL){
        printf("student found is:\n");
        printf("Name: %s\n", ptr->name);
        printf("Grade: %.2f\n", ptr->grade);
    }
    return 0;
}

s_node *create_node(char *name, float *grades) {
    s_node *new_node = (s_node*)malloc(sizeof(s_node));

    if(new_node == NULL) {
        return NULL;
    }

    strncpy(new_node->name, name, sizeof(new_node->name) - 1);
    new_node->name[sizeof(new_node->name) - 1] = '\0';
    new_node->grade = *grades;
    new_node->next = NULL;
    return new_node;
}


void init(h_struct *node) {
    node->head = NULL;
}

void add_to_beginning(s_node **head, s_node *node) {
    node->next = *head;
    *head = node;
}

void print_all_students(s_node *head) {
    if(head == NULL) {
        printf("List is empty\n");
    }
    s_node *current = head;
    while(current != NULL) {
        printf("Name: %s\n", current->name);
        printf("Grade: %.2f\n", current->grade);
        printf("----------------------------------\n");
        current = current->next;
    }
}

s_node *search_student(s_node *head, char *name) {
    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    s_node *current = head;
    while(current != NULL) {
        if(strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    printf("Student not found\n");
    return NULL;
}


