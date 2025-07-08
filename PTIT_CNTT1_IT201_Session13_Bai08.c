#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    if (stack->top == stack->size - 1) return;
    stack->top++;
    stack->arr[stack->top] = val;
}
int pop(Stack *stack) {
    if (stack->top >= 0) return stack->arr[stack->top--];
    return 0;
}
int posifix(char *str) {
    Stack stack = createStack(strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) push(&stack, str[i] - '0');
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
            int a = pop(&stack);
            int b = pop(&stack);
            int result = 0;
            switch (str[i]) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/':
                    if (a == 0) {
                        free(stack.arr);
                        return 0;
                    }
                    result = b / a;
                    break;
            }
            push(&stack, result);
        }
    }
    int final = pop(&stack);
    free(stack.arr);
    return final;
}
int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    printf("%d", posifix(str));
}