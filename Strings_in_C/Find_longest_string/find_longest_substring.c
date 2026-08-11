#include <stdio.h>
#include <string.h>

char *find_longest_word(const char *sentence)
{
    static char longest_str[100];
    char buffer[100];

    int l_num_c = 0;   // length of longest word
    int num_c = 0;     // length of current word

    int i = 0;

    while (sentence[i] != '\0')
    {
        if (sentence[i] != ' ')
        {
            /* Add character to buffer */
            buffer[num_c] = sentence[i];
            num_c++;
        }
        else
        {
            /* End the current word */
            buffer[num_c] = '\0';

            /* Check if current word is longer */
            if (num_c > l_num_c)
            {
                strcpy(longest_str, buffer);
                l_num_c = num_c;
            }

            /* Prepare buffer for the next word */
            num_c = 0;
        }

        i++;
    }

    /* Check the last word */
    buffer[num_c] = '\0';

    if (num_c > l_num_c)
    {
        strcpy(longest_str, buffer);
        l_num_c = num_c;
    }

    return longest_str;
}

int main(void)
{
    char sentence[] = "I love programming in C";

    printf("Longest word: %s\n", find_longest_word(sentence));

    return 0;
}