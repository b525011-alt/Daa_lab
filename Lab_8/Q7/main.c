#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int unboundedKnapsack(int W, int wt[], int val[], int n) {
    int dp[W + 1];

    for (int i = 0; i <= W; i++) {
        dp[i] = 0;
    }

    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (wt[i] <= w) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
    }
    return dp[W];
}

int main() {
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    printf("Maximum value in Unbounded Knapsack: %d\n", unboundedKnapsack(W, wt, val, n));
    return 0;
}