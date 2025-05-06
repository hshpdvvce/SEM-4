#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define MAX 16 // Maximum number of cities

int n; // Number of cities
int graph[MAX][MAX]; // Cost adjacency matrix
int dp[MAX][1 << MAX]; // DP table to store minimum costs

// Function to solve TSP using Dynamic Programming
int tsp(int currentCity, int visited) {
    // If all cities have been visited, return the cost to return to the starting city
    if (visited == (1 << n) - 1) {
        return graph[currentCity][0] ? graph[currentCity][0] : INF;
    }

    // If the result is already computed, return it
    if (dp[currentCity][visited] != -1) {
        return dp[currentCity][visited];
    }

    int minCost = INF;

    // Try visiting all unvisited cities
    for (int nextCity = 0; nextCity < n; nextCity++) {
        if (!(visited & (1 << nextCity)) && graph[currentCity][nextCity] != 0) {
            int cost = graph[currentCity][nextCity] + tsp(nextCity, visited | (1 << nextCity));
            if (cost < minCost) {
                minCost = cost;
            }
        }
    }

    // Store the result in the DP table and return it
    dp[currentCity][visited] = minCost;
    return minCost;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    printf("(Enter 0 if there is no direct path)\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize the DP table with -1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Solve the TSP starting from city 0 with only city 0 visited
    int minCost = tsp(0, 1);

    printf("The minimum cost of the tour is: %d\n", minCost);

    return 0;
}