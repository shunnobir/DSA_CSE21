#include "stack.h"

#include <stdio.h>

#define STACK_SIZE 10

int main() {
    Stack *stack;

    for (int i = 0; i < STACK_SIZE; ++i) {
        stack_push(&stack, i+1);
    }

    stack_print(stack);
    
    printf("Stack top: %d\n", stack_top(stack));
    for (int i = 0; i < STACK_SIZE / 2; ++i) {
        stack_pop(&stack);
        printf("Stack top: %d\n", stack_top(stack));
    }

    stack_print(stack);
    stack_delete(&stack);
}
