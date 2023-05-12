#include <stdio.h>
#include <stdlib.h>

struct ListNode
{ 
  int val;
  ListNode* next;
  ListNode* prev;
  
};

void add_to_front(struct ListNode** begin, int value)
{   
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    ptr->val = value;
    
    ptr->next = (*begin);
    ptr->prev = NULL;
    
    if ((*begin) != NULL)
    {   
        (*begin)->prev = ptr;
    }
    
    *begin = ptr;
}
void add_to_back(struct ListNode** begin, int value)
{
    struct ListNode* ptr = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* tail = *begin;

    ptr->val = value;
    ptr->next = NULL;

    if (*begin == NULL)
    {
        ptr->prev = NULL;
        *begin = ptr;
        return;
    }

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = ptr;
    ptr->prev = tail;
}
int first(struct ListNode* begin)
{   
    struct ListNode *ptr = begin;
    
    if (ptr != NULL)
    {   
        while (ptr->prev != NULL)
            ptr = ptr->prev;
    }
    return ptr->val;
}
int last(struct ListNode* begin)
{   
    struct ListNode *ptr = begin;
    
    if (ptr != NULL)
    {   
        while (ptr->next != NULL)
            ptr = ptr->next;
    }
    return ptr->val;
}
void remove(struct ListNode** begin, struct ListNode* deleteNode)
{
    if (*begin == NULL || deleteNode == NULL)
    {
        return;
    }
    if (*begin == deleteNode)
    {
        *begin = deleteNode->next;
    }
    if (deleteNode->next != NULL)
    {
        deleteNode->next->prev = deleteNode->prev;
    }
    if (deleteNode->prev != NULL)
    {
        deleteNode->prev->next = deleteNode->next;
    }

    free(deleteNode);
}
struct ListNode* previous(struct ListNode* node)
{
    struct ListNode *ptr = node;

    if (ptr != NULL)
    {
        if (ptr->prev != NULL)
            ptr = ptr->prev;
    }
    else
    {
        return NULL;
    }
    return ptr;
}
struct ListNode* next(struct ListNode* node)
{
    struct ListNode* ptr = node;

    if (ptr != NULL)
    {
        if (ptr->prev != NULL)
            ptr = ptr->next;
    }
    else
    {
        return NULL;
    }
    return ptr;
}
struct ListNode* search_value(struct ListNode* begin, int value)
{
    struct ListNode* ptr = begin;

    if (ptr != NULL)
    {
        while (ptr->next != NULL)
        {
            if (ptr->val == value)
                return ptr;
            ptr = ptr->next;
        }
    }
    else
    {
        return NULL;
    }
    return ptr;

}
