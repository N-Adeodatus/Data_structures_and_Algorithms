#include <stdio.h>

#define LEVELS 4
#define SPOTS_PER_LEVEL 5

char garage[LEVELS][SPOTS_PER_LEVEL];

/* Function prototypes */
void init_garage(void);
void print_garage(void);
int park_car(int level, int spot);

int main(void) {
    init_garage();

    while (1) {
        print_garage();

        int level, spot;
        printf("\nEnter level and spot to park (level -1 to quit): ");
        scanf("%d", &level);

        if (level == -1) {
            break;
        }

        scanf("%d", &spot);

        if (park_car(level, spot)) {
            printf("Car parked successfully.\n");
        } else {
            printf("Unable to park there. Spot may be invalid or occupied.\n");
        }
    }

    printf("\nFinal garage state:\n");
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

int park_car(int level, int spot) {
    if (level < 0 || level >= LEVELS || spot < 0 || spot >= SPOTS_PER_LEVEL) {
        return 0;
    }
    if (garage[level][spot] != '.') {
        return 0;
    }
    garage[level][spot] = '#';
    return 1;
}