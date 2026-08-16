#include <stdio.h>

void add(int A[10][10], int B[10][10], int C[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[10][10], int B[10][10], int C[10][10], int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int A[10][10], int B[10][10], int C[10][10], int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[10][10], A12[10][10], A21[10][10], A22[10][10];
    int B11[10][10], B12[10][10], B21[10][10], B22[10][10];
    int P[10][10], Q[10][10], R[10][10], S[10][10];
    int T[10][10], U[10][10];

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+k];
            A21[i][j] = A[i+k][j];
            A22[i][j] = A[i+k][j+k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+k];
            B21[i][j] = B[i+k][j];
            B22[i][j] = B[i+k][j+k];
        }

    add(A11, A22, T, k); add(B11, B22, U, k);
    strassen(T, U, P, k);

    add(A21, A22, T, k);
    strassen(T, B11, Q, k);

    sub(B12, B22, U, k);
    strassen(A11, U, R, k);

    sub(B21, B11, U, k);
    strassen(A22, U, S, k);

    add(A11, A12, T, k);
    strassen(T, B22, T, k);

    sub(A21, A11, U, k);
    add(B11, B12, P, k);
    strassen(U, P, U, k);

    sub(A12, A22, P, k);
    add(B21, B22, S, k);
    strassen(P, S, P, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = P[i][j] + S[i][j] - T[i][j] + U[i][j];
            C[i][j+k] = R[i][j] + T[i][j];
            C[i+k][j] = Q[i][j] + S[i][j];
            C[i+k][j+k] = P[i][j] + R[i][j] - Q[i][j] + T[i][j];
        }
}

int main() {
    int n;
    int A[10][10], B[10][10], C[10][10];

    printf("Enter matrix size (power of 2): ");
    scanf("%d", &n);

    printf("Enter Matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("Result Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}