#include "Header.h"

int cmp_age(void* e1, void* e2)
{
	return (int)(((ElemType*)e1)->age - ((ElemType*)e2)->age);
}


int main()
{
	//创建链表
	LinkList L;
	//L.isEmpty();
	//节点数据以及创建节点
	ElemType p1 = { 1,1.1 };
	//ElemType q1 = { 14,11.11 };
	ElemType p2 = { 2,2.2 };
	ElemType p3 = { 3,3.3 };
	ElemType p4 = { 4,4.4 };
	LNode n1(&p1);
	LNode n2(&p2);
	LNode n3(&p3);
	LNode n4(&p4);

	//连接节点
	L.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;

	L.isEmpty();
	L.Print();
	L.ListLen();

	//测试insert
	//ElemType q1 = { 14,11.11 };
	//LNode m1(&q1);
	//L.InsertList(&m1, 2);
	//L.ListLen();
	//L.Print();

	////测试Delete
	//L.DeleteList(2);
	//L.ListLen();
	//L.Print();

	//测试Get
	//LNode m2(&p1);
	//m2 = *L.GetElem(2);
	//m2.show();


	////测试Locate
	//ElemType q1 = { 14,11.11 };
	//LNode m1(&q1);
	//L.LocateElem(&m1, cmp_age);

	return 0;
}
