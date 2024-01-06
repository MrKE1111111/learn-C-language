#include <stdio.h>
#include <stdbool.h>

int W,H;
int cnt = 0;
char g[25][25];
int dx[] = {-1,0,1,0};//上左下右
int dy[] = {0,-1,0,1};
bool st[25][25];

void dfs(int x,int y)
{
    st[x][y] = true;
    for(int i = 0;i<4;i++)
    {
        int x1 = x+dx[i];
        int y1 = y+dy[i];
        if(x1<0 || y1>=W || y1<0 || x1>=H)
        continue ;
        if(g[x1][y1] == '.' && !st[x1][y1])
        {
            cnt++;
            st[x1][y1] = true;
            dfs(x1,y1);
        }
    }
}

int main()
{
    scanf("%d%d",&W,&H);
    getchar();
    for(int i = 0;i<H;i++)
    {
        scanf("%s",g[i]);
    }
    for(int i = 0;i<H;i++)
    {
        for(int j = 0;j<W;j++)
        {
            if(g[i][j] == '@')
            {
                dfs(i,j);
                break;
            }
        }
    }
    printf("%d",cnt+1);
    return 0;
}