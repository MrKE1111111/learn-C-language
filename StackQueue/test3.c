#include "Stack.h"

void StackTest1()
{
    ST ps;
    StackInit(&ps);

    StackPush(&ps,1);
    StackPush(&ps,2);
    StackPush(&ps,3);
    StackPush(&ps,4);
    //StackPop(&ps);
    // StackPop(&ps);
    // StackPop(&ps);
    //  StackPop(&ps);
    //  StackPop(&ps);
    //  StackPop(&ps);
    // //int top= StackTop(&ps);
    // int size = StackSize(&ps);
    // printf("%d",size);
    while(!SatckEmpty(&ps))
    {
        printf("%d ",StackTop(&ps));
        StackPop(&ps);
    }
}

int main()
{
    StackTest1();
    return 0;
}