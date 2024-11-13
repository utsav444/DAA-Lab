#include <stdio.h>
#include <limits.h>
#define V 5  // Number of vertices in the graph

// Function to find the vertex with minimum distance value, from the set of vertices not yet processed
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

// Function that implements Dijkstra's single-source shortest path algorithm for a graph represented using an adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V];    // Output array. dist[i] will hold the shortest distance from src to i
    int sptSet[V];  // sptSet[i] is 1 if vertex i is included in shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;  // Distance of source vertex from itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    int graph[V][V] = { {0, 10, 0, 0, 5},
                        {0, 0, 1, 0, 2},
                        {0, 0, 0, 4, 0},
                        {7, 0, 6, 0, 0},
                        {0, 3, 9, 2, 0} };

    int src = 0;  // Starting vertex
    dijkstra(graph, src);

    return 0;
}
