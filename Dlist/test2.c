#include "list.h"

void LTTest1()
{
    ListNode* phead;
    phead = ListInit(phead);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushBack(phead,5);
    ListPrint(phead);
    ListPopBack(phead);
    ListPopBack(phead);
    ListPopBack(phead);
    ListPopBack(phead);
    ListPopBack(phead);
    //ListPopBack(phead);
    ListPrint(phead);
}

void LTTest2()
{
    ListNode* phead;
    phead = ListInit(phead);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushBack(phead,5);
    ListPrint(phead);
    // ListPushFront(phead,1);
    // ListPushFront(phead,2);
    // ListPushFront(phead,3);
    // ListPushFront(phead,4);
    // ListPushFront(phead,5);
    // ListPopFront(phead);
    // ListPopFront(phead);
    // ListPopFront(phead);
    // ListPopFront(phead);
    // ListPopFront(phead);
    // ListPopFront(phead);
    // ListPrint(phead);
    ListDestory(phead);
    phead = NULL;
}

void LTTset3()
{
    ListNode* phead;
    phead = ListInit(phead);
    ListPushBack(phead,1);
    ListPushBack(phead,2);
    ListPushBack(phead,3);
    ListPushBack(phead,4);
    ListPushBack(phead,5);
    ListPrint(phead);
    ListNode* pos = ListFind(phead,4);
    ListInsert(phead,pos,40);
    pos = ListFind(phead,1);
    ListInsert(phead,pos,10);
    ListPrint(phead);
    pos = ListFind(phead,10);
    ListErase(phead,pos);
    pos = ListFind(phead,5);
    ListErase(phead,pos);
    ListPrint(phead);
}


int main()
{
    //LTTest1();
    //LTTest2();
    LTTset3();
    return 0;
}