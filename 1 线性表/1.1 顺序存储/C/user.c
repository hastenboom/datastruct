#include "Linear.h"

int cmp_age(void* e1, void* e2)
{
	return (int)(((Person*)e1)->age - ((Person*)e2)->age);
}



int main()
{
	SqList L;
	InitList(&L);
	isEmpty(&L);
	Person p1 = {19,50.0};
	Person p2 = {10,51.5};
	Person p3 = { 20,52.2 };
	//insert test
	ListInsert(&L, 0, &p1);
	ListInsert(&L, 1, &p2);
	ListInsert(&L, 2, &p3);


	//Delete test
	/*printf("age is %d, weight is %f\n", L.elem[1].age, L.elem[1].weight);
	ListDelete(&L, 1);
	printf("age is %d, weight is %f\n", L.elem[1].age, L.elem[1].weight);
	isEmpty(&L);*/
	
	//GetElem test
	//Person q1;
	//GetElem(&L, 0, &q1);
	//printf("age is %d, weight is %f\n", q1.age,q1.weight);


	//LocateElem test
	Person q2 = { 19,51.1 };
	Person q3 = { 1000,1.1 };
	int i = LocateElem(&L, &q2, cmp_age);
	printf("%d\n", i);
	i = LocateElem(&L, &q3, cmp_age);
	printf("%d\n", i);
	//DestroyList(&L);

	return 0;
}