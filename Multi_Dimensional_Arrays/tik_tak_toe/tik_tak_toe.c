#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

/* Function prototypes */
void init_board(void);
void print_board(void);
void get_move(int *row, int *col);

int main(void) {
    init_board();
    print_board();

    int row, col;
    get_move(&row, &col);
    printf("You entered row %d, col %d\n", row, col);

    return 0;
}

/* Function definitions */

void init_board(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i < BOARD_SIZE - 1) {
            for (int k = 0; k < BOARD_SIZE; k++) {
                printf("---");
                if (k < BOARD_SIZE - 1) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
}

void get_move(int *row, int *col) {
    printf("Enter row and column (0-2 0-2): ");
    scanf("%d %d", row, col);
}