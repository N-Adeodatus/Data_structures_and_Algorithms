#include <stdio.h>

#define NUM_SEATS 10

void display_seats(int seats[], int size);
int book_seat(int seats[], int size, int seat_number);

int main(void)
{
    int seats[NUM_SEATS] = {0};
    int choice;
    int seat_number;
    int result;

    do
    {
        printf("\nMenu:\n");
        printf("1. View seats\n");
        printf("2. Book a seat\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display_seats(seats, NUM_SEATS);
                break;

            case 2:
                printf("Enter seat number to book: ");
                scanf("%d", &seat_number);
                result = book_seat(seats, NUM_SEATS, seat_number);

                if (result == 1)
                {
                    printf("Seat %d booked successfully.\n", seat_number);
                }
                else if (result == 0)
                {
                    printf("Seat %d is already booked.\n", seat_number);
                }
                else
                {
                    printf("Invalid seat number.\n");
                }
                break;

            case 3:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void display_seats(int seats[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Seat %d: %s\n", i + 1, seats[i] == 0 ? "Available" : "Booked");
    }
}

int book_seat(int seats[], int size, int seat_number)
{
    int index = seat_number - 1;

    if (index < 0 || index >= size)
    {
        return -1;
    }

    if (seats[index] == 1)
    {
        return 0;
    }

    seats[index] = 1;
    return 1;
}