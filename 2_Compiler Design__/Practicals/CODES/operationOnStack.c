#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_CAPACITY 100

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

struct Stack *createStack(unsigned capacity) {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed.\n");
        free(stack);
        return NULL;
    }
    return stack;
}

bool isFull(struct Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

void push(struct Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow, can't push %d\n", item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow, can't pop\n");
        return -1; // Returning an arbitrary value to indicate underflow
    }
    int item = stack->array[stack->top--];
    printf("%d popped from stack\n", item);
    return item;
}

int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty, no top element\n");
        return -1; // Returning an arbitrary value to indicate empty stack
    }
    return stack->array[stack->top];
}

void freeStack(struct Stack *stack) {
    free(stack->array);
    free(stack);
    printf("Stack memory freed\n");
}

int main() {
    struct Stack *stack = createStack(STACK_CAPACITY);
    if (stack == NULL) {
        return -1; // Exiting due to memory allocation failure
    }
    printf("\n");

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    pop(stack);
    pop(stack);
    pop(stack);
    pop(stack); // Trying to pop from an empty stack

    freeStack(stack);
    printf("\n");
    return 0;
}
