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
song_t *insert_front(song_t **head, char *title, int duration);
song_t *insert_back(song_t **head, song_t **tail, char *title, int duration);
void print_forward(song_t *head);
void print_backward(song_t *tail);

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

song_t *insert_front(song_t **head, char *title, int duration)
{
    song_t *new_node;

    new_node = create_node(title, duration);
    if (new_node == NULL)
        return (NULL);

    new_node->next = *head;

    if (*head != NULL)
        (*head)->prev = new_node;

    *head = new_node;

    return (new_node);
}

song_t *insert_back(song_t **head, song_t **tail, char *title, int duration)
{
    song_t *new_node;

    new_node = create_node(title, duration);
    if (new_node == NULL)
        return (NULL);

    new_node->prev = *tail;

    if (*tail != NULL)
        (*tail)->next = new_node;
    else
        *head = new_node;

    *tail = new_node;

    return (new_node);
}

void print_forward(song_t *head)
{
    while (head != NULL)
    {
        printf("%s (%d sec)\n", head->title, head->duration);
        head = head->next;
    }
}

void print_backward(song_t *tail)
{
    while (tail != NULL)
    {
        printf("%s (%d sec)\n", tail->title, tail->duration);
        tail = tail->prev;
    }
}