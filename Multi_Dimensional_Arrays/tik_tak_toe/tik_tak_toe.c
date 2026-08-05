#include <stdio.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

/* Function prototypes */
void init_board(void);
void print_board(void);
void get_move(int *row, int *col);
int place_move(int row, int col, char symbol);
char check_win(void);
int check_draw(void);

int main(void) {
    init_board();
    print_board();

    int row, col;
    get_move(&row, &col);

    if (place_move(row, col, 'X')) {
        printf("Move placed successfully.\n");
    } else {
        printf("Invalid move.\n");
    }

    print_board();

    char winner = check_win();
    if (winner != ' ') {
        printf("%c wins!\n", winner);
    } else if (check_draw()) {
        printf("It's a draw!\n");
    } else {
        printf("No winner yet.\n");
    }

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

int place_move(int row, int col, char symbol) {
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    board[row][col] = symbol;
    return 1;
}

char check_win(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }

    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }

    return ' ';
}

int check_draw(void) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}