#include <stdio.h>

#define MAX 64

void add(int A[MAX][MAX], int B[MAX][MAX],
         int C[MAX][MAX], int n) {
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j] = A[i][j] + B[i][j];
}

void specialMul(int A[MAX][MAX], int B[MAX][MAX],
                int C[MAX][MAX], int n) {
    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int h = n/2;
    int A1[MAX][MAX], A2[MAX][MAX];
    int B1[MAX][MAX], B2[MAX][MAX];
    int X[MAX][MAX], Y[MAX][MAX];
    int P[MAX][MAX], Q[MAX][MAX], R[MAX][MAX];

    for(int i=0;i<h;i++)
        for(int j=0;j<h;j++) {
            A1[i][j] = A[i][j];
            A2[i][j] = A[i][j+h];
            B1[i][j] = B[i][j];
            B2[i][j] = B[i][j+h];
        }

    add(A1,A2,X,h);
    add(B1,B2,Y,h);

    specialMul(A1,B1,P,h);
    specialMul(A2,B2,Q,h);
    specialMul(X,Y,R,h);

    for(int i=0;i<h;i++)
        for(int j=0;j<h;j++) {
            C[i][j]     = P[i][j] + Q[i][j];
            C[i][j+h]   = R[i][j] - P[i][j] - Q[i][j];
            C[i+h][j]   = C[i][j+h];
            C[i+h][j+h] = C[i][j];
        }
}

int main() {
    int n;
    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    printf("Enter n (power of 2): ");
    scanf("%d",&n);

    printf("Enter Matrix A:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter Matrix B:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    specialMul(A,B,C,n);

    printf("Result:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }

    return 0;
}