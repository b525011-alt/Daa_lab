#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void computeLCS(char *X, char *Y) {
    int m = strlen(X);
    int n = strlen(Y);

    // Dynamic 2D DP Table
    int **dp = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        dp[i] = (int *)calloc(n + 1, sizeof(int));
    }

    // Build DP table bottom-up
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
            }
        }
    }

    int lcs_length = dp[m][n];

    // Reconstruct LCS string by tracing back
    char *lcs_str = (char *)malloc((lcs_length + 1) * sizeof(char));
    lcs_str[lcs_length] = '\0';

    int i = m, j = n, index = lcs_length - 1;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs_str[index--] = X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    printf("\n--------------------------------------------------\n");
    printf("Length of LCS: %d\n", lcs_length);
    printf("Reconstructed LCS String: \"%s\"\n", lcs_str);
    printf("--------------------------------------------------\n");

    for (int k = 0; k <= m; k++) free(dp[k]);
    free(dp);
    free(lcs_str);
}

int main() {
    char X[500], Y[500];

    printf("==================================================\n");
    printf("      DAA LAB 8 - QUESTION 3: LONGEST COMMON SUBSEQUENCE\n");
    printf("==================================================\n\n");

    printf("Enter String X: ");
    scanf("%s", X);

    printf("Enter String Y: ");
    scanf("%s", Y);

    computeLCS(X, Y);

    return 0;
}