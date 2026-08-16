#include <stdio.h>

int binarySearch(int a[], int n, int x, int *c) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        (*c)++;
        if (a[m] == x) return m;
        if (a[m] < x) l = m + 1;
        else r = m - 1;
    }
    return -1;
}

int ternarySearch(int a[], int n, int x, int *c) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int m1 = l + (r-l)/3;
        int m2 = r - (r-l)/3;

        (*c)++;
        if (a[m1] == x) return m1;

        (*c)++;
        if (a[m2] == x) return m2;

        if (x < a[m1]) r = m1 - 1;
        else if (x > a[m2]) l = m2 + 1;
        else {
            l = m1 + 1;
            r = m2 - 1;
        }
    }
    return -1;
}

int main() {
    int n, x, cb = 0, ct = 0;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int b = binarySearch(a, n, x, &cb);
    int t = ternarySearch(a, n, x, &ct);

    printf("\nBinary Search: %s", b == -1 ? "Not Found" : "Found");
    printf("\nComparisons = %d", cb);

    printf("\n\nTernary Search: %s", t == -1 ? "Not Found" : "Found");
    printf("\nComparisons = %d", ct);

    printf("\n\nBinary Search is better when comparisons are considered.");
    return 0;
}