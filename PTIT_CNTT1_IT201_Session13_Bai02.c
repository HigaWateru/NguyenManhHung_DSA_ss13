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
int val;
int main() {
    Stack stack = createStack(5);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &val);
        push(&stack, val);
    }
    printf("Element: [");
    for (int i = 0; i < 5; i++) {
        printf("%d", stack.arr[i]);
        if (i != 4) printf(", ");
    }
    printf("]\n");
    printf("Top: %d\n", stack.top);
    printf("Cap: %d\n", stack.size);
    free(stack.arr);
    return 0;
}