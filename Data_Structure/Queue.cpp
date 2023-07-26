#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    unsigned int size;
    unsigned int max_size;
    int* arr;
    int front;
    int rear;
}Queue;

Queue* get_new_queue(unsigned int max_size = 10000)
{
    Queue* new_q = (Queue*)malloc(sizeof(Queue));
    new_q->front = 0;
    new_q->rear = 0;
    new_q->max_size = max_size;
    new_q->arr = (int*)malloc(sizeof(int)*max_size);
    new_q->size = 0;
    return new_q;
}

bool is_full(Queue* q)
{
    return q->rear >= q->max_size - 1;
}

bool is_empty(Queue* q)
{
    return q->size == 0;
}

void push(Queue* q, int data)
{
    if(is_full(q))
    {
        puts("Error:: in push: queue is full");
        exit(-1);
    }
    if(is_empty(q))
    {
        q->arr[q->front] = data;
        q->size++;
        return;
    }
    q->arr[++q->rear] = data;
    q->size++;
    return;
}

void pop(Queue* q)
{
    if(is_empty(q))
    {
        puts("Error:: in pop: queue is empty");
        exit(-1);
        return;
    }
    q->size--;
    q->front++;
}

int back(Queue*q)
{
    if(is_empty(q))
    {
        puts("Error:: in pop: queue is empty");
        exit(-1);
    }
    return q->arr[q->rear];
}

int front(Queue* q)
{
    if(is_empty(q))
    {
        puts("Error:: in fornt: queue is empty");
        exit(-1);
        return -1;
    }
    return q->arr[q->front];
}

int main()
{
    Queue* q = get_new_queue();
    push(q, 1);
    push(q, 2);

}