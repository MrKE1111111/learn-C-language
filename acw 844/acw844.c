#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct QueueNode
{
    int date;
    struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
    QueueNode* head;
    QueueNode* tail;
}Queue;

void QueuePush(Queue* pq,int x)
{
    assert(pq);
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    newnode->date = x;
    newnode->next = NULL;
    if(pq->head == NULL)
    {
        pq->head = newnode;
        pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

bool QueueEmpty(Queue* pq)
{
    return pq->head == NULL;
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
        pq->head = NULL;
        pq->head = next;
    }
}

int QueueFront(Queue* pq)
{
    assert(pq);
    assert(!QueueEmpty(pq));
    return pq->head->date;
}

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head= pq->tail = NULL;
}

int n,m;
int g[110][110];
int dist[110][110];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
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
        for(int i = 0;i<4;i++)
        {
            int a = first + dx[i];
            int b = second+ dy[i];
            if(a<1 || b<1 || a>n || b>m) continue;
            if(g[a][b] != 0) continue;
            if(dist[a][b] > 0) continue;

            QueuePush(&q,a);
            QueuePush(&q,b);
            dist[a][b] = dist[first][second] + 1;
            if(a == n && b == m) return dist[n][m];
        }
    }
    return dist[n][m];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= m;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    QueueInit(&q);
    int res = bfs(1,1);
    printf("%d",res);
    return 0;
}
