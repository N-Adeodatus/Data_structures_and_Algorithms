#include<stdio.h>
#define VER 4
#define EDG 5

typedef struct edge{
    int source;
    int destination;
    int weight;
} edge;

/*
Input:
    - hardcoded edges
    - number of vertexes.
    - number of edges
Storage:
    - structs for storing edges
    - array to store the edges.
    - array to store the shortest distance to each vertex
Processing:
    - Have an outer loop to pass through the edges (V - 1) times
    - Have an inner loop for interate over all the edges
        - check if a distance to destination needs change
            - update the distance
            - update the parent for the path
Output:
    - iterate over the dist array:
        - print distance from A to each vertex
        - print the path taken to reach it
    
*/

void bellman_ford(edge edges_arr[], int distances[], int previous[]);
void print_path(int previous[], int node);

int main(void) {
    edge edges[] = {
        {0, 1, 4},   // A -> B
        {0, 2, 2},   // A -> C
        {1, 3, 3},   // B -> D
        {2, 3, 1},   // C -> D
        {1, 2, 1}    // B -> C
    };

    int dist[] = {0, 999, 999, 999};
    int previous[] = {-1, -1, -1, -1};
    bellman_ford(edges, dist, previous);
    printf("__________Distances_________\n");
    for(int i = 0; i < VER; i++) {
        printf("A -> %c = %d, path: ", 'A' + i, dist[i]);
        print_path(previous, i);
        printf("\n");
    }
    for(int i = 0; i < VER; i++) {
        printf("(%d, %c), ", previous[i], 'A' + previous[i]);
    }
    printf("\n");

    return 0;
}

void bellman_ford(edge edges_arr[], int distances[], int previous[]){
    for(int i = 1; i < VER; i++) {
        for(int j = 0; j < EDG; j++) {
             if(distances[edges_arr[j].source] + edges_arr[j].weight < distances[edges_arr[j].destination]) {
                distances[edges_arr[j].destination] = distances[edges_arr[j].source] + edges_arr[j].weight;
                previous[edges_arr[j].destination] = edges_arr[j].source;
             }
        }
    }
}

void print_path(int previous[], int node) {
    if (previous[node] != -1) {
        print_path(previous, previous[node]);
        printf(" -> ");
    }
    printf("%c", 'A' + node);
}