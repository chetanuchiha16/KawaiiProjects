#include <stdio.h>

void swap(int *a, int *b);

int main() {
    int a = 1;
    int b = 10;
    printf("A and b before swap %d\t%d\n",a,b);
    swap(&a,&b);
    printf("A and b after swap %d\t%d",a,b);
    return 0;
}

void swap (int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}