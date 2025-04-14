#include <stdio.h>
#include <stdlib.h>

int n, m;         // number of items and capacity
int *w;           // weights array (1-indexed)
int *value;       // profits array (1-indexed)
int **v;          // DP table for memoization

// Utility function to get maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to compute the knapsack solution
int knap(int i, int j) {
    // Base condition: if no items or zero capacity, profit is 0
    if (i == 0 || j == 0) {
        v[i][j] = 0;
        return 0;
    }
    // If already computed, return stored value
    if (v[i][j] != -1)
        return v[i][j];
        
    // If the capacity j is less than the weight of the current item, skip it
    if (j < w[i]) {
        v[i][j] = knap(i - 1, j);
    } else {
        // Otherwise, consider including or excluding the current item
        int exclude = knap(i - 1, j);
        int include = value[i] + knap(i - 1, j - w[i]);
        v[i][j] = max(exclude, include);
    }
    return v[i][j];
}

// Function to display the selected items for the optimal solution
void optimal(int i, int j) {
    // Base condition: if no items left or no capacity, return
    if (i == 0 || j == 0)
        return;
    // If the current item is included in the solution,
    // its profit will add to the solution compared to the previous row.
    if (v[i][j] != v[i - 1][j]) {
        printf("Item: %d\n", i);
        optimal(i - 1, j - w[i]);
    } else {
        optimal(i - 1, j);
    }
}

int main() {
    int i, profit;

    // Input number of items and knapsack capacity
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    // Allocate arrays (using 1-indexed arrays; index 0 is for base condition)
    w = (int *)malloc((n + 1) * sizeof(int));
    value = (int *)malloc((n + 1) * sizeof(int));

    // Allocate DP table: v will be (n+1) x (m+1)
    v = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        v[i] = (int *)malloc((m + 1) * sizeof(int));
    }

    // Initialize DP table with a sentinel value (-1) so we know if a cell is computed
    for (i = 0; i <= n; i++) {
        int j;
        for (j = 0; j <= m; j++) {
            v[i][j] = -1;
        }
    }

    // Input weights of items
    printf("\nEnter weights for items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    // Input profits of items
    printf("\nEnter profits for items:\n");
    for (i = 1; i <= n; i++) {
        scanf("%d", &value[i]);
    }

    // Compute maximum profit
    profit = knap(n, m);
    printf("\nMaximum Profit: %d\n", profit);

    // Print the items that are included in the optimal solution
    printf("Items to be added for the optimal solution:\n");
    optimal(n, m);

    // Free allocated memory
    for (i = 0; i <= n; i++) {
        free(v[i]);
    }
    free(v);
    free(w);
    free(value);

    return 0;
}