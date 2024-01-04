#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[10010];
int q[10010];
int count = 0;
int N,M;
int judge[10010] = {0};//判断这个数是否被用过

void dfs(int x)
{
    if(x>N)
    {
        count++;
        if(count == M+1)
        {
            for(int i = 1;i<=N;i++)
            {
                printf("%d ",arr[i]);
            }
            exit(0);
        }
        return ;
    }
    for(int i = 1;i<=N;i++)
    {
        if(!count)
        {
            i = q[x];
        }
        if(!judge[i])
        {
            arr[x] = i;
            judge[i] = 1;
            dfs(x+1);
            arr[x] = 0;
            judge[i] = 0;
        }
    }
}

int main()
{
    scanf("%d%d",&N,&M);
    for(int i = 1;i<=N;i++)
    {
        scanf("%d",q+i);
    }
    dfs(1);
    return 0;
}