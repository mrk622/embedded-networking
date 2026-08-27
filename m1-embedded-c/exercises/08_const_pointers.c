#include <stdio.h>

int main(void) {
    int a = 10;
    int b = 20;

    const int *ptr1 = &a;
    int *const ptr2 = &a;
    const int *const ptr3 = &a;

    ptr1 = &b;
    *ptr2 = 5;

    return 0;
}
