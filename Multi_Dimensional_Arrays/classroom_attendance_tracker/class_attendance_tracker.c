/* Class room attendance*/
// define 2D array data structure with 3 rows and 6 columns
// initialize the array with empty seats (O)
// define function to display the seats chart
// define the function to occupy a seat with a student
// define a function to perform attendance
// wire everything together in main function

#include<stdio.h>

#define ROWS 3
#define COLUMNS 6

char chart[ROWS][COLUMNS];

void init_chart(void);
void print_chart(void);
int occupy_a_seat(int row, int column);
int count_attendance(void);

int main(void) {
    int row, column, result, num_of_students_present, choice;

    init_chart();
    print_chart();
    while(1) {
        printf("Enter the row and column you want to occupy respectively(e.g: 2 4): ");
        if (scanf("%d %d", &row, &column) != 2) {
            printf("Invalid input! Please enter numbers only.\n");
            while (getchar() != '\n');  /* clear the bad input from buffer */
            continue;
        }
        result = occupy_a_seat(row, column);
        if(result == 0) {
            printf("the spot is already occupied or input is invalid\n");
        }
    
        if (result == 1) {
            printf("Successfully occupied spot [%d][%d]\n", row, column);
        }
    
        print_chart();
        
        num_of_students_present = count_attendance();
        printf("The number of students who attended is %d\n", num_of_students_present);
        printf("Enter 0 to quit, or any other number to continue: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  /* clear bad input */
            continue;
        }
        if (choice == 0) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }
    }

    return 0;
}

void init_chart(void) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            chart[i][j] = 'E';
        }
    }
}

void print_chart(void) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            printf("%c ", chart[i][j]);
        }
        printf("\n");
    }
}

int occupy_a_seat(int row, int column) {
    if(chart[row][column] == 'O' || row < 0 || row > ROWS || column < 0 || column > COLUMNS) {
        return 0;
    }
    chart[row][column]  = 'O';

    return 1;
}

int count_attendance() {
    int counter = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLUMNS; j++) {
            if (chart[i][j] == 'O') {
                counter = counter + 1;
            }
        }
    }

    return counter;
}