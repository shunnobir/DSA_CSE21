#include <stdio.h>

void swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b;
    int *aptr = &a, *bptr = &b;
    printf("Before swapping: aptr = %p, bptr = %p\n", aptr, bptr);

    swap(&aptr, &bptr);
    printf("After swapping: aptr = %p, bptr = %p\n", aptr, bptr);
}
