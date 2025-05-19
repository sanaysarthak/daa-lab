#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Knapsack DP function
int knapsack(int W, int weight[], int value[], int n) {
    int dp[n + 1][W + 1];

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Track selected items
    int selected[n];
    for (int i = 0; i < n; i++) selected[i] = 0;

    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            selected[i - 1] = 1;
            w -= weight[i - 1];
        }
    }

    printf("\nAll entered item values: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", value[i]);
    }

    printf("\nAll entered item weights: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", weight[i]);
    }

    printf("\n\nSelected item indices (0-based): ");
    for (int i = 0; i < n; i++) {
        if (selected[i])
            printf("%d ", i);
    }

    printf("\nSelected item values: ");
    for (int i = 0; i < n; i++) {
        if (selected[i])
            printf("%d ", value[i]);
    }

    printf("\nSelected item weights: ");
    for (int i = 0; i < n; i++) {
        if (selected[i])
            printf("%d ", weight[i]);
    }

    printf("\n");
    return dp[n][W];
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int value[n], weight[n];

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    int result = knapsack(W, weight, value, n);
    printf("\nMaximum value in knapsack of capacity %d = %d\n", W, result);

    return 0;
}
