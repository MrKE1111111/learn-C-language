#include <stdio.h>

int k,n;
int arr[10];
int cnt = 0;

void dfs(int x,int start,int sum)
{
    //if(sum+(k-x+1)*arr[x-1] > n) return ;//在这里剪枝的优化程度不如在for循环处直接优化快，因为这样减少了递归次数
    if(x>k)
    {
        if(sum == n)
        {
            cnt++;
            // for(int i = 1;i<=k;i++)
            // {
            //     printf("%d ",arr[i]);
            // }
            // printf("\n");
        }
        return ;
    }
    for(int i = start;sum+(k-x+1)*i<=n;i++)
    {
        arr[x] = i;
        dfs(x+1,i,sum+i);
        arr[x] = 0;
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    dfs(1,1,0);
    printf("%d",cnt);
    return 0;
}