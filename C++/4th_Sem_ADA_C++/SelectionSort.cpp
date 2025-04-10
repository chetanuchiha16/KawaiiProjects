#include <ctime>
#include <iostream>
#include <vector>

class Array {
 public:
  std::vector<long int> arr;
//   int size = 1000;
  Array(int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
      arr.push_back(rand() % size + 1);
    }
  }

  void swap(long int &a, long int &b) {
    long int temp = a;
    a = b;
    b = temp;
  }
  void SelectionSort() {
    for (int i = 0; i < arr.size(); i++) {
      int min = i;
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[j] < arr[min]) {
          min = j;
        }
      }
      swap(arr[i], arr[min]);
    }
  }

  void Merge(int low, int mid, int high) {
    int leftSize = mid - low;
    int rightSize = high - mid + 1;
    int leftArray[leftSize];
    int rightArray[rightSize];
    for(int i = 0; i < leftSize; i++) {
      leftArray[i] = arr[low + i];
    }
    for(int i = 0; i < rightSize; i++) {
      rightArray[i] = arr[mid + 1 + i];
    }

    int left = 0, right = 0, i = low;
    while( left < leftSize && right < rightSize) {
      if(leftArray[left] < rightArray[right]) {
        arr[i] = leftArray[left];
        left++;
      } else {
        arr[i] = rightArray[right];
        right++;
      }
      i++;
    }
    while( left < leftSize) {
      arr[i++] = leftArray[left++];
    }
    while(right < rightSize) {
      arr[i++] = rightArray[right++];
    }

  }

  void MergeSort(int low, int high) {
    if(low < high) {
      int mid = low + (high - low) / 2;
      MergeSort(low, mid);
      MergeSort(mid + 1,high);
      Merge(low, mid, high);
    }
  }

  void print() {
    for (int i : arr) {
      std::cout << i << " ";
    }
    std::cout << "\n";
  }
};

int main() {
  int it = 0, n = 1000, currentSize = 1000;
  double times[10];

  while (it < 10) {
    Array array(currentSize);
    time_t start = clock();
    // array.SelectionSort();
    array.MergeSort(0, currentSize - 1);
    time_t end = clock();
    times[it] = ((double)(end - start)) / CLOCKS_PER_SEC;
    std::cout
        << "I love you Hina senpaiii, here is the time taken for the size "
        << currentSize << " and iteration " << it + 1
        << ((it + 1 == 1)   ? "st"
            : (it + 1 == 2) ? "nd"
            : (it + 1 == 3) ? "rd"
                            : "th")
        << "  " << times[it] << "\n";
    // array.print();
    currentSize += n;
    it++;
  }
  return 0;
}