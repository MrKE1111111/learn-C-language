// #include "SeqList.h"

// void SeqListInit(SL* ps)
// {
//     ps->a = NULL;
//     ps->size = ps->capacity = 0;
// }

// void SeqListPrint(SL* ps)
// {
//     for(int i = 0;i<ps->size;i++)
//     {
//         printf("%d ",ps->a[i]);
//     }
//     printf("\n");
// }

// void SeqListCheckCapacity(SL* ps)
// {
//     if(ps->size == ps->capacity)
//     {
//         int newcapacity = ps->capacity == 0? 4 : ps->capacity*2;
//         SLDateType* tmp = (SLDateType*)realloc(ps->a,sizeof(SLDateType)*newcapacity);
//         if(tmp == NULL)
//         {
//             printf("realloc fail");
//             exit(-1);
//         }
//         ps->a = tmp;
//         ps->capacity = newcapacity;
//     }
// }

// void SeqListPushBack(SL* ps,SLDateType x)
// {
//     SeqListCheckCapacity(ps);
//     ps->a[ps->size] = x;
//     ps->size++;
// }

// void SeqListPopBack(SL* ps)
// {
//     assert(ps->size > 0);
//     ps->size--;
// }

// void SeqListPushFront(SL* ps,SLDateType x)
// {
//     SeqListCheckCapacity(ps);
//     int end = ps->size;
//     // for(int i = 0;i<end;i++)
//     // {
//     //     ps->a[i+1] = ps->a[i];
//     // }这是错误的，比如 1 2 3 4 5，第一次循环就会变成 1 1 2 4 5，第二次循环 1 1 1 4 5，因此要从最右边移动
//     while(end)
//     {
//         ps->a[end] = ps->a[end-1];
//         end--;
//     }
//     ps->a[0] = x;
//     ps->size++;
// }

// void SeqListPopFront(SL* ps)
// {
//     assert(ps->size>0);
//     int begin = 0;
//     for(begin = 0;begin<ps->size-1;begin++)
//     {
//         ps->a[begin] = ps->a[begin+1];
//     }
//     ps->size--;
// }

// void SeqListDestory(SL* ps)
// {
//     free(ps->a);//不能写成free(ps)
//     ps->a = NULL;
//     ps->size = ps->capacity = 0;
// }

// void SeqListInsert(SL* ps,SLDateType x,int pos)// 1 2 3 4 5
// {
//     SeqListCheckCapacity(ps);
//     int begin = pos - 1;
//     int end = ps->size;
//     for(int i = end;i>begin;i--)
//     {
//         ps->a[i] = ps->a[i-1];
//     }
//     ps->a[begin] = x;
//     ps->size++;//别忘了这一步骤
// }

// void SeqListErase(SL* ps,int pos)
// {
//     if(pos > ps->size)
//     {
//         printf("此位置未赋值\n");
//         return ;
//     }
//     assert(ps->size>0);
//     int begin = pos-1;
//     for(int i = begin;i<ps->size-1;i++)
//     {
//         ps->a[i] = ps->a[i+1];
//     }
//     ps->size--;
//     //assert(ps->size> = 0);
// }

// void SeqListFind(SL* ps,int x,int *arr)
// {
//     int j = 0;
//     for(int i = 0;i<ps->size;i++)
//     {
//         if(ps->a[i] == x)
//         {
//             arr[j] = i;
//             j++;
//         }
//     }
// }