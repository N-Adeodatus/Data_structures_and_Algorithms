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
int relax_edges(edge_t edges[], int num_edges, int dist[], int parent[]);
void bellman_ford(edge_t edges[], int num_edges, int dist[], int parent[]);
void print_distances(int dist[], int source);
int has_negative_cycle(edge_t edges[], int num_edges, int dist[], int parent[]);
void print_path(int parent[], int node);

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
    int i;

    init_arrays(dist, parent, source);
    bellman_ford(edges, num_edges, dist, parent);

    if (has_negative_cycle(edges, num_edges, dist, parent))
    {
        printf("Graph contains a negative-weight cycle!\n");
        return (1);
    }

    print_distances(dist, source);

    printf("\nPaths from source %d:\n", source);
    for (i = 0; i < NUM_VERTICES; i++)
    {
        if (dist[i] == INF)
        {
            printf("Node %d: unreachable\n", i);
            continue;
        }
        printf("Node %d: ", i);
        print_path(parent, i);
        printf("\n");
    }

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

int relax_edges(edge_t edges[], int num_edges, int dist[], int parent[])
{
    int i;
    int updated;
    int u, v, w;

    updated = 0;
    for (i = 0; i < num_edges; i++)
    {
        u = edges[i].src;
        v = edges[i].dest;
        w = edges[i].weight;
        if (dist[u] != INF && dist[u] + w < dist[v])
        {
            dist[v] = dist[u] + w;
            parent[v] = u;
            updated = 1;
        }
    }
    return (updated);
}

void bellman_ford(edge_t edges[], int num_edges, int dist[], int parent[])
{
    int i;
    int updated;

    for (i = 0; i < NUM_VERTICES - 1; i++)
    {
        updated = relax_edges(edges, num_edges, dist, parent);
        if (updated == 0)
            break;
    }
}

void print_distances(int dist[], int source)
{
    int i;

    printf("Shortest distances from source %d:\n", source);
    for (i = 0; i < NUM_VERTICES; i++)
    {
        if (dist[i] == INF)
            printf("Node %d: INF\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}

int has_negative_cycle(edge_t edges[], int num_edges, int dist[], int parent[])
{
    return (relax_edges(edges, num_edges, dist, parent));
}

void print_path(int parent[], int node)
{
    if (parent[node] != NO_PARENT)
    {
        print_path(parent, parent[node]);
        printf(" -> ");
    }
    printf("%d", node);
}