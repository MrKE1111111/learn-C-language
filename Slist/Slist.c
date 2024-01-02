// #include "Slist.h"

// void SLTPrint(SLTNode* phead)
// {
//     SLTNode* cur = phead;
//     while(cur != NULL)
//     {
//         printf("%d->",cur->date);
//         cur = cur->next;
//     }
//     printf("NULL\n");
// }

// void SLTDestory(SLTNode** pphead)
// {
//     SLTNode* tail = *pphead;
//     SLTNode* prev = NULL;
//     while(tail->next)
//     {
//         prev = tail;
//         tail = tail->next;
//         free(prev);
//         prev = NULL;
//     }
//     *pphead = NULL;
// }

// SLTNode* CreatNode(SLTDatetype x)
// {
//     SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
//     newnode->date = x;
//     newnode->next = NULL;
//     return newnode;
// }

// void SLTPushBack(SLTNode** pphead,SLTDatetype x)
// {
//     SLTNode* newnode = CreatNode(x);
//     if(*pphead == NULL)
//     {
//         *pphead = newnode;
//     }//如果不讨论这种情况，那么tail就可能为NULL，那么该程序就会对NULL进行解引用，则程序出错
//     else
//     {
//         SLTNode* tail = *pphead;
//         while(tail->next != NULL)
//         {
//             tail = tail->next;
//         }
//         // tail->next = NULL;
//         // tail->date = x;
//         tail->next = newnode;
//     }
// }

// void SLTPopBack(SLTNode** pphead)
// {
//     assert(*pphead);
//     SLTNode* tail = *pphead;
//     SLTNode* prev = NULL;
//     if(tail->next == NULL)
//     {
//         *pphead = NULL;
//     }
//     else
//     {
//         while(tail->next)
//         {
//             prev = tail;
//             tail = tail->next;
//         }
//         prev->next = NULL;
//         free(tail);
//         tail = NULL;
//         //不能够直接free(tail),因为tail只是一个临时变量，prev->next还是指向原来的地址
//     }
// }

// void SLTPushFront(SLTNode** pphead,SLTDatetype x)
// {
//     SLTNode* newnode = CreatNode(x);
//     newnode->next = *pphead;
//     *pphead = newnode;
// }

// void SLTPopFront(SLTNode** pphead)
// {
//     assert(*pphead);
//     SLTNode* next = (*pphead)->next;
//     free(*pphead);
//     *pphead = NULL;
//     *pphead = next;
// }

// SLTNode* SLTFind(SLTNode* phead,SLTDatetype x)
// {
//     assert(phead);
//     SLTNode* cur = phead;
//     while(cur->date != x)
//     {
//         cur = cur->next;
//         if(cur == NULL)
//         {
//             printf("find fail\n");
//             return NULL;
//         }
//     }
//     return cur;
// }

// void SLTInsert(SLTNode** pphead,SLTNode* pos,SLTDatetype x)
// {
//     assert(pos);
//     assert(*pphead);
//     SLTNode* newnode = CreatNode(x);
//     SLTNode* cur = *pphead;
//     if(cur == pos)
//     {
//         newnode->next = *pphead;
//         *pphead = newnode;
//     }
//     else
//     {
//         while(cur->next != pos)
//         {
//             cur = cur->next;
//         }
//         newnode->next = pos;
//         cur->next = newnode;
//         //这个顺序不能反，反了的话，newnode->next 就找不到了
//     }
// }

// void SLTErase(SLTNode** pphead,SLTNode* pos)
// {
//     assert(*pphead);
//     SLTNode* cur = *pphead;
//     if(cur == pos)
//     {
//         SLTNode* next = cur->next;
//         free(*pphead);
//         *pphead = NULL;
//         *pphead = next;
//     }
//     else
//     {
//         while(cur->next != pos)
//         {
//             cur = cur->next;
//         }
//         cur->next = pos->next;
//         free(pos);
//         pos = NULL;
//     }
// }