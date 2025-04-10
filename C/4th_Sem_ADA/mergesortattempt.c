#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main() {
  srand(time(0));
  int arr[20000];
  int size = 100;
  int n = 1000;
  int it = 0;
  double times[10];
  while (it < 10) {
    for (int i = 0; i < size; i++) {
      arr[i] = rand() % 100 + 1;
    }

    time_t start = clock();
    mergeSort(arr, 0, size - 1);
    time_t end = clock();

    // for (int i = 0; i < size; i++) {
    //   printf("%d ", arr[i]);
    // }
    // printf("\n");

    times[it] = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Hina-onee-san the time taken for the %d%s iteration is %f\n",
           it + 1,
           (it + 1 == 1)   ? "st"
           : (it + 1 == 2) ? "nd"
           : (it + 1 == 3) ? "rd"
                           : "th",
           times[it]);
    it++;
    size += n;
  }

  return 0;
}

void mergeSort(int arr[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void merge(int arr[], int low, int mid, int high) {
  int leftSize = mid - low + 1;
  int rightSize = high - mid;
  int leftArray[leftSize];
  int rightArray[rightSize];

  for (int i = 0; i < leftSize; i++) {
    leftArray[i] = arr[low + i];
  }

  for (int i = 0; i < rightSize; i++) {
    rightArray[i] = arr[mid + 1 + i];
  }
  int l, r, i;
  l = r = 0;
  i = low;
  while (l < leftSize && r < rightSize) {
    if (leftArray[l] < rightArray[r]) {
      arr[i] = leftArray[l];
      l++;
    } else {
      arr[i] = rightArray[r];
      r++;
    }
    i++;
  }

  while (l < leftSize) {
    arr[i++] = leftArray[l++];
  }

  while (r < rightSize) {
    arr[i++] = rightArray[r++];
  }
}
