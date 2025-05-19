#include <stdio.h>

// Function to compute the maximum value using dynamic‑programming approach
int cutRod(int price[], int n) {
    // dp[j] will hold the maximum revenue for a rod of length j
    int dp[n + 1];
    dp[0] = 0;  

    for (int j = 1; j <= n; j++) {
        int max_val = 0;
        // try cutting off a first piece of length (i+1), leaving j-(i+1)
        for (int i = 0; i < j; i++) {
            int revenue = price[i] + dp[j - i - 1];
            if (revenue > max_val) {
                max_val = revenue;
            }
        }
        dp[j] = max_val;
    }
    return dp[n];
}

int main() {
    // Example price list (for rod lengths 1 to 10)
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = sizeof(price) / sizeof(price[0]); 

    int user_len;
    printf("Enter length: ");
    scanf("%d", &user_len);

    if (user_len >= 1 && user_len <= n)
        printf("Maximum cost you can get: %d\n", cutRod(price, user_len));
    else
        printf("Invalid length! Enter a value between 1 and %d\n", n);

    return 0;
}
