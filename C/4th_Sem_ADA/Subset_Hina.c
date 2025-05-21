#include <stdio.h>
#define MAX 10

void findSubsets(int set[], int include[], int targetSum,
                 int currentSum, int currentIndex, int remainingSum) {
  int i;
  include[currentIndex] = 1;

  if ((currentSum + set[currentIndex]) == targetSum) {
    printf("{\t");
    for (i = 1; i <= currentIndex; i++) {
      if (include[i] == 1) printf("%d\t", set[i]);
    }
    printf("}\n");
  } else if ((currentSum + set[currentIndex] + set[currentIndex + 1]) <=
             targetSum) {
    findSubsets(set, include,targetSum,
                currentSum + set[currentIndex], currentIndex + 1,
                remainingSum - set[currentIndex]);
  }

  if ((currentSum + remainingSum - set[currentIndex] >= targetSum) &&
      (currentSum + set[currentIndex + 1] <= targetSum)) {
    include[currentIndex] = 0;
    findSubsets(set, include, targetSum, currentSum,
                currentIndex + 1, remainingSum - set[currentIndex]);
  }
}

int main() {
  int set[MAX];
  int include[MAX] = {0};
  int targetSum, totalElements, totalSetSum = 0;

  printf("Enter the number of elements in the set:\n");
  scanf("%d", &totalElements);

  printf("Enter the set elements in increasing order:\n");
  for (int i = 1; i <= totalElements; i++) scanf("%d", &set[i]);

  printf("Enter the target sum:\n");
  scanf("%d", &targetSum);

  for (int i = 1; i <= totalElements; i++) totalSetSum += set[i];

  if (totalSetSum < targetSum)
    printf("\nNo subset possible\n");
  else
    findSubsets(set, include, targetSum, 0, 1, totalSetSum);

  return 0;
}
