#include <stdio.h>
#include <stdlib.h>

typedef struct Dequeue
{
    unsigned int size;
    unsigned int max_size;
    int front;
    int rear;
    int* arr;
}Dequeue;

Dequeue* get_new_dequeue(unsigned int max_size = 10000)
{
    Dequeue* new_q = (Dequeue*)malloc(sizeof(Dequeue));
    new_q->size = 0;
    new_q->max_size = max_size;
    new_q->front = 0;
    new_q->rear = 0;
    new_q->arr = (int*)malloc(sizeof(int)*max_size);

    return new_q;
}

bool is_empty(Dequeue* q)
{
    return q->size == 0;
}

bool is_full(Dequeue* q)
{
    return q->size >= q->max_size;
}

void push(Dequeue* q, int data)
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

void pop_front(Dequeue* q)
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

void pop_back(Dequeue* q)
{
    if(is_empty(q))
    {
        puts("Error:: in pop_back(): queue is empty");
        exit(-1);
    }
    if(q->rear >= q->max_size - 1)
    {
        q->rear = 0;
        q->size--;
        return;
    }
    q->rear--;
    q->size--;
}

int front(Dequeue* q)
{
    return q->arr[q->front];
}
int back(Dequeue* q)
{
    return q->arr[q->rear];
}

int main()
{
    //!!!!
    printf("%d", front(q));
}