#include <stdio.h>
#include <stdlib.h>

typedef struct Heap
{
    unsigned int max_size;
    unsigned int size;
    int* arr;
}Heap;

Heap* get_new_Heap(int max_size = 10000)
{
    Heap* new_heap = (Heap*)malloc(sizeof(Heap));
    new_heap->size = 0;
    new_heap->max_size = max_size;
    new_heap->arr = (int*)malloc(sizeof(int)*max_size);
}

bool is_empty(Heap* heap)
{
    return heap->size == 0;
}

bool is_full(Heap* heap)
{
    return heap->size >= heap->max_size;
}

void push(Heap* heap, int data)
{

}

void pop(Heap* heap)
{

}

int front(Heap* heap)
{

}