#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int STDateType;

typedef struct Stack
{
    STDateType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps,STDateType x);
void StackPop(ST* ps);
STDateType StackTop(ST* ps);
int StackSize(ST* ps);
bool SatckEmpty(ST* ps);

