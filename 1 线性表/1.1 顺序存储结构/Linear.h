#ifndef Linear_H_
#define Linear_H_
#include <stdio.h>
#include <stdlib.h>


#define MAXSIZE 100
#define ElemType Person

typedef struct
{
    int age;
    float weight;
} Person;

typedef struct
{
    ElemType* elem;
    int length;
} SqList;


int InitList(SqList* L);
int DestroyList(SqList* L);
int ClearList(SqList* L);
int isEmpty(SqList* L);
int ListLen(SqList* L);
void GetElem(SqList* L, int index, ElemType* p);
int ListInsert(SqList* L, int index, ElemType* elem);
int ListDelete(SqList* L, int index);
int LocateElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2));
ElemType PriorElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2));
ElemType NextElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2));
#endif