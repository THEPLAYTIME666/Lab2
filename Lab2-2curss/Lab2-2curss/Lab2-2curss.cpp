// Lab2-2curss.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

class Vector 
{
public:
	int *pa;
	Vector () // �����������
	{
		pa = new int;
		*pa = 10;
	}
	~Vector() // ����������
	{
		delete pa;
	}

	int & operator[](int index) // �� ����� ����� ��� �� ���� ������ � �������, �� ���������� ������� � ����� ���������.
	{
		return arr[index];
	}


	int *arr = new int[25];

	void transformArray(int array[][5]) // �� ���������� � ����������
	{

		int n = 0;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				arr[j + n] = array[i][j];
			}
			n += 5;
		}
	}


	void out() //������. �����
	{
		for (int i = 0; i < 25; i++)
		{
			cout.width(8);
			cout << arr[i];

		}
	}
	
	int g = 0;

	// ���������� ����������:

	Vector & operator ++() // ���������� ����. ����� ����������.
	{
		this->g++;

		return *this;
	}
	Vector & operator ++(int value) // ���������� ��������. ����� ����������.
	{
		Vector temp(*this);

		this->g++;

		return temp;
	}

	// ���������� ����������:

	Vector & operator --() // ���������� ����. ����� ����������.
	{
		this->g--;

		return *this;
	}
	Vector & operator --(int value) // ���������� ��������. ����� ����������.
	{
		Vector temp(*this);

		this->g--;

		return temp;
	}

};

class Matrix
{
public:
	int array[5][5]; //�������� ������� � ������


	long double fact(int N)
	{
		if (N < 0) // ���� ������������ ���� ������������� �����
			return 0; // ���������� ����
		if (N == 0) // ���� ������������ ���� ����,
			return 1; // ���������� ��������� �� ���� - �� �����������, �� ��� 1 =)
		else // �� ���� ��������� �������
			return N * fact(N - 1); // ������ ��������.
	}

	void initArray() // ���������� �������
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				array[i][j] = fact(i + j);
			}
		}
	}

	int at(int i, int j) // �������� �������� �� �������� i � j
	{
		return array[i][j];
	}

	void setAt(int i, int j, int g) // ������������� �������� g �� �������� i � j
	{
		array[i][j] = g;

	}
};



int _tmain(int argc, _TCHAR* argv[])
{

	Matrix name;
	name.initArray();
	Vector noname;
	noname.transformArray(name.array);
	noname.out();

	cout << endl;
	cout << name.at(2, 3) << endl;
	cout << endl;

	system("pause");
	return 0;
}

