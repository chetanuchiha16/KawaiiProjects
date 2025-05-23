#include <stdio.h>
#define MAX 10

void sumOfSubsets(int set[], int include[], int targetSum, int numElements,
                  int currSum, int currIndex, int remainingSum) {
  include[currIndex] = 1;

  if ((currSum + set[currIndex]) == targetSum) {
    printf("{\t");
    for (int i = 1; i <= currIndex; i++)
      if (include[i] == 1) printf("%d\t", set[i]);
    printf("}\n");
  } else if ((currSum + set[currIndex] + set[currIndex + 1]) <= targetSum) {
    sumOfSubsets(set, include, targetSum, numElements, currSum + set[currIndex],
                 currIndex + 1, remainingSum - set[currIndex]);
  }

  if ((currSum + remainingSum - set[currIndex] >= targetSum) &&
      (currSum + set[currIndex + 1] <= targetSum)) {
    include[currIndex] = 0;
    sumOfSubsets(set, include, targetSum, numElements, currSum, currIndex + 1,
                 remainingSum - set[currIndex]);
  }
}

int main() {
  int set[MAX], include[MAX];
  int numElements, targetSum, totalSum = 0;

  printf("Enter the number of elements in the set:\n");
  scanf("%d", &numElements);

  printf("Enter the set elements in increasing order:\n");
  for (int i = 1; i <= numElements; i++) {
    scanf("%d", &set[i]);
  }

  printf("Enter the sum value:\n");
  scanf("%d", &targetSum);

  for (int i = 1; i <= numElements; i++) {
    totalSum += set[i];
  }

  if (totalSum < targetSum) {
    printf("\nNo subset possible\n");
  } else {
    sumOfSubsets(set, include, targetSum, numElements, 0, 1, totalSum);
  }
  return 0;
}