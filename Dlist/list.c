#include "list.h"

ListNode* ListInit(ListNode* phead)
{
    phead = (ListNode*)malloc(sizeof(ListNode));
    phead->next = phead;
    phead->prev = phead;
    return phead;
}

ListNode* Creatnewnode(LTDateType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->date = x;
    return newnode;
}

void ListDestory(ListNode* phead)
{
    assert(phead);
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        ListNode* next = cur->next;
        free(cur);
        cur = NULL;
        cur = next;
    }
    free(phead);
    phead = NULL;
}

void ListPrint(ListNode* phead)
{
    assert(phead);
    ListNode* cur = phead->next;
    while(cur != phead)
    {
        printf("%d ",cur->date);
        cur = cur->next;
    }
    printf("\n");
}


void ListPushBack(ListNode* phead,LTDateType x)
{
    assert(phead);
    ListNode* newnode = Creatnewnode(x);
    ListNode* tail = phead->prev;
    newnode->next = phead;
    newnode->prev = tail; 
    tail->next = newnode;
    phead->prev = newnode;
}

void ListPopBack(ListNode* phead)
{
    assert(phead);
    assert(phead->next != phead);
    ListNode* tail = phead->prev;
    ListNode* tailprev = tail->prev;
    tailprev->next = phead;
    phead->prev = tailprev;
    free(tail);
    tail = NULL;
}

void ListPushFront(ListNode* phead,LTDateType x)
{
    ListNode* newnode = Creatnewnode(x);
    ListNode* next = phead->next;
    newnode->next = next;
    next->prev = newnode;
    phead->next = newnode;
    newnode->prev = phead;
}

void ListPopFront(ListNode* phead)
{
    assert(phead);
    assert(phead->next != phead);
    ListNode* next = phead->next;
    ListNode* Nextnext = next->next;
    free(next);
    next = NULL;
    phead->next = Nextnext;
    Nextnext->prev = phead;
}

ListNode* ListFind(ListNode* phead,LTDateType x)
{
    ListNode* cur = phead->next;
    while(cur->date != x)
    {
        cur = cur->next;
        if(cur == phead)
        {
            return NULL;
        }
    }
    return cur;
}

void ListInsert(ListNode* phead,ListNode* pos,LTDateType x)
{
    assert(phead);
    ListNode* newnode = Creatnewnode(x);
    ListNode* prev = pos->prev;
    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;
}

void ListErase(ListNode* phead,ListNode* pos)
{
    ListNode* prev = pos->prev;
    ListNode* next = pos->next;
    free(pos);
    pos = NULL;
    prev->next = next;
    next->prev = prev;
}