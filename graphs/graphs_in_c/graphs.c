#include <stdio.h>

#define INF 1000000
#define NO_PARENT (-1)
#define NUM_VERTICES 5

typedef struct edge_s
{
    int src;
    int dest;
    int weight;
} edge_t;

void init_arrays(int dist[], int parent[], int source);

int main(void)
{
    edge_t edges[] = {
        {0, 1, 6},
        {0, 2, 7},
        {1, 2, 8},
        {1, 3, 5},
        {1, 4, -4},
        {2, 3, -3},
        {2, 4, 9},
        {3, 1, -2}
    };
    int num_edges = sizeof(edges) / sizeof(edges[0]);
    int dist[NUM_VERTICES];
    int parent[NUM_VERTICES];
    int source = 0;

    init_arrays(dist, parent, source);

    return (0);
}

void init_arrays(int dist[], int parent[], int source)
{
    int i;

    for (i = 0; i < NUM_VERTICES; i++)
    {
        dist[i] = INF;
        parent[i] = NO_PARENT;
    }
    dist[source] = 0;
}