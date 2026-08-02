#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int x = *(int *)a;
    int y = *(int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int hasDuplicates(int arr[], int n)
{
    qsort(arr, n, sizeof(int), compare);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
            return 1;   // Duplicate found
    }

    return 0;   // No duplicates
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (hasDuplicates(arr, n))
        printf("Duplicates found.\n");
    else
        printf("All elements are unique.\n");

    return 0;
}