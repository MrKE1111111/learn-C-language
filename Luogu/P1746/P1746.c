#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

typedef struct  QueueNode
{
    struct QueueNode* next;
    int date;
}QueueNode;

typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;

bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;
}

int QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->date;
}

void QueuePush(Queue* pq,int x)
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
        free(pq->head);
        //free(pq->tail);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QueueNode* next = pq->head->next;
        free(pq->head);
        pq->head = NULL;
        pq->head = next;
    }
}

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = pq->tail = NULL;
}

int n;
char g[1010][1010];
int dist[1010][1010];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int first_x,first_y,end_x,end_y;
Queue q;

int bfs(int x1,int y1)
{
    memset(dist,-1,sizeof(dist));
    QueuePush(&q,x1);
    QueuePush(&q,y1);
    dist[x1][y1] = 0;
    while(!QueueEmpty(&q))
    {
        int first = QueueFront(&q);
        QueuePop(&q);
        int second = QueueFront(&q);
        QueuePop(&q);
        for(int i = 0;i < 4;i++)
        {
            int a = first + dx[i];
            int b = second + dy[i];
            if(a<1 || a>n || b>n || b<1) continue;
            if(g[a][b] -48 != 0) continue;
            if(dist[a][b] > 0) continue;
            
            QueuePush(&q,a);
            QueuePush(&q,b);
            dist[a][b] = dist[first][second] + 1;
            
            if(a==end_x && b==end_y) return dist[end_x][end_y];
        }
    }
    //return dist[end_x][end_y];
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%s",g[i]+1);
    }
    scanf("%d%d%d%d",&first_x,&first_y,&end_x,&end_y);
    //printf("%d ",g[1][3]);
    QueueInit(&q);
    int res = bfs(first_x,first_y);
    printf("%d",res);
    return 0;
}