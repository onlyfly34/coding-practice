#include <stdio.h>
#include <stdlib.h>

void quicksort(int *data, int left, int right);
void swap(int *a, int *b);

int main(void) {
    int i, n, data[10];

    printf("Enter the amount of numbers (<= 10): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter number %d : ", i + 1);
        scanf("%d", &data[i]);
    }

    quicksort(data, 0, n - 1);

    printf("\nAfter sorting: ");
    for (i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");
    //system("pause");
	
	return 0;
}

void quicksort(int *data, int left, int right) {
    int pivot, i, j;

    if (left >= right) { return; }

    pivot = data[left];

    i = left + 1;
    j = right;

    while (1) {
        while (i <= right) {
            if (data[i] > pivot) break;
            i = i + 1;
        }

        while (j > left) {
            if (data[j] < pivot) break;
            j = j - 1;
        }

        if (i > j) break;

        swap(&data[i], &data[j]);
    }

    swap(&data[left], &data[j]);

    quicksort(data, left, j - 1);
    quicksort(data, j + 1, right);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
