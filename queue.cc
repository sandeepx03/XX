#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{   
    float data;
    struct Node* next;
};

struct Queue
{
    struct Node *head, *tail;
};

struct Node* newNode(float data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Queue* createQueue()
{
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->head = NULL;
    q->tail = NULL;
    return q;
}

void enqueue(struct Queue* q, float data)
{
    struct Node* temp = newNode(data);

    if (q->tail == NULL)
    {
        q->head = temp;
        q->tail = temp;
        return;
    }

    q->tail->next = temp;
    q->tail = temp;
}
float dequeue(struct Queue *q)
{

    if (q->head == NULL)
        return -1;

    struct Node* temp = q->head;
    float result = temp->data;
    q->head = q->head->next;

    if (q->head == NULL)
        q->tail = NULL;

    free(temp);
    return result;
}
