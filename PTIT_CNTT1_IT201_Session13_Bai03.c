#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int top;
    int size;
} Stack;
Stack createStack(int size) {
    Stack stack;
    stack.arr = (int*)malloc(size * sizeof(int));
    stack.top = -1;
    stack.size = size;
    return stack;
}
void push(Stack *stack, int val) {
    if (stack->top == stack->size - 1) {
        printf("Stack da day\n");
        return;
    }
    stack->top++;
    stack->arr[stack->top] = val;
}
int pop(Stack *stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return stack->arr[stack->top--];
}
int val;
int main() {
    Stack stack = createStack(5);

    printf("%d", pop(&stack));
    free(stack.arr);
    return 0;
}