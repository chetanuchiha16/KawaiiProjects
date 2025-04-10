#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int data[10000];

void merge(int start, int mid, int end) {
    int leftPtr = start;
    int rightPtr = mid + 1;
    int mergePtr = start;
    int mergedArray[10000];

    while (leftPtr <= mid && rightPtr <= end) {
        if (data[leftPtr] < data[rightPtr]) {
            mergedArray[mergePtr++] = data[leftPtr++];
        } else {
            mergedArray[mergePtr++] = data[rightPtr++];
        }
    }

    while (leftPtr <= mid) {
        mergedArray[mergePtr++] = data[leftPtr++];
    }

    while (rightPtr <= end) {
        mergedArray[mergePtr++] = data[rightPtr++];
    }

    for (int copyIdx = start; copyIdx <= end; copyIdx++) {
        data[copyIdx] = mergedArray[copyIdx];
    }
}

void mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    int totalElements;
    clock_t startTime, endTime;

    printf("Enter number of elements to sort, my cutie: ");
    scanf("%d", &totalElements);

    srand((unsigned)time(NULL));
    for (int i = 0; i < totalElements; i++) {
        data[i] = rand() % 10000;
    }

    printf("\nBefore Sorting:\n");
    for (int i = 0; i < totalElements; i++) {
        printf("%d ", data[i]);
    }

    startTime = clock();
    mergeSort(0, totalElements - 1);
    endTime = clock();

    printf("\n\nAfter Sorting:\n");
    for (int i = 0; i < totalElements; i++) {
        printf("%d ", data[i]);
    }

    printf("\n\nTime Taken: %.6f seconds\n", (float)(endTime - startTime) / CLOCKS_PER_SEC);

    return 0;
}
