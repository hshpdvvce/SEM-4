#include <stdio.h>
#include <stdlib.h>

#define INF 999  // A large value representing infinity

// Function to extract the index of the vertex with the minimum distance
int Extract_Min(int *visited, int *d, int n) {
    int i, j = 0, min = INF;
    for (i = 0; i < n; i++) {
        if (!visited[i] && d[i] < min) {
            min = d[i];
            j = i;
        }
    }
    return j;
}

// Function to implement Dijkstra's algorithm
void Dijkstra(int s, int **a, int n) {
    int *visited = (int *)malloc(n * sizeof(int));
    int *d = (int *)malloc(n * sizeof(int));
    int i, u, v;
    
    // Initialize the visited array and the distance array (d)
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        d[i] = a[s][i];
    }
    visited[s] = 1;
    d[s] = 0;
    
    // Process all vertices
    for (i = 1; i <= n - 1; i++) {
        u = Extract_Min(visited, d, n);
        visited[u] = 1;
        
        // Update the distance value of the adjacent vertices of the chosen vertex.
        for (v = 0; v < n; v++) {
            if (!visited[v] && (d[u] + a[u][v] < d[v])) {
                d[v] = d[u] + a[u][v];
            }
        }
    }
    
    // Print shortest paths from source to all other vertices
    for (i = 0; i < n; i++) {
        if (i != s)
            printf("%d -> %d : %d\n", s, i, d[i]);
    }
    
    free(visited);
    free(d);
}

int main() {
    int n, s, i, j;
    
    // Input the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    // Dynamically allocate memory for the adjacency matrix
    int **a = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    
    // Input the cost adjacency matrix
    printf("Enter the cost adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    // Input the source vertex
    printf("Enter the source vertex: ");
    scanf("%d", &s);
    
    // Execute Dijkstra's algorithm from the given source vertex
    Dijkstra(s, a, n);
    
    // Free the allocated memory for the adjacency matrix
    for (i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
    
    return 0;
}