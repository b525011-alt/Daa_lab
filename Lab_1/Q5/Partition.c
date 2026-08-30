#include <stdio.h>

int findPartition(int arr[], int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == 1)
        {
            if (mid == 0 || arr[mid - 1] == 0)
                return mid;      // First occurrence of 1
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;   // No 1's found
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements (0's followed by 1's):\n", n);

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int partition = findPartition(arr, n);

    if (partition == -1)
        printf("No transition found (array contains only 0's).\n");
    else
        printf("Partition point is at index %d.\n", partition);

    return 0;
}