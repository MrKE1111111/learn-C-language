#include <stdio.h>

int main()
{
    int arr[] = {4,8,2,1,9,0,5,7,3,6};
    int flag = 0;
    for(int i = 0;i<10;i++)
    {
        for(int j = 0;j<10-1-i;j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag = 1;
                arr[j] = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j] = arr[j]^arr[j+1];
            }
        }
        if(!flag)
        {
            break;
        }
    }
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}