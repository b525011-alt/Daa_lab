#include <stdio.h>

int findDefective(int a[], int l, int r) {
    if (l == r)
        return l;

    int n = r - l + 1;
    int mid = (l + r) / 2;

    int sum1 = 0, sum2 = 0;

    for (int i = l; i <= mid; i++)
        sum1 += a[i];

    for (int i = mid + 1; i <= r; i++)
        sum2 += a[i];

    if (sum1 < sum2)
        return findDefective(a, l, mid);

    if (sum2 < sum1)
        return findDefective(a, mid + 1, r);

    // Equal groups: check extra coin
    if (n % 2 != 0)
        return mid + 1;

    return -1;   // No defective coin
}

int main() {
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter coin weights:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int d = findDefective(a, 0, n - 1);

    if (d == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin = Coin %d (weight = %d)\n", d + 1, a[d]);

    return 0;
}