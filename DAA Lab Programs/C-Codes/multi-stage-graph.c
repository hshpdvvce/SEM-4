#include <stdio.h>
#include <limits.h>

#define INF INT_MAX

void multistageGraph(int cost[][100], int n) {
    int dist[100], path[100];

    dist[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        dist[i] = INF;
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != INF && cost[i][j] + dist[j] < dist[i]) {
                dist[i] = cost[i][j] + dist[j];
                path[i] = j;
            }
        }
    }

    printf("Minimum Cost Path: ");
    int i = 0;
    while (i != n - 1) {
        printf("%d -> ", i);
        i = path[i];
    }
    printf("%d\n", n - 1);

    printf("Minimum Cost from Source to Destination: %d\n", dist[0]);
}

int main() {
    int n;
    int cost[100][100];

    printf("Enter the number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 99999 if there is no direct edge)\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            scanf("%d", &input);
            if (input == 99999) {
                cost[i][j] = INF;
            } else {
                cost[i][j] = input;
            }
        }
    }

    multistageGraph(cost, n);

    return 0;
}