#include <stdio.h>

void maxMin(int a[], int l, int r, int *max, int *min) {
    int max1, min1, max2, min2, mid;

    if (l == r) {
        *max = *min = a[l];
        return;
    }

    if (r == l + 1) {
        if (a[l] > a[r]) {
            *max = a[l];
            *min = a[r];
        } else {
            *max = a[r];
            *min = a[l];
        }
        return;
    }

    mid = (l + r) / 2;

    maxMin(a, l, mid, &max1, &min1);
    maxMin(a, mid + 1, r, &max2, &min2);

    *max = (max1 > max2) ? max1 : max2;
    *min = (min1 < min2) ? min1 : min2;
}

int main() {
    int n, max, min;

    printf("Enter n: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    maxMin(a, 0, n - 1, &max, &min);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}