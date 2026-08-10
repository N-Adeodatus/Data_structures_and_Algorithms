#include <stdio.h>
#include <stdlib.h>

/* ----- Data structure ----- */

typedef struct song_s
{
    char *title;
    int duration;
    struct song_s *next;
    struct song_s *prev;
} song_t;

/* ----- Function prototypes ----- */

song_t *create_node(char *title, int duration);

int main(void)
{
    return (0);
}

/* ----- Function definitions ----- */

song_t *create_node(char *title, int duration)
{
    song_t *new_node;
    int i;

    new_node = malloc(sizeof(song_t));
    if (new_node == NULL)
        return (NULL);

    i = 0;
    while (title[i] != '\0')
        i++;

    new_node->title = malloc(sizeof(char) * (i + 1));
    if (new_node->title == NULL)
    {
        free(new_node);
        return (NULL);
    }

    i = 0;
    while (title[i] != '\0')
    {
        new_node->title[i] = title[i];
        i++;
    }
    new_node->title[i] = '\0';

    new_node->duration = duration;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}