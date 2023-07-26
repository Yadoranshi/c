#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    unsigned int size;
    unsigned int max_size;
    int top;
    int* arr;
}Stack;

Stack* get_new_stack(unsigned int max_size = 10000)
{
    Stack* new_stack = (Stack*)malloc(sizeof(Stack));
    new_stack->arr = (int*)malloc(sizeof(int)*max_size);
    new_stack->size = 0;
    new_stack->max_size = max_size;
    new_stack->top = 0;
    return new_stack;
}

bool is_empty(Stack* stack)
{
    return stack->size == 0;
}

bool is_full(Stack* stack)
{
    return stack->size >= stack->max_size;
}

void push(Stack* stack, int data)
{
    if(is_full(stack))
    {
        puts("Error:: in push(): stack is full");
        exit(-1);
    }
    if(is_empty(stack))
    {
        stack->arr[stack->top] = data;
        stack->size++;
        return;
    }
    stack->arr[++stack->top] = data;
    stack->size++;
}

void pop(Stack* stack)
{
    if(is_empty(stack))
    {
        puts("Error:: in pop(): stack is stack");
        exit(-1);
    }
    stack->top--;
    stack->size--;
}

int top(Stack* stack)
{
    if(is_empty(stack))
    {
        puts("Error:: in pop(): stack is stack");
        exit(-1);
    }
    return stack->arr[stack->top];
}

int main()
{
    Stack* s = get_new_stack();
    push(s, 10);
    pop(s);
    push(s, 20);
    printf("%d", top(s));
}