#include <stdio.h>
#include <stdlib.h>

typedef struct Circular_Queue
{
    unsigned int size;
    unsigned int max_size;
    int front;
    int rear;
    int* arr;
}Circular_Queue;

Circular_Queue* get_new_circular_queue(unsigned int max_size = 10000)
{
    Circular_Queue* new_q = (Circular_Queue*)malloc(sizeof(Circular_Queue));
    new_q->size = 0;
    new_q->max_size = max_size;
    new_q->front = 0;
    new_q->rear = 0;
    new_q->arr = (int*)malloc(sizeof(int)*max_size);

    return new_q;
}

bool is_empty(Circular_Queue* q)
{
    return q->size == 0;
}

bool is_full(Circular_Queue* q)
{
    return q->size >= q->max_size;
}

void push(Circular_Queue* q, int data)
{
    if(is_full(q))
    {
        puts("Error:: in push(): queue is full");
        exit(-1);
    }

    if(is_empty(q))
    {
        q->arr[q->rear] = data;
        q->size++;
        return;
    }

    if(q->rear == q->max_size - 1)
    {
        q->rear = 0;
        q->arr[q->rear] = data;
        q->size++;
        return;
    }

    q->arr[++(q->rear)] = data;
    q->size++;
}

void pop(Circular_Queue* q)
{
    if(is_empty(q))
    {
        puts("Error:: in push(): queue is empty");
        exit(-1);
    }
    if(q->front >= q->max_size - 1)
    {
        q->front = 0;
        q->size--;
        return;
    }
    q->front++;
    q->size--;
}

int front(Circular_Queue* q)
{
    return q->arr[q->front];
}
int back(Circular_Queue* q)
{
    return q->arr[q->rear];
}

int main()
{
    Circular_Queue* q = get_new_circular_queue(3);
    push(q, 10);
    push(q, 20);
    push(q, 30);
    pop(q);
    pop(q);
    push(q, 0);
    push(q, 1);
    pop(q);
    pop(q);

    printf("%d", front(q));
}