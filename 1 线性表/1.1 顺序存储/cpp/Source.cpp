#include "Header.hpp"


int cmp_age(void* e1, void* e2)
{
	return (int)(((Person*)e1)->age - ((Person*)e2)->age);
}

int main()
{
	Person p1 = { 18,50.1 };
	Person p2 = { 19,56.1 };
	Person p3 = { 1300,53.1 };

	SqList<Person>L;
	L.isEmpty();
	L.ListInsert(0, p1);
	L.ListInsert(1, p2);
	L.ListInsert(2, p3);
	L.isEmpty();
	cout << L;
	L.ListDelete(1);
	cout << L;

	Person q1 = { 18,100.1 };
	Person q2 = { 1211,0.1 };
	L.LocateElem(&q1, cmp_age);
	return 0;
}
