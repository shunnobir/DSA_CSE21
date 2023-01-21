#ifndef __STACK_H__
#define __STACK_H__

typedef struct Stack StackCell;
typedef struct Stack {
    int data;
    StackCell *next;
} Stack;


// Helper function to create new stack cells
// Complexity: O(1)
StackCell *stack_cell_new(int data);

// Creates new stack cell with data and pushes it into the stack
// Complexity: O(1)
void stack_push(Stack **stack, int data);

// Removes the top stack cell and returns its data
// Complexity: O(1)
int stack_pop(Stack **stack);

// Returns the top stack cell data
// Complexity: O(1)
int stack_top(Stack *stack);

// Prints all the stack cell from the top to the bottoom of the stack
// Complexity: O(N)
void stack_print(Stack *stack);

// Deletes all the stack cells and frees the memories
// Complexity: O(N)
void stack_delete(Stack **stack);

#endif
