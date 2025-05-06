#include <stdio.h>

// Structure to represent an item
typedef struct {
    int weight;
    int value;
    double ratio; // value-to-weight ratio
} Item;

// Function to sort items by value-to-weight ratio in descending order
void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to solve the fractional knapsack problem
double greedyKnapsack(Item items[], int n, int capacity) {
    sortItemsByRatio(items, n);

    double totalValue = 0.0;
    int remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= remainingCapacity) {
            // Take the whole item
            totalValue += items[i].value;
            remainingCapacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += items[i].value * ((double)remainingCapacity / items[i].weight);
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = greedyKnapsack(items, n, capacity);

    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}