#include <stdio.h>
#include <stdlib.h>

// Function to calculate total distinct combinations to make amount V
long long countWays(int C[], int n, int V) {
    long long *dp = (long long *)calloc(V + 1, sizeof(long long));
    if (dp == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    // Base case: 1 way to make amount 0 (using no coins)
    dp[0] = 1;

    // Process each coin denomination
    for (int i = 0; i < n; i++) {
        for (int j = C[i]; j <= V; j++) {
            dp[j] += dp[j - C[i]];
        }
    }

    long long result = dp[V];
    free(dp);
    return result;
}

int main() {
    int n, V;

    printf("==================================================\n");
    printf("   DAA LAB 8 - QUESTION 2: COIN CHANGE (TOTAL WAYS)\n");
    printf("==================================================\n\n");

    printf("Enter number of coin denominations (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input!\n");
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

    long long ways = countWays(C, n, V);

    printf("\n--------------------------------------------------\n");
    printf("Total distinct combinations to make amount %d: %lld\n", V, ways);
    printf("--------------------------------------------------\n");

    free(C);
    return 0;
}