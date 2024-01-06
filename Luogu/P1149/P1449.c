#include <stdio.h>

int n;
int count = 0;
int arr[5];
int total[1000] = {6,2,5,5,4,5,6,3,7,6};

void dfs(int x,int sum)
{
    if(sum>n)
    {
        return ;
    }
    if(x>3)
    {
        if(arr[1] + arr[2] == arr[3] && sum == n -4)
        {
            // printf("%d\n",sum);
            // printf("%d %d %d\n",arr[1],arr[2],arr[3]);
            count++;
        }
        return ;
    }
    for(int i = 0;i<=1000;i++)
    {
        arr[x] = i;
        dfs(x+1,sum+total[i]);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 10;i<=1000;i++)
    {
        int t = i;
        while(t)
        {
            total[i] += total[t%10];
            t /= 10;
        }
    }
    dfs(1,0);
    printf("%d",count);
    return 0;
}