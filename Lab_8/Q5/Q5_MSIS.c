#include <stdio.h>
#include <stdlib.h>

int findMSIS(int A[], int n) {
    int *msis = (int *)malloc(n * sizeof(int));
    int max_sum = 0;

    // Initialize MSIS values with array elements
    for (int i = 0; i < n; i++) {
        msis[i] = A[i];
    }

    // Compute maximum sum increasing subsequence values
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[j] < A[i] && msis[i] < msis[j] + A[i]) {
                msis[i] = msis[j] + A[i];
            }
        }
    }

    // Find maximum value in msis array
    for (int i = 0; i < n; i++) {
        if (msis[i] > max_sum) {
            max_sum = msis[i];
        }
    }

    free(msis);
    return max_sum;
}

int main() {
    int n;

    printf("==================================================\n");
    printf("  DAA LAB 8 - QUESTION 5: MAXIMUM SUM INCREASING SUBSEQUENCE\n");
    printf("==================================================\n\n");

    printf("Enter size of array A (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size!\n");
        return 1;
    }

    int *A = (int *)malloc(n * sizeof(int));
    printf("Enter %d positive integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max_sum = findMSIS(A, n);

    printf("\n--------------------------------------------------\n");
    printf("Maximum Sum Increasing Subsequence: %d\n", max_sum);
    printf("--------------------------------------------------\n");

    free(A);
    return 0;
}