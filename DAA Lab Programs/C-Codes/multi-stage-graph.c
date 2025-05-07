#include <stdio.h>

#define MAX     100
#define INF     99999

int  cost[MAX][MAX];    // cost[i][j]: cost to go from node i to node j (INF if no edge)
int  dist[MAX];         // dist[i]: min cost from node i to the destination
int  nextNode[MAX];     // nextNode[i]: which node to go to from i on the min-cost path
int  nodeStage[MAX];    // nodeStage[i]: the stage number (1..numStages) of node i

int  n;                 // total number of nodes
int  numStages;         // total number of stages

void multistageShortestPath(int source, int destination) {
    // 1) Base: cost from destination to itself is zero
    dist[destination] = 0;
    
    // 2) Process every stage backwards
    for (int s = numStages - 1; s >= 1; s--) {
        // For every node i that lies in stage s...
        for (int i = 0; i < n; i++) {
            if (nodeStage[i] == s) {
                dist[i] = INF;
                // Try every possible forward neighbor j
                for (int j = 0; j < n; j++) {
                    if (nodeStage[j] > s && cost[i][j] != INF) {
                        int tentative = cost[i][j] + dist[j];
                        if (tentative < dist[i]) {
                            dist[i]     = tentative;
                            nextNode[i] = j;
                        }
                    }
                }
            }
        }
    }

    // 3) Print results
    printf("\nMinimum cost from %d to %d: %d\n", source, destination, dist[source]);
    printf("Path: ");
    for (int u = source; u != destination; u = nextNode[u]) {
        printf("%d -> ", u);
    }
    printf("%d\n", destination);
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter number of stages: ");
    scanf("%d", &numStages);

    printf("Enter stage of each node (0 to %d):\n", n - 1);
    for (int i = 0; i < n; i++) {
        printf("  Stage of node %d: ", i);
        scanf("%d", &nodeStage[i]);
    }

    printf("Enter cost matrix (use 99999 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            cost[i][j] = (x == 99999 ? INF : x);
        }
    }

    int source, destination;
    printf("Enter source node: ");
    scanf("%d", &source);
    printf("Enter destination node: ");
    scanf("%d", &destination);

    multistageShortestPath(source, destination);
    return 0;
}