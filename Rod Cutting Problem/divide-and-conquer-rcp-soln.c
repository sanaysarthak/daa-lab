#include <stdio.h>

// Function to compute the maximum value using a divide-and-conquer approach
int cutRod(int price[], int n) {
    int max_val = 0;

    // Try every possible first cut
    for (int i = 0; i < n; i++) {
        int revenue = price[i] + cutRod(price, n - i - 1);
        if (revenue > max_val) {
            max_val = revenue;
        }
    }

    return max_val;
}

int main() {
    // Example price list (for rod lengths 1 to 10)
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int n = sizeof(price) / sizeof(price[0]);  // Get the size of the price array

    int user_len;
    printf("Enter length: ");
    scanf("%d", &user_len);

    // Checking if user_len is valid
    if (user_len >= 1 && user_len <= n)
        printf("Maximum cost you can get: %d\n", cutRod(price, user_len));
    else
        printf("Invalid length! Enter a value between 1 and %d\n", n);

    return 0;
}
