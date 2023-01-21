#include <stdio.h>

void swap(int **a, int **b) {
    int *temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct Node {
    struct Node *next;  
} Node;

void list_insert(Node **head, Node *new) {
    new->next = *head;
    *head = new;
}

int main() {
    int a, b;
    int *aptr = &a, *bptr = &b;
    printf("Before swapping: aptr = %p, bptr = %p\n", aptr, bptr);

    swap(&aptr, &bptr);
    printf("After swapping: aptr = %p, bptr = %p\n", aptr, bptr);
}
