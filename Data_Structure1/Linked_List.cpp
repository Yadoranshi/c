#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    Node* next;
    int data;
}Node;

typedef struct List
{
    unsigned int size;
    Node* head;
    Node* tail;
}List;

List* get_new_list()
{
    List* new_list = (List*)malloc(sizeof(List));
    new_list->head = NULL;
    new_list->tail = NULL;
    new_list->size = 0;
    return new_list;
}

bool is_empty(List* list)
{
    return list->size == 0;
}

Node* get_new_node(int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void append(List* list, int data)
{
    if(is_empty(list))
    {
        list->head = get_new_node(data);
        list->tail = list->head;
        list->size++;
        return;
    }
    list->tail->next = get_new_node(data);
    list->tail = list->tail->next;
    list->size++;
}

void insert(List* list, int data, unsigned int idx)
{
    if(idx > list->size)
    {
        puts("Error:: in insert(); out of bound");
        exit(-1);
    }
    if(is_empty(list)) 
    {
        append(list, data);
        return;
    }
    if(idx == 0)
    {
        Node* temp = get_new_node(data);
        temp->next = list->head;
        list->head = temp;
        list->size++;
        return;
    }
    if(idx == list->size)
    {
        append(list, data);
        return;
    }

    Node* current = list->head;
    for(int i = 0; i < idx-1; i++)
    {
        current = current->next;
    }

    Node* temp = get_new_node(data);
    temp->next = current->next;
    current->next = temp;
    list->size++;
}

void remove(List* list, unsigned int idx)
{
    if(is_empty(list))
    {
        puts("Error::in remove(): the list is empty");
        exit(-1);
    }
    if(idx >= list->size)
    {
        puts("Error::in remove(): out of bound");
        exit(-1);
    }

    if(idx == 0)
    {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }

    Node* current = list->head;

    for(int i = 0; i < idx-1; i++)
    {
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
    if(idx == list->size-1) list->tail = current;
    list->size--;
}

int get_elemental(List* list, unsigned int idx)
{
    if(is_empty(list))
    {
        puts("Error:: in get_elemental(): list is empty");
        exit(-1);
    }
    if(idx >= list->size)
    {
        puts("Error:: in get_elemental(): out of bound");
        exit(-1);
    }
    Node* current = list->head;
    for(int i = 0; i < idx; i++)    current = current->next;
    return current->data;
}

void print(List* list)
{
    if(is_empty(list))
    {
        return;
    }
    Node* current = list->head;
    for(int i = 0; i < list->size; i++)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    List* list = get_new_list();
    append(list, 10);
    append(list, 20);
    append(list, 30);
    insert(list, -1, 2);
    append(list, 30);
    print(list);
    printf("%d", get_elemental(list, 3));
}