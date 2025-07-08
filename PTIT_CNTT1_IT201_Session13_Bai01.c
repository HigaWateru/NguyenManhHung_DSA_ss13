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
int main() {
    Stack stack = createStack(5);
    printf("%d", stack.size);
    free(stack.arr);
    return 0;
}