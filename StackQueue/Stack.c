#include "Stack.h"

void StackInit(ST* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

void StackDestory(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

void StackPush(ST* ps,STDateType x)
{
    assert(ps);
    if(ps->capacity == ps->top)
    {
        int newcapacity = ps->capacity== 0 ? 4 : 2*ps->capacity;
        STDateType* tmp = (STDateType*)realloc(ps->a,sizeof(STDateType)*newcapacity);
        if(tmp == NULL)
        {
            printf("realloc fail");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity = newcapacity;
        }
    }
    ps->a[ps->top] = x; 
    ps->top++;
}

void StackPop(ST* ps)
{
    assert(ps);
    assert(ps->top > 0);
    ps->top--;
}

STDateType StackTop(ST* ps)
{
    assert(ps);
    assert(!SatckEmpty(ps));
    return ps->a[ps->top-1];//如果此时栈里没有数据，这里a就会越界
}

int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}

bool SatckEmpty(ST* ps)
{
    return ps->top == 0;
}
