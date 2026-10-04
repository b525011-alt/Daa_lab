#include <stdio.h>
#include <stdlib.h>

int findLIS(int A[], int n) {
    int *dp = (int *)malloc(n * sizeof(int));
    int max_lis = 1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1; // Minimum LIS ending at index i is length 1
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > max_lis) {
            max_lis = dp[i];
        }
    }

    free(dp);
    return max_lis;
}

int main() {
    int n;

    printf("==================================================\n");
    printf("     DAA LAB 8 - QUESTION 4: LONGEST INCREASING SUBSEQUENCE\n");
    printf("==================================================\n\n");

    printf("Enter size of array A (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int *A = (int *)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int lis_length = findLIS(A, n);

    printf("\n--------------------------------------------------\n");
    printf("Length of Longest Increasing Subsequence: %d\n", lis_length);
    printf("--------------------------------------------------\n");

    free(A);
    return 0;
}