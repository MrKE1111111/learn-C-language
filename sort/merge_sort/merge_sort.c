#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20

void Print(int* arr,int length)
{
    for(int i = 0;i<length;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void Initarry(int* arr,int length)
{
    srand((unsigned int)time(NULL));
    for(int i = 0;i < length;i++)
    {
        arr[i] = rand()%30;
    }

}

void merge(int* arr,int left,int mid,int right,int* temp)
{
    int i = left;
    int j = mid+1;
    int k = left;
    while(i<=mid && j<=right)
    {
        temp[k++] = arr[i]>arr[j]?arr[j++]:arr[i++];
    }
    while(i<=mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    for(int i = left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
}

void divide(int* arr,int left,int right,int* temp)
{
    if(left>=right) return ;
    int mid = (left + right)/2;
    divide(arr,left,mid,temp);
    divide(arr,mid+1,right,temp);
    merge(arr,left,mid,right,temp);
}

void merge_sort(int* arr,int length)
{
    int* temp = (int*)malloc(sizeof(int)*length);
    assert(temp);
    divide(arr,0,length-1,temp);
    free(temp);
}

int main()
{
    int arr[MAXSIZE];
    Initarry(arr,MAXSIZE);
    Print(arr,MAXSIZE);
    merge_sort(arr,MAXSIZE);
    Print(arr,MAXSIZE);
    system("pause");
    return 0;
}