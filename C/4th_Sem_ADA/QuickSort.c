#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int low, int high);
int partition(int low, int high);
void swap(int *a, int *b);

int a[100000];
int i, j, n, key, low, high;
time_t t;

int main() {
  clock_t start, end;
  double d;
  printf("input n\n");
  scanf("%d", &n);
  srand((unsigned)time(&t));
  printf("random array elements \n");
  for (i = 0; i < n; i++) a[i] = rand() % 100;
  printf("array elements are\n");
  for (i = 0; i < n; i++) printf("%d\n", a[i]);
  start = clock();
  quicksort(0, n - 1);
  end = clock();
  d = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time complexity =%f\n", d);
  printf("sorted elements are\n");
  for (i = 0; i < n; i++) printf("%d\n", a[i]);
  return 0;
}

void quicksort(int low, int high) {
  if (low < high) {
    j = partition(low, high);
    quicksort(low, j - 1);
    quicksort(j + 1, high);
  }
}

int partition(int low, int high) {
  key = a[low];
  i = low + 1;
  j = high;
  while (1) {
    while (i < high && key >= a[i]) i++;
    while (key < a[j]) j--;
    if (i < j)
      swap(&a[i], &a[j]);
    else {
      swap(&a[j], &a[low]);
      return j;
    }
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

