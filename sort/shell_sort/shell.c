#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Print(int* arr)
{
    for(int i = 0;i<10;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main()
{
    srand((unsigned int)time(NULL));
    int arr[10];
    for(int i = 0;i<10;i++)
    {
        arr[i] = rand()%20;
    }
    Print(arr);
    int h = 3;
    while(h>=1)
    {
        for(int i = h;i<10;i++)
        {
            for(int j = i;j>=h && arr[j] < arr[j-h];j-=h)
            {
                int temp = arr[j];
                arr[j] = arr[j-h];
                arr[j-h] = temp;
            }
        }
        h /=2;
    }
    Print(arr);
    system("pause");
    return 0;
}