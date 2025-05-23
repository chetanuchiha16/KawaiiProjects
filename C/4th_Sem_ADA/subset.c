#include<stdio.h>
#define MAX 10

void findSubsets(int set[], int include[], int currentSum, int currentIndex, int remainingSum, int targetSum, int totalElements)
{
    include[currentIndex] = 1;

    if ((currentSum + set[currentIndex]) == targetSum)
    {
        printf("{\t");
        for (int i = 0; i <= currentIndex; i++)
        {
            if (include[i] == 1)
                printf("%d\t", set[i]);
        }
        printf("}\n");
    }
    else if ((currentIndex + 1 < totalElements) && (currentSum + set[currentIndex] + set[currentIndex + 1]) <= targetSum)
    {
        findSubsets(set, include, currentSum + set[currentIndex], currentIndex + 1, remainingSum - set[currentIndex], targetSum, totalElements);
    }

    if ((currentSum + remainingSum - set[currentIndex] >= targetSum) &&
        (currentIndex + 1 < totalElements && currentSum + set[currentIndex + 1] <= targetSum))
    {
        include[currentIndex] = 0;
        findSubsets(set, include, currentSum, currentIndex + 1, remainingSum - set[currentIndex], targetSum, totalElements);
    }
}

int main()
{
    int set[MAX], include[MAX];
    int totalElements, targetSum;
    int totalSum = 0;

    printf("Enter the number of elements in the set:\n");
    scanf("%d", &totalElements);

    printf("Enter the set elements in increasing order:\n");
    for (int i = 0; i < totalElements; i++)
    {
        scanf("%d", &set[i]);
        totalSum += set[i];
    }

    printf("Enter the target sum:\n");
    scanf("%d", &targetSum);

    if (totalSum < targetSum)
    {
        printf("\nNo subset possible\n");
    }
    else
    {
        findSubsets(set, include, 0, 0, totalSum, targetSum, totalElements);
    }

    return 0;
}
