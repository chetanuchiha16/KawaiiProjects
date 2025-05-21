#include <stdio.h>

void discreteKnapsack(int itemCount, float weights[], float values[], float capacity);
void continuousKnapsack(int itemCount, float weights[], float values[], float capacity);

int main() {
    int itemCount;
    float weights[10], values[10], capacity;
    float valuePerWeight[10];
    
    printf("Enter the number of items: ");
    scanf("%d", &itemCount);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < itemCount; i++)
        scanf("%f", &weights[i]);

    printf("Enter the values of the items:\n");
    for (int i = 0; i < itemCount; i++)
        scanf("%f", &values[i]);

    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    for (int i = 0; i < itemCount; i++)
        valuePerWeight[i] = values[i] / weights[i];

    // Display the items before sorting
    printf("\nGiven Items:\n");
    printf("Item\tWeight\t\tValue\t\tValue/Weight\n");
    for (int i = 0; i < itemCount; i++)
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i, weights[i], values[i], valuePerWeight[i]);

    // Sort items by value per weight ratio in descending order
    for (int i = 0; i < itemCount - 1; i++) {
        for (int j = 0; j < itemCount - i - 1; j++) {
            if (valuePerWeight[j] < valuePerWeight[j + 1]) {
                // Swap ratios
                float temp = valuePerWeight[j];
                valuePerWeight[j] = valuePerWeight[j + 1];
                valuePerWeight[j + 1] = temp;

                // Swap weights
                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;

                // Swap values
                temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }

    // Display the sorted items
    printf("\nItems After Sorting by Value/Weight:\n");
    printf("Item\tWeight\t\tValue\t\tValue/Weight\n");
    for (int i = 0; i < itemCount; i++)
        printf("%d\t%.2f\t\t%.2f\t\t%.2f\n", i, weights[i], values[i], valuePerWeight[i]);

    printf("\n--- Discrete Knapsack ---\n");
    discreteKnapsack(itemCount, weights, values, capacity);

    printf("\n--- Continuous Knapsack ---\n");
    continuousKnapsack(itemCount, weights, values, capacity);

    return 0;
}

void discreteKnapsack(int itemCount, float weights[], float values[], float capacity) {
    int itemTaken[10] = {0};
    float totalProfit = 0.0;

    for (int i = 0; i < itemCount; i++) {
        if (weights[i] > capacity)
            break;

        itemTaken[i] = 1;
        totalProfit += values[i];
        capacity -= weights[i];
    }

    printf("Items selected (1 for taken, 0 for not taken):\n");
    for (int i = 0; i < itemCount; i++)
        printf("%d\t", itemTaken[i]);

    printf("\nTotal Profit: %.2f\n", totalProfit);
}

void continuousKnapsack(int itemCount, float weights[], float values[], float capacity) {
    float itemFraction[10] = {0.0};
    float totalProfit = 0.0;
    int i;

    for (i = 0; i < itemCount; i++) {
        if (weights[i] > capacity)
            break;

        itemFraction[i] = 1.0;
        totalProfit += values[i];
        capacity -= weights[i];
    }

    if (i < itemCount && capacity > 0) {
        itemFraction[i] = capacity / weights[i];
        totalProfit += itemFraction[i] * values[i];
    }

    printf("Fraction of items taken:\n");
    for (int i = 0; i < itemCount; i++)
        printf("%.2f\t", itemFraction[i]);

    printf("\nTotal Profit: %.2f\n", totalProfit);
}
