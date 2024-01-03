#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDateType;

typedef struct QueueNode
{
    struct QueueNode* next;
    QDateType date;
}QueueNode;

typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);
void QueuePush(Queue* pq,QDateType x);
void QueuePop(Queue* pq);
QDateType QueueFront(Queue* pq);//取队头数据
QDateType QueueBack(Queue* pa);//取队尾数据
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);