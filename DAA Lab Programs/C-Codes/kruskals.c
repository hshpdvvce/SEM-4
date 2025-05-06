#include <stdio.h>
#include <limits.h>

#define MAX 100

int parent[MAX];

int find(int p) {
    while (parent[p] != 0) {
        p = parent[p];
    }
    return p;
}

void unionSets(int i, int j) {
    if (i < j) {
        parent[i] = j;
    } else {
        parent[j] = i;
    }
}

void kruskal(int n, int cost[MAX][MAX]) {
    int u, v, min, k = 0, i, j, sum = 0;

    while (k < n - 1) {
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && i != j) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int parentU = find(u);
        int parentV = find(v);

        if (parentU != parentV) {
            unionSets(parentU, parentV);
            printf("Edge (%d, %d) with cost %d\n", u, v, min);
            sum += min;
            k++;
        }

        cost[u][v] = cost[v][u] = INT_MAX;
    }

    printf("Minimum cost of spanning tree: %d\n", sum);
}

int main() {
    int n, cost[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 99999 for no direct edge)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            scanf("%d", &input);
            if (input == 99999) {
                cost[i][j] = INT_MAX;
            } else {
                cost[i][j] = input;
            }
        }
    }

    kruskal(n, cost);

    return 0;
}