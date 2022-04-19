#include "Linear.h"

int InitList(SqList* L)
{
    //这里就部分回答了为什么用用Person *elem的声明
    //但注意了，elem是没有被初始化的
    (*L).elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    //如果分配空间失败，直接报错,并且退出
    if (!L)
    {
        perror("Init Error: ");
        exit(EXIT_FAILURE);
    }

    L->length = 0;
    printf("Init Sucessful!\n");
    return 0;
}

int DestroyList(SqList* L)
{
    //这里是防止没有用Init直接用Destroy，这会对一块莫名其妙的区域释放内存
    if (!L->elem)
    {
        perror("Destroy Error: ");
        exit(EXIT_FAILURE);
    }
    //free完后一定要置空，防止他变成一个野指针
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    printf("Destroy Sucessful!\n");
    return 0;
}

int ClearList(SqList* L)
{
    L->length = 0;
    return 0;
}


//C里面没有bool类型，这里返回的int应该与bool一致，
//而不是之前那种0是程序正常运行，1是异常
int isEmpty(SqList* L)
{
    //==0,就是真的返回1
    if (L->length == 0)
    {
        printf("is Empty!\n");
        return 1;
    }
    else
    {
        printf("isn't Empty\n");
        return 0;
    }
}

int ListLen(SqList* L)
{
    return L->length;
}

//index从0开始计算，而不是1
void GetElem(SqList* L, int index,ElemType *p)
{
    if (index < 0 || index > L->length+1 || L->length == 0)
    {
        printf("GetElem failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("GetElem successed\n");
    }
    p->age = L->elem[index].age;
    p->weight = L->elem[index].weight;
}


int ListInsert(SqList* L, int index, ElemType* elem)
{
    if ((L->length >= MAXSIZE)|| (index < 0) || (index > L->length+1))
    {
        printf("Insert failed!\n");
        exit(EXIT_FAILURE);
    }
    //插入时，把index后面所有数据往后面移动，但是我们不能从前移动，应该从后移动
    for (int i = L->length - 1; i >= index + 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }
    //后移完毕，插入,len+1
    L->elem[index] = *elem;
    L->length++;
    printf("Insert successed!\n");
    return 0;

}

int ListDelete(SqList* L, int index)
{
    if (L->length ==0 || index < 0 || index > L->length)
    {
        printf("Delete failed!\n");
        exit(EXIT_FAILURE);
    }

    //删除后我们从前往前移动
    for (int i = index + 1; i <= L->length; i++)
    {
        L->elem[i - 1] = L->elem[i];
    }
    L->length--;
    printf("Delete successed!\n");

}



//-------------这些是能写的，用函数指针，参考回调函数的bubble
//int (*cmp)(void* e1, void* e2)这是一个函数指针，
//因为我在设计时我并不知道你要传什么样的数据类型给我，所以我对你传过来的数据类型是要怎么比较一无所知
//比如我这里的Person，他应该怎么比较呢？是比较姓名？还是age？还是什么方法？
//所以你得自己写一个函数，然后传到这里来
//需要注意的是，你写的函数返回和参数列表必须跟我这里一致
//你可以参照我的调试文件的函数形式写你自己的

int LocateElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2))
{
    if (L->length == 0)
    {
        printf("Locate failed!\n");
        exit(EXIT_FAILURE);
    }
    //找位置
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (cmp((*L).elem, e) == 0)
        {
            printf("Location found!\n");
            return i;
        }
    }
    printf("No such elem!\n");
    return -1;
}

ElemType PriorElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2))
{
    if (L->length == 0)
    {
        printf("PriorElem failed\n");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (cmp(e, L->elem) == 0||i!=0)
        {
            return L->elem[i - 1];
        }
    }
    printf("PriorElem Not Found!\n");
}

ElemType NextElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2))
{
    if (L->length == 0)
    {
        printf("PriorElem failed\n");
        exit(EXIT_FAILURE);
    }
    int i;
    for (i = 0; i < L->length; i++)
    {
        if (cmp(e, L->elem) == 0 || i != 0)
        {
            return L->elem[i + 1];
        }
    }
    printf("PriorElem Not Found!\n");
}
