// #include "Slist.h"

// void SLTTest1()
// {
//     SLTNode* plist = NULL;
//     SLTPushBack(&plist,1);
//     SLTPushBack(&plist,2);
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,4);
//     SLTPushBack(&plist,5);
//     SLTPrint(plist);
//     SLTPushFront(&plist,1);
//     SLTPushFront(&plist,2);
//     SLTPushFront(&plist,3);
//     SLTPushFront(&plist,4);
//     SLTPushFront(&plist,5);
//     SLTPrint(plist);
// }

// void SLTTest2()
// {
//     SLTNode* plist = NULL;
//     SLTPushBack(&plist,1);
//     SLTPushBack(&plist,2);
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,4);
//     SLTPushBack(&plist,5);
//     SLTPrint(plist);
//     // SLTPopBack(&plist);
//     // SLTPopBack(&plist);
//     // SLTPopBack(&plist);
//     // SLTPopBack(&plist);
//     // SLTPopBack(&plist);
//     // SLTPopBack(&plist);
//     // SLTPopFront(&plist);
//     // SLTPopFront(&plist);
//     // SLTPopFront(&plist);
//     // SLTPopFront(&plist);
//     // SLTPopFront(&plist);
//     // SLTPopFront(&plist);
//     SLTDestory(&plist);
//     SLTPrint(plist);
// }

// void SLTTest3()
// {
//     SLTNode* plist = NULL;
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,2);
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,4);
//     SLTPushBack(&plist,5);
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,4);
//     SLTPushBack(&plist,5);
//     SLTPrint(plist);
//     SLTNode* pos = SLTFind(plist,3);
//     printf("%p\n",pos);
//     while(pos->next)
//     {
//         pos = pos->next;
//         pos = SLTFind(pos,3);
//         if(pos != NULL)
//         {
//             printf("%p\n",pos);
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// void SLTTest4()
// {
//     SLTNode* plist = NULL;
//     SLTPushBack(&plist,1);
//     SLTPushBack(&plist,2);
//     SLTPushBack(&plist,3);
//     SLTPushBack(&plist,4);
//     SLTPushBack(&plist,5);
//     SLTPrint(plist);
//     SLTNode* pos = SLTFind(plist,4);
//     SLTInsert(&plist,pos,40);
//     SLTPrint(plist);
//     pos = SLTFind(plist,1);
//     SLTInsert(&plist,pos,10);
//     pos = SLTFind(plist,4);
//     SLTPrint(plist);
//     SLTErase(&plist,pos);
//      SLTPrint(plist);
//     // SLTPopBack(&plist);
//     // SLTPrint(plist);
//     //SLTDestory(&plist);
// }

// int main()
// {
//     //SLTTest1();
//     //SLTTest2();
//     //SLTTest3();
//     SLTTest4();
//     return 0;
// }