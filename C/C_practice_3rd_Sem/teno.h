#include <stdio.h>

extern int global_ = 7;
int main() {

    int  global_ = 5;
    printf("%d",  global_);

    /*
    int a = 50;
    int b = 6;
    float c = a/b;
    printf("%f",c);
    */

    return 0;
}