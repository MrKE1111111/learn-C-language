#include <stdio.h>

int main()
{
    int arr[] = {4,8,2,9,0,1,3,7,6,5};
    int k=0,j=1;
    for(k = 0;k<10;k++)
    {
        int i = k;
        for(j = k+1;j<10;j++)
        {
            if(arr[j] < arr[i])
            {
                i = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[k];
        arr[k] = temp;
    }
    for(int n = 0;n<10;n++)
    {
        printf("%d ",arr[n]);
    }
    return 0;
}
