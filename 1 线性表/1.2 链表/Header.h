#pragma once
#include<iostream>
using namespace std;


typedef struct
{
	int age;
	float grade;
}ElemType;

class LNode
{
private:
	ElemType* elem;
	
public:
	LNode* next;
	LNode(ElemType*e,LNode* left=NULL)
	{
		elem = e;
		next = left;
	}
	void show()
	{
		cout << "age is: " << elem->age << " ,grade is: " << elem->grade << endl;
	}

};

class LinkList
{

public:
	LNode* next;

	LinkList()
	{
		next = NULL;
		cout << "Link List Inited!" << endl;
	}

	~LinkList()
	{

	}

	bool isEmpty()
	{
		if (next == NULL)
		{
			cout << "is Empty!" << endl;
			return 0;
		}
		else
		{
			cout << "Not Empty!" << endl;
			return 1;
		}
	}

	int ListLen()
	{
		auto p = next;
		int i = 0;
		while (p != NULL)
		{
			p = p->next;
			i++;
		}
		cout << "length is: " << i << endl;
		return i;
	}

	void Print()
	{
		auto p = next;
		while (p != NULL)
		{
			p->show();
			p = p->next;
		}
	}


	void InsertList(LNode* n, int loc)
	{
		auto p = next;
		auto q = next;
		int i = 1, j = 1;
		while (i != (loc))
		{
			p = p->next;
			i++;
		}
		n->next = p;

		//因为我在上面改了节点，现在他会直接到新的节点处，而新节点是NULL
		while (j != (loc -1))
		{
			q = q->next;
			j++;
		}
		q->next = n;

	}

	void DeleteList(int loc)
	{
		auto p = next;
		auto q = next;
		int i = 1, j = 1;
		while (i != (loc+1))
		{
			p = p->next;
			i++;
		}

		while (j != (loc - 1))
		{
			q = q->next;
			j++;
		}

		q->next = p;
	}

	LNode* GetElem(int loc)
	{
		auto p = next;
		int i = 1;
		while (i<(loc))
		{
			p = p->next;
			i++;
		}
		return p;
	}
	

	int LocateElem(LNode* n, int (*cmp)(void* e1, void* e2))
	{
		auto p = next;
		int i = 1;
		for (p; p != NULL; p = p->next)
		{
			if (cmp(p, n) == 0)
			{
				cout << "Location Found:  " << i << endl;
				return i;
			}
			i++;
		}
		printf("No such elem!\n");
		return -1;
	}

};
