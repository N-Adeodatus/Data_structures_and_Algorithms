#include<stdio.h>
#include<string.h>

#define SIZE 100

char *get_the_longest(char *sentence);
int main(void) {
    char phrase[SIZE] = "The amazing spiderman";
    char *longest = get_the_longest(phrase);
    printf("The longest word is: %s\n", longest);
    return 0;
}

char *get_the_longest(char *sentence) {

    static char result[SIZE];
    char *token = strtok(sentence, " ");

    result[0] = '\0';
    while(token != NULL){
        if(strlen(token) > strlen(result)) {
            strncpy(result, token, SIZE - 1);
            result[SIZE - 1] = '\0';
        }
        token = strtok(NULL, " ");
    }

    return result;
    
}