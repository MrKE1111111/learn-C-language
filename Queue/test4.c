#include "Queue.h"

void TestQueue1()
{
    //要改变结构体里的内容，就传结构体的指针
    int size = 0;
    Queue q;
    //printf("%d ",QueueEmpty(&q));
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);
    printf("%d ",QueueEmpty(&q));
    size = QueueSize(&q);
    printf("%d ",size);
    QueuePop(&q);
    QueuePop(&q);
    QueuePop(&q);
    size = QueueSize(&q);
    printf("%d ",size);
    QueuePop(&q);
    size = QueueSize(&q);
    printf("%d ",size);
    printf("%d ",QueueEmpty(&q));
}

void TestQueue2()
{
    Queue q;
    QueueInit(&q);
    QueuePush(&q,1);
    QueuePush(&q,2);
    QueuePush(&q,3);
    QueuePush(&q,4);
    printf("%d ",QueueFront(&q));
    printf("%d ",QueueBack(&q));
    while(!QueueEmpty(&q))
    {
        printf("%d ",(&q)->head->date);
        QueuePop(&q);
    }
    printf("\n");
    // printf("%d ",QueueFront(&q));
    // printf("%d ",QueueBack(&q));
}

int main()
{
    //TestQueue1();
    //TestQueue2();
    return 0;
}