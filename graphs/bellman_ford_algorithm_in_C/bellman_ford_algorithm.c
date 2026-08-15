#include<stdio.h>
#define VER 4
#define EDG 5

typedef struct edge{
    int source;
    int destination;
    int weight;
} edge;



void bellman_ford(edge edges_arr[], int distances[], int previous[]);
void print_path(int previous[], int v);

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
    for(int i = 0; i < VER - 1; i++) {
        for(int j = 0; j < EDG; j++) {
            int u = edges_arr[j].source;
            int v = edges_arr[j].destination;
            int weight = edges_arr[j].weight;
            
            if(distances[u] != 999 && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                previous[v] = u;
            }
        }
    }

    for(int i = 0; i < VER - 1; i++) {
        for(int j = 0; j < EDG; j++) {
            int u = edges_arr[j].source;
            int v = edges_arr[j].destination;
            int weight = edges_arr[j].weight;
            
            if(distances[u] != 999 && distances[u] + weight < distances[v]) {
                printf("This graph has negative cycles");
                return;
            }
        }
    }
}

void print_path(int previous[], int v) {
    if(previous[v] != -1) {
        print_path(previous, previous[v]);
        printf("->");
    }
    printf("%c", 'A' + v);
}