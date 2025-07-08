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
void reverse(Stack *stack) {
    int i, j;
    for(i = 0, j = stack->top; i < j; i++, j--) {
        int temp = stack->arr[i];
        stack->arr[i] = stack->arr[j];
        stack->arr[j] = temp;
    }
}
int n, val;
int main() {
    scanf("%d", &n);
    Stack stack = createStack(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&stack, val);
    }
    reverse(&stack);
    for (int i = 0; i < n; i++) printf("%d ", stack.arr[i]);
    free(stack.arr);
    return 0;
}