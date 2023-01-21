#include "stack.h"

#include <stdlib.h>
#include <stdio.h>

StackCell *stack_cell_new(int data) {
    StackCell *new = (StackCell*)malloc(sizeof(struct Stack));
    new->data = data;
    new->next = NULL;
    return new;
}

void stack_push(Stack **stack, int data) {
    StackCell *head = *stack;
    StackCell *new = stack_cell_new(data);
    new->next = head;
    *stack = new;
}

int stack_pop(Stack **stack) {
    if (*stack == NULL) {
        return -1;
    }

    StackCell *head = *stack;
    *stack = head->next;
    int data = head->data;
    free(head);
    return data;
}

int stack_top(Stack *stack) {
    if (stack == NULL) {
        return -1;
    }

    int data = stack->data;
    return data;
}

void stack_print(Stack *stack) {
    if (stack == NULL) {
        printf("BOTTOM\n");
        return;
    }

    printf("%d\n", stack->data);
    stack_print(stack->next);
}

void stack_delete(Stack **stack) {
    StackCell *head = *stack;
    while (head != NULL) {
        StackCell *temp = head;
        head = head->next;
        free(temp);
    }

    *stack = NULL;
}
