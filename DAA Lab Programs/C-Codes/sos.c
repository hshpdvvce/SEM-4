#include <stdio.h>
#define MAX 10

int n, d;              // n: number of elements, d: target subset sum
int S[MAX + 1];        // Array to hold the set elements (1-indexed)
int soln[MAX + 1];     // Array to indicate whether S[i] is included in the current subset

// Function to check if the current node is promising for further exploration
int promising(int i, int weight, int total) {
    // Check if a solution is still possible: current sum plus the remaining total must be at least d
    // and either we've already reached d or adding the next smallest element doesn't overshoot d.
    if ((weight + total >= d) && (weight == d || (i < n && weight + S[i+1] <= d)))
        return 1;
    else
        return 0;
}

// Recursive function to explore subsets
void SumofSub(int i, int weight, int total) {
    if (promising(i, weight, total)) {
        if (weight == d) {
            // A valid subset is found; print the elements that are marked as included.
            for (int j = 1; j <= i; j++) {
                if (soln[j] == 1)
                    printf("%d ", S[j]);
            }
            printf("\n");
        } else {
            // Try including the next element
            soln[i + 1] = 1;
            SumofSub(i + 1, weight + S[i + 1], total - S[i + 1]);
            // Try excluding the next element
            soln[i + 1] = 0;
            SumofSub(i + 1, weight, total - S[i + 1]);
        }
    }
}

int main() {
    int sum = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the set in increasing order: ");
    // Input elements into S[1] ... S[n] and compute the total sum of the set
    for (int i = 1; i <= n; i++) {
        scanf("%d", &S[i]);
        sum += S[i];
    }
    
    printf("Enter the max. subset value (d): ");
    scanf("%d", &d);
    
    // Check for simple feasibility: if total sum is less than target or smallest element exceeds target
    if (sum < d || S[1] > d) {
        printf("No subset possible\n");
    } else {
        // Start the backtracking process with initial state: index 0, current sum 0, remaining total as sum
        SumofSub(0, 0, sum);
    }
    
    return 0;
}