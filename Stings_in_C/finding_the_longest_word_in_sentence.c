#include<stdio.h>
#define SIZE 60

char *find_longest(char *sentence, int size);
int main(void) {
    char phrase[SIZE] = "he plays well";
    char *word = find_longest(phrase, SIZE);
    printf("The longest word is %s\n", word);
    return 0;
}

/*
Variable names' meaning:
p_t_l_s: pointer to longest string
i: index
n_o_p_s: number of char(s) per string
p_t_f_c_s: pointer to the first character of the current string.
n_c_f_l_s: number of characters for the longest string so far.
*/
char *find_longest(char *sentence, int size) {
    char character;
    int n_o_p_s = 0;
    int n_c_f_l_s = 0;
    char *p_t_f_c_s = sentence;
    char *p_t_l_s = sentence;
    static char result[SIZE];      // ← buffer to hold the final word

    for (int i = 0; i < size; i++) {
        character = sentence[i];
        if (character == '\0') break;
        if (character == ' ') {
            if (n_o_p_s > n_c_f_l_s) {
                n_c_f_l_s = n_o_p_s;
                p_t_l_s = p_t_f_c_s;
            }
            n_o_p_s = 0;
            p_t_f_c_s = &sentence[i + 1];
        } else {
            n_o_p_s++;
        }
    }
    // Check last word
    if (n_o_p_s > n_c_f_l_s) {
        n_c_f_l_s = n_o_p_s;      // ← also update the count here
        p_t_l_s = p_t_f_c_s;
    }

    // Copy only the longest word into result, then close it with \0
    for (int i = 0; i < n_c_f_l_s; i++) {
        result[i] = p_t_l_s[i];
    }
    result[n_c_f_l_s] = '\0';     // ← this is what tells printf to stop

    return result;
}