#include <stdio.h>

int n;
int arr[5010];
int mem[60000][15];
int count = 0;

void dfs(int x,int sum)
{
    if(sum>n)
    {
        return ;
    }
    if(x > 10)
    {
        if(sum == n)
        {
            //printf("%d ",sum);
            count++;
            for(int i = 1;i<=10;i++)
            {
                mem[count][i] = arr[i];
            }
        }
        return ;
    }
    for(int i = 1;i<=3;i++)
    {
        arr[x] = i;
        dfs(x+1,sum+i);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d",&n);
    dfs(1,0);
    printf("%d\n",count);
    for(int i = 1;i<=count;i++)
    {
        for(int j = 1;j<=10;j++)
        {
            printf("%d ",mem[i][j]);
        }
        printf("\n");
    }
    return 0;
}