#include<stdio.h>
#define SIZE 30

int count_words(char *sentence, size);
int main(void) {
    char sentence1[SIZE] = "mango is a delicious fruit";
    char sentence2[SIZE] = "A computer is a useful tool";
    char sentence3[SIZE] = "Wild animals live in the forest";
    char sentence4[SIZE] = "Happy new year!";
    char sentence5[SIZE] = "congratulations on your promotion.";
    int words_count;

    printf("Sentence1: %s\n", sentence1);
    printf("The number of words in sentence1 is: %d\n", count_words(sentence1, SIZE));

    return 0
}

int count_words(char *sentence, size) {
    int word_count = 0;
    int counter = 0

    while(counter < size) {
        if (*sentence + counter == ' ') {
            word_count++
        }
        counter++
    }

    return word_count
}