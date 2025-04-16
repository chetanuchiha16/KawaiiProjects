#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void swap(int *a, int *b);

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1};
    quickSort(arr, 0, 8);
    for(int i = 0; i < 8; i++) {
        printf("%d  ", arr[i]);
    }
    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if ( arr[j] < pivot) {
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[i + 1],&arr[high]);
    return i + 1;
}
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}