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
char peek(Stack *stack) {
    if (stack->top >= 0)return stack->arr[stack->top];
    return '\0';
}
bool checkMatching(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}
bool check(char *str) {
    Stack stack = createStack(strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') push(&stack, str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (stack.top == -1 || !checkMatching(peek(&stack), str[i])) return false;
            pop(&stack);
        }
    }
    bool result = stack.top == -1;
    free(stack.arr);
    return result;
}
int main() {
    char str[100];
    fgets(str, 100, stdin);
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    if (check(str)) printf("true");
    else printf("false");
}