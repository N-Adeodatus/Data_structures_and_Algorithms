#include <stdio.h>

#define V 4
#define E 5

typedef struct {
    int from;
    int to;
    int weight;
} Edge;

void bellman_ford(Edge edges[], int distance[]) {
    distance[0] = 0;

    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {

            int from = edges[j].from;
            int to = edges[j].to;
            int weight = edges[j].weight;

            if (distance[from] + weight < distance[to]) {
                distance[to] = distance[from] + weight;
            }
        }
    }
}

int main(void) {
    Edge edges[E] = {
        {0, 1, 4},   // A -> B
        {0, 2, 2},   // A -> C
        {1, 3, 3},   // B -> D
        {2, 3, 1},   // C -> D
        {1, 2, 1}    // B -> C
    };

    int distance[V] = {0, 999, 999, 999};

    bellman_ford(edges, distance);

    printf("Distance from A:\n");

    for (int i = 0; i < V; i++) {
        printf("A -> %c = %d\n", 'A' + i, distance[i]);
    }

    return 0;
}