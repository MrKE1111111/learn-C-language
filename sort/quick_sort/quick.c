#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAXSIZE 150

void Swap(int* arr,int x,int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void Quick1sort(int* arr,int left,int right)//6 4 3 9 0 2 8 7 1 5//5 4 3 9(i) 0 2 8 7 1 5(j)//5 4 3 9(i) 0 2 8 7 1(j) 9//
//5 4 3 1 0 2 8(i) 7 1(j) 9 // 5 4 3 1 0 2 8(i,j) 7 8 9//5 4 3 1 0 2 6 7 8 9
{
    if(left>=right) return ;
    int pivot = arr[left];
    int i = left;
    int j = right;
    while(i<j)
    {
        while(i < j && arr[j] >= pivot) j--;
        arr[i] = arr[j];
        while(i< j && arr[i] <= pivot) i++;
        arr[j] = arr[i];
    }
    arr[i] = pivot;
    Quick1sort(arr,left,i-1);
    Quick1sort(arr,i+1,right);
}

void Quick2sort(int* arr,int left,int right)
{
    if(left>=right) return ;
    int pivot = arr[left];
    int i = left + 1;
    int j = right + 1;
    while(j<=right)
    {
        if(arr[j] < pivot)
        {
            Swap(arr,i,j);
            i++;
        }
        j++;
    }
    Swap(arr,left,i-1);
    Quick2sort(arr,left,i-2);
    Quick2sort(arr,i,right);
}

void Print(int* arr)
{
    for(int i = 0;i<MAXSIZE;i++)
    printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[MAXSIZE];
    for(int i = 0;i < MAXSIZE;i++)
    {
        arr[i] = rand()%20;
    }
    Print(arr);
    Quick1sort(arr,0,MAXSIZE-1);
    Print(arr);
    Quick2sort(arr,0,MAXSIZE-1);
    Print(arr);
    system("pause");
    return 0;
}