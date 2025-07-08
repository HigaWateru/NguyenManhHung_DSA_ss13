#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
void push(Stack *stack, char c) {
    if (stack->top == stack->size - 1) return;
    stack->top++;
    stack->arr[stack->top] = c;
}
char pop(Stack *stack) {
    if (stack->top == -1) return '\0';
    return stack->arr[stack->top--];
}
bool checkReverse(char *str) {
    int size = strlen(str);
    Stack stack = createStack(size);
    for (int i = 0; i < size / 2; i++) push(&stack, str[i]);
    int cur = (size % 2 == 0) ? size / 2 : size / 2 + 1;
    while (cur < size) if (pop(&stack) != str[cur++]) return false;
    free(stack.arr);
    return true;
}
int main() {
    char str[100];
    fgets(str, 100, stdin);
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    if (checkReverse(str)) printf("true");
    else printf("false");
}