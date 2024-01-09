#include <stdio.h>
#include <stdbool.h>

char g[110][110];
bool st[110][110];
int N,M;
int cnt = 0;

int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {-1,0,1,1,-1,1,0,-1};

void dfs(int x,int y)
{
    for(int i = 0;i<8;i++)
    {
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(x1<0 || y1<0 || x1>=N || y1>=M)
        continue;
        // if(g[x1][y1] != 'W') continue;
        // if(st[x1][y1]) continue;
        
        // st[x1][y1] = true;
        // dfs(x1,y1);
        if(g[x1][y1] == 'W' && !st[x1][y1])
        {
            st[x1][y1] = true;
            dfs(x1,y1);
        }
    }
}

int main()
{
    scanf("%d%d",&N,&M);
    //getchar();
    for(int i = 0;i<N;i++)
    {
        scanf("%s",g[i]);
    }
    for(int i = 0;i<N;i++)
    {
        for(int j = 0;j<M;j++)
        {
            if(g[i][j] == 'W' && !st[i][j])
            {
                st[i][j] = true;
                dfs(i,j);
                cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;
}