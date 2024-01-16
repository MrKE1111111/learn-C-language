#include <stdio.h>

int main()
{
    int arr[] = {1,2,3,7,6,5,4,9,8,0};
    for(int i = 1;i<10;i++)
    {
        for(int j = i;j>=1 && (arr[j] < arr[j-1]);j--)
        {
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
        }
    }
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}