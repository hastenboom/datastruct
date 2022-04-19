#pragma once
#include<iostream>
using namespace std;

#define MAXSIZE 100


typedef struct
{
	int age;
	float weight;
}Person;

template<class T>
class SqList
{
private: 
	T* elem;
	int length;

public:
	//这个只是为了测试Person这个数据类型用的，具体类型使用时，这里是要修改的。
	friend ostream& operator<<(ostream& os, SqList& L)
	{
		for (int i = 0; i < L.length; i++)
		{
			cout << "element:" << i << ", age: " << L.elem[i].age << ", weight: " << L.elem[i].weight<<endl;
		}
		return os;
	}


	SqList()
	{
		elem = new T[MAXSIZE];
		if (!elem)
		{
			perror("Init Error: ");
			exit(EXIT_FAILURE);
		}
		length = 0;
		cout << "Initialization Successed!" << endl;
	}
	~SqList()
	{
		if (!elem)
		{
			perror("Delete Error: ");
			exit(EXIT_FAILURE);
		}
		delete[]elem;
		elem = NULL;
		length = 0;
		cout << "List is deleted!" << endl;
	}

	bool isEmpty()
	{
		//==0,就是真的返回1
		if (length == 0)
		{
			printf("Is Empty!\n");
			return 1;
		}
		else
		{
			printf("Not Empty!\n");
			return 0;
		}
	}

	void GetElem(int index, T& p)
	{
		if (index < 0 || index > length + 1 || length == 0)
		{
			printf("GetElem failed\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			printf("GetElem successed\n");
		}
		p.age = elem[index].age;
		p.weight = elem[index].weight;
		cout << "Elem got!" << endl;
	}

	int ListInsert( int index, T& p)
	{
		if ((length >= MAXSIZE) || (index < 0) || (index > length + 1))
		{
			printf("Insert failed!\n");
			exit(EXIT_FAILURE);
		}
		//插入时，把index后面所有数据往后面移动，但是我们不能从前移动，应该从后移动
		for (int i = length - 1; i >= index + 1; i--)
		{
			elem[i + 1] = elem[i];
		}
		//后移完毕，插入,len+1
		elem[index] = p;
		length++;
		printf("Insert successed!\n");
		return 0;

	}


	int ListDelete(int index)
	{
		if (length == 0 || index < 0 || index > length)
		{
			printf("Delete failed!\n");
			exit(EXIT_FAILURE);
		}

		//删除后我们从前往前移动
		for (int i = index + 1; i <= length; i++)
		{
			elem[i - 1] = elem[i];
		}
		length--;
		printf("Delete successed!\n");

	}

	int LocateElem(T* e, int (*cmp)(void* e1, void* e2))
	{
		if (length == 0)
		{
			printf("Locate failed!\n");
			exit(EXIT_FAILURE);
		}
		//找位置
		int i;
		for (i = 0; i < length; i++)
		{
			if (cmp(&(elem[i]), e) == 0)
			{
				cout << "Location found: " << i << endl;
				return i;
			}
		}
		printf("No such elem!\n");
		return -1;
	}




};
