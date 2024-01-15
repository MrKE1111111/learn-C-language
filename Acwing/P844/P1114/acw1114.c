#include <stdio.h>
#include <stdbool.h>

int n,k;
char g[10][10];
bool st[10];
int res = 0;

void dfs(int x,int cnt)
{
    if(cnt == k)
    {
        res++;
        return ;
    }
    if(x==n) return ;
    
    for(int i= 0;i<n;i++)
    {
        if(!st[i] && g[x][i] == '#')
        {
            st[i] = true;
            dfs(x+1,cnt+1);
            st[i] = false;
        }
    }
    dfs(x+1,cnt);
}

int main()
{
    scanf("%d%d",&n,&k);
    while(n!=-1)
    {
        for(int i = 0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        dfs(0,0);
        scanf("%d%d",&n,&k);
        printf("%d\n",res);
        res = 0;
    }
    return 0;
}