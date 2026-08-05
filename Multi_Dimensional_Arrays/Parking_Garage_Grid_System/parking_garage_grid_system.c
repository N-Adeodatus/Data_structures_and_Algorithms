#include <stdio.h>

#define LEVELS 4
#define SPOTS_PER_LEVEL 5

char garage[LEVELS][SPOTS_PER_LEVEL];

/* Function prototypes */
void init_garage(void);
void print_garage(void);

int main(void) {
    init_garage();
    print_garage();
    return 0;
}

/* Function definitions */

void init_garage(void) {
    for (int i = 0; i < LEVELS; i++) {
        for (int j = 0; j < SPOTS_PER_LEVEL; j++) {
            garage[i][j] = '.';
        }
    }
}

void print_garage(void) {
    for (int i = 0; i < LEVELS; i++) {
        printf("Level %d: ", i);
        for (int j = 0; j < SPOTS_PER_LEVEL; j++) {
            printf("%c ", garage[i][j]);
        }
        printf("\n");
    }
}