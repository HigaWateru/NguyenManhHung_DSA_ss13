#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
void push(Stack *stack, char *str) {
    stack->arr[++stack->top] = strdup(str);
}
char *pop(Stack *stack) {
    if (stack->top == -1) return NULL;
    return stack->arr[stack->top--];
}
bool operator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/';
}
char *infix(char *str) {
    Stack stack = createStack(strlen(str));
    for (int i = 0; i < strlen(str); i++) {
        if (isalnum(str[i])) {
            char *oper = (char*)malloc(2 * sizeof(char));
            oper[0] = str[i];
            oper[1] = '\0';
            push(&stack, oper);
        }
        else if (operator(str[i])) {
            char *a = pop(&stack);
            char *b = pop(&stack);
            char *result = (char*)malloc((strlen(a) + strlen(b) + 4) * sizeof(char));
            sprintf(result, "(%s%c%s)", b, str[i], a);
            push(&stack, result);
            free(a);
            free(b);
        }
    }
    char *result = pop(&stack);
    free(stack.arr);
    return result;
}
int main() {
    char str[100];
    fgets(str, sizeof(str), stdin);
    if (str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    char *result = infix(str);
    printf("%s", result);
    free(result);
}
