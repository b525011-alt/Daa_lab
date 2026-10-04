#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int weight;
} Item;

int compare(const void* a, const void* b) {
    Item* item1 = (Item*)a;
    Item* item2 = (Item*)b;
    double r1 = (double)item1->value / item1->weight;
    double r2 = (double)item2->value / item2->weight;

    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

double fractionalKnapsack(int W, Item items[], int n) {
    qsort(items, n, sizeof(Item), compare);

    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W -= items[i].weight;
            finalValue += items[i].value;
        } else {
            finalValue += items[i].value * ((double)W / items[i].weight);
            break;
        }
    }
    return finalValue;
}

int main() {
    int W = 50;
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);

    printf("Maximum value in Fractional Knapsack: %.2f\n", fractionalKnapsack(W, items, n));
    return 0;
}