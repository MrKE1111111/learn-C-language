#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDateType;

typedef struct List
{
    struct List* next;
    struct List* prev;
    LTDateType date;
}ListNode;


ListNode* ListInit(ListNode* phead);
ListNode* Creatnewnode(LTDateType x);
void ListPrint(ListNode* phead);
void ListDestory(ListNode* phead);
void ListPushBack(ListNode* phead,LTDateType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead,LTDateType x);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead,LTDateType x);
void ListInsert(ListNode* phead,ListNode* pos,LTDateType x);
void ListErase(ListNode* phead,ListNode* pos);
