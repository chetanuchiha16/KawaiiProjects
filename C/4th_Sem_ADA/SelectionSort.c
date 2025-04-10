#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(long int *a, long int *b);
void SelectionSort(long int arr[], long int size);

int main() {
    long int arr[10000], size = 100;
    srand(time(0));
    double times[10];
    int it = 0;
    int n = 1000;
    while(it < 10) {
        for(int i = 0; i < size; i++ ) {
            arr[i] = rand() % 10 + 1;
        }

        time_t start = clock();
        SelectionSort(arr, size);
        time_t end = clock();
        // for(int i = 0; i < size; i++ ) {
        //     printf("%d ", arr[i]);
        // }
        printf("\n");
        times[it] = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Hina-onee-san the time taken for the %d%s iteration is %f", it + 1, (it + 1 == 1) ? "st":(it + 1 == 2) ? "nd": (it + 1 == 3) ? "rd": "th", times[it]);
        it++;
        size += n;

    }
    return 0;
}
void swap(long int *a, long int *b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(long int arr[], long int size) {
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = i + 1; j < size; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}