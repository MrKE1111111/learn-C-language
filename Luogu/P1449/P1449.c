#include <stdio.h>
#include <stdbool.h>

int N,A,B;
int K[210];
bool judge[210];
int res = 1e9;

int min(int x,int y)
{
    return x>y?y:x;
}

void dfs(int x,int count)
{
    if(x<1 || x>N )
    {
        return ;
    }
    if(x == B)
    {
        res = min(count,res);
        return ;
    }
    judge[x] = true;
    if(x+K[x] <= N && !judge[x+K[x]])
    {
        judge[x+K[x]] = true;
        dfs(x+K[x],count+1);
        judge[x+K[x]] = false;
    }
    if(x-K[x] > 0 && !judge[x-K[x]])
    {
        judge[x-K[x]] = true;
        dfs(x-K[x],count+1);
        judge[x-K[x]] = false;
    }
}

int main()
{
    scanf("%d%d%d",&N,&A,&B);
    for(int i = 1;i<=N;i++)
    {
        scanf("%d",K+i);
    }
    dfs(A,0);
    if(res == 1e9)
    {
        printf("-1");
    }
    else
    {
        printf("%d",res);
    }
    return 0;
}


//如果按下面那种写法，就更容易导致栈溢出，栈的大小一般只有几MB。按照下面那种写法，
//先调用函数在判断的话，就会更频繁的像栈区索要空间，栈的大小也就会更快被用完
//因此我们要先判断该层楼是否去过，在调用dfs，以减少调用dfs的次数


// #include <stdio.h>
// #include <stdbool.h>

// int N,A,B;
// int K[210];
// bool judge[210];
// int res = 1e9;

// int min(int x,int y)
// {
//     return x>y?y:x;
// }

// void dfs(int x,int count)
// {
//     if(x<1 || x>N || judge[x])
//     {
//         return ;
//     }
//     if(x == B)
//     {
//         res = min(count,res);
//         return ;
//     }
//     judge[x] = true;
//     dfs(x+K[x],count+1);
//     judge[x+K[x]] = false;
//     dfs(x-K[x],count+1);
//     judge[x-K[x]] = false;
// }

// int main()
// {
//     scanf("%d%d%d",&N,&A,&B);
//     for(int i = 1;i<=N;i++)
//     {
//         scanf("%d",K+i);
//     }
//     dfs(A,0);
//     if(res == 1e9)
//     {
//         printf("-1");
//     }
//     else
//     {
//         printf("%d",res);
//     }
//     return 0;
// }