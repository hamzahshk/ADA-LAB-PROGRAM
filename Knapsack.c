#include <stdio.h>

struct Item {
    int weight;
    int value;
    float ratio;
    int index;

void sort(struct Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter value and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (float)items[i].value / items[i].weight;
        items[i].index = i + 1;
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    sort(items, n);

    float totalValue = 0.0;

    printf("\nSelected items:\n");

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d -> FULL (value = %d, weight = %d)\n",
                   items[i].index, items[i].value, items[i].weight);
        } else {
            float fraction = capacity / items[i].weight;
            totalValue += items[i].ratio * capacity;

            printf("Item %d -> FRACTION %.2f (value taken = %.2f)\n",
                   items[i].index, fraction, items[i].ratio * capacity);
            break;
        }
    }

    printf("\nMaximum value = %.2f\n", totalValue);

    return 0;
}
