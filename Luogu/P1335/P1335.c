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


//下面这种写法回到更容易导致栈溢出，栈的大小一般很小，只有几MB
//每次调用dfs就会像栈索要空间，那么如果像下面那种写法，等调用函数之后
//再判断这层楼是否来过就会频繁向栈索要空间，因此我们要先判断该层楼是否来过
//在调用dfs，减少向栈索要的空间


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