#include "Linear.h"

int InitList(SqList* L)
{
    //����Ͳ��ֻش���Ϊʲô����Person *elem������
    //��ע���ˣ�elem��û�б���ʼ����
    (*L).elem = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);
    //�������ռ�ʧ�ܣ�ֱ�ӱ���,�����˳�
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
    //�����Ƿ�ֹû����Initֱ����Destroy������һ��Ī������������ͷ��ڴ�
    if (!L->elem)
    {
        perror("Destroy Error: ");
        exit(EXIT_FAILURE);
    }
    //free���һ��Ҫ�ÿգ���ֹ�����һ��Ұָ��
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


//C����û��bool���ͣ����ﷵ�ص�intӦ����boolһ�£�
//������֮ǰ����0�ǳ����������У�1���쳣
int isEmpty(SqList* L)
{
    //==0,������ķ���1
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

//index��0��ʼ���㣬������1
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
    //����ʱ����index�������������������ƶ����������ǲ��ܴ�ǰ�ƶ���Ӧ�ôӺ��ƶ�
    for (int i = L->length - 1; i >= index + 1; i--)
    {
        L->elem[i + 1] = L->elem[i];
    }
    //������ϣ�����,len+1
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

    //ɾ�������Ǵ�ǰ��ǰ�ƶ�
    for (int i = index + 1; i <= L->length; i++)
    {
        L->elem[i - 1] = L->elem[i];
    }
    L->length--;
    printf("Delete successed!\n");

}



//-------------��Щ����д�ģ��ú���ָ�룬�ο��ص�������bubble
//int (*cmp)(void* e1, void* e2)����һ������ָ�룬
//��Ϊ�������ʱ�Ҳ���֪����Ҫ��ʲô�����������͸��ң������Ҷ��㴫����������������Ҫ��ô�Ƚ�һ����֪
//�����������Person����Ӧ����ô�Ƚ��أ��ǱȽ�����������age������ʲô������
//��������Լ�дһ��������Ȼ�󴫵�������
//��Ҫע����ǣ���д�ĺ������غͲ����б�����������һ��
//����Բ����ҵĵ����ļ��ĺ�����ʽд���Լ���

int LocateElem(SqList* L, ElemType* e, int (*cmp)(void* e1, void* e2))
{
    if (L->length == 0)
    {
        printf("Locate failed!\n");
        exit(EXIT_FAILURE);
    }
    //��λ��
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
