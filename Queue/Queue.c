#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
    assert(pq);
    QueueNode* cur = pq->head;
    //while(cur != pq->tail)
    //这样写最后一个节点就没删掉
    while(cur != NULL)
    {
        // QueueNode* prev = cur;
        // free(prev);
        // prev = NULL;
        // cur = cur->next;
        //这样写的话，那么最后一个节点也没删掉
        QueueNode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq,QDateType x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->date = x;
    newnode->next = NULL;
    if(pq->head == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    if(pq->head == pq->tail)
    {
        pq->head = pq->tail = NULL;
    }
    else
    {
        QueueNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
    //当删到最后一个时,pq->head变为NULL,但是此时pq->tail还是原来的地址，此时我们需要芭pq->tail置为NULL
}

QDateType QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->date;
}

QDateType QueueBack(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->tail->date;
}

int QueueSize(Queue* pq)
{
    int size = 0;
    QueueNode* cur = pq->head;
    while(cur != NULL)
    {
        cur = cur->next;
        size++;
    }
    return size;
}

bool QueueEmpty(Queue* pq)
{
    return pq->head == NULL;
}



// 队头弹出<--  head->next->next->next->next->tail  <--队尾进入