// uncertain

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
    Dequeue* new_dq = (Dequeue*)malloc(sizeof(Dequeue));
    new_dq->size = 0;
    new_dq->max_size = max_size;
    new_dq->front = 0;
    new_dq->rear = 0;
    new_dq->arr = (int*)malloc(sizeof(int)*max_size);

    return new_dq;
}

bool is_empty(Dequeue* dq)
{
    return dq->size == 0;
}

bool is_full(Dequeue* dq)
{
    return dq->size >= dq->max_size;
}

void push_front(Dequeue* dq, int data)
{
    if(is_full(dq))
    {
        puts("Error:: in push_front(): dequeue is full");
        exit(-1);
    }

    if(is_empty(dq))
    {
        dq->arr[dq->rear] = data;
        dq->size++;
        return;
    }

    if(dq->front == 0)
    {
        dq->front = dq->max_size - 1;
        dq->arr[dq->rear] = data;
        dq->size++;
        return;
    }

    dq->arr[--(dq->front)] = data;
    dq->size++;
}
void push_back(Dequeue* dq, int data)
{
    if(is_full(dq))
    {
        puts("Error:: in push_back(): dequeue is full");
        exit(-1);
    }

    if(is_empty(dq))
    {
        dq->arr[dq->rear] = data;
        dq->size++;
        return;
    }

    if(dq->rear == dq->max_size - 1)
    {
        dq->rear = 0;
        dq->arr[dq->rear] = data;
        dq->size++;
        return;
    }

    dq->arr[++(dq->rear)] = data;
    dq->size++;
}


void pop_front(Dequeue* dq)
{
    if(is_empty(dq))
    {
        puts("Error:: in push(): queue is empty");
        exit(-1);
    }
    if(dq->front >= dq->max_size - 1)
    {
        dq->front = 0;
        dq->size--;
        return;
    }
    dq->front++;
    dq->size--;
}

void pop_back(Dequeue* dq)
{
    if(is_empty(dq))
    {
        puts("Error:: in pop_back(): queue is empty");
        exit(-1);
    }
    if(dq->rear >= dq->max_size - 1)
    {
        dq->rear = 0;
        dq->size--;
        return;
    }
    dq->rear--;
    dq->size--;
}

int front(Dequeue* dq)
{
    return dq->arr[dq->front];
}
int back(Dequeue* dq)
{
    return dq->arr[dq->rear];
}

int main()
{
    //!!!!
    Dequeue* dq = get_new_dequeue();
    push_back(dq, 10);
    push_back(dq, 20);
    push_front(dq, 0);
    printf("%d", front(dq));
}