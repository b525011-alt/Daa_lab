#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of coins needed to make amount V
int minCoins(int C[], int n, int V) {
    // dp[i] will store the minimum coins required for amount i
    int *dp = (int *)malloc((V + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        return -1;
    }

    // Base case: 0 amount needs 0 coins
    dp[0] = 0;

    // Initialize all other DP values with a large value (infinity equivalent)
    for (int i = 1; i <= V; i++) {
        dp[i] = V + 1; // V + 1 is effectively infinity since max coins <= V
    }

    // Compute minimum coins required for all values from 1 to V
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (C[j] <= i) {
                int sub_res = dp[i - C[j]];
                if (sub_res != V + 1 && sub_res + 1 < dp[i]) {
                    dp[i] = sub_res + 1;
                }
            }
        }
    }

    int result = dp[V];
    free(dp);

    // If dp[V] wasn't updated, amount V cannot be formed
    return (result > V) ? -1 : result;
}

int main() {
    int n, V;

    printf("==================================================\n");
    printf("        DAA LAB 8 - QUESTION 1: MIN COIN CHANGE    \n");
    printf("==================================================\n\n");

    printf("Enter number of coin denominations (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of denominations!\n");
        return 1;
    }

    int *C = (int *)malloc(n * sizeof(int));
    printf("Enter %d coin denominations: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &C[i]);
    }

    printf("Enter target amount (V): ");
    if (scanf("%d", &V) != 1 || V < 0) {
        printf("Invalid target amount!\n");
        free(C);
        return 1;
    }

    int ans = minCoins(C, n, V);

    printf("\n--------------------------------------------------\n");
    if (ans != -1) {
        printf("Minimum coins needed to make amount %d: %d\n", V, ans);
    } else {
        printf("Amount %d cannot be formed using the given denominations.\n", V);
    }
    printf("--------------------------------------------------\n");

    free(C);
    return 0;
}