#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int res = 0;
char words[25][50];
int g[50][50] = {0};
int used[25] = {0};

int min(int x,int y)
{
    return x>y?y:x;
}

int max(int x,int y)
{
    return x>y?x:y;
}

int size(char* arr)
{
    for(int i = 0;;i++)
    {
        if(*(arr+i) == '\0')
        {
            return i;
        }
    }
}

char* substr(char* a,int x,int y)
{
    char* p = (char*)malloc(sizeof(char)*y);
    for(int i = 0;i<y;i++)
    {
        p[i] = a[x+i];
    }
    p[y] = '\0';
    return p;
}

void dfs( char* dragon,int x)
{
    char p1[100];
    strcpy(p1,dragon);
    res = max(size(p1),res);
    used[x]++;
    for(int i = 0;i < n;i++)
    {
        strcpy(p1,dragon);
        if(g[x][i] && used[i] < 2)
        {
            int a = strlen(words[i]);
            char* p = substr(words[i],g[x][i],a-g[x][i]);
            dfs(strcat(p1,p),i);
            //puts(dragon);
        }
    }
    used[x]--;
    //strcpy(p1,dragon);
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%s",words[i]);
    }
    getchar();
    char start;
    scanf("%c",&start);
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            char a[50];strcpy(a,words[i]);//puts(a);printf("\n");
            char b[50];strcpy(b,words[j]);//puts(b);printf("\n");
            for(int k = 1;k<=min(strlen(a),strlen(b));k++)
            {
                char* p1 = substr(a,strlen(a) - k,k);
                char* p2 = substr(b,0,k);
                if(strcmp(p1,p2) == 0)
                {
                    g[i][j] = k;
                    break;
                }
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        if(words[i][0] == start)
        {
            dfs(words[i],i);
        }
    }
    printf("%d",res);
    return 0;
}