#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int n;
bool elect = false;
int sour[15];
int bitter[15];
int st[15];
int res = 1e9;

int min(int x,int y)
{
    return x>y?y:x;
}

void dfs(int x)
{
    if(x>n)
    {
        int sum_s = 1;
        int sum_b = 0;
        for(int i = 1;i<=n;i++)
        {
            if(st[i] == 1)
            {
                elect = true;
                sum_s *=sour[i];
                sum_b += bitter[i];
            }
        }
        if(elect)
        res = min(res,fabs(sum_s - sum_b));
        return ;
    }
    st[x] = -1;
    dfs(x+1);
    //st[x] = 0;
    st[x] = 1;
    dfs(x+1);
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        scanf("%d%d",sour+i,bitter+i);
    }
    dfs(1);
    printf("%d",res);
    return 0;
}