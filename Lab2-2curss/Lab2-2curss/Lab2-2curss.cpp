// Lab2-2curss.cpp: определяет точку входа для консольного приложения.
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
	Vector () // конструктор
	{
		pa = new int;
		*pa = 10;
	}
	~Vector() // деструктор
	{
		delete pa;
	}

	int & operator[](int index) // не очень понял что от меня хотели в задании, но перегрузку написал и можно применять.
	{
		return arr[index];
	}


	int *arr = new int[25];

	void transformArray(int array[][5]) // из двумерного в одномерный
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


	void out() //формат. вывод
	{
		for (int i = 0; i < 25; i++)
		{
			cout.width(8);
			cout << arr[i];

		}
	}
	
	int g = 0;

	// Перегрузка инкремента:

	Vector & operator ++() // перегрузка преф. формы инкремента.
	{
		this->g++;

		return *this;
	}
	Vector & operator ++(int value) // перегрузка постфикс. формы инкремента.
	{
		Vector temp(*this);

		this->g++;

		return temp;
	}

	// Перегрузка дикремента:

	Vector & operator --() // перегрузка преф. формы дикремента.
	{
		this->g--;

		return *this;
	}
	Vector & operator --(int value) // перегрузка постфикс. формы дикремента.
	{
		Vector temp(*this);

		this->g--;

		return temp;
	}

};

class Matrix
{
public:
	int array[5][5]; //создание массива с нулями


	long double fact(int N)
	{
		if (N < 0) // если пользователь ввел отрицательное число
			return 0; // возвращаем ноль
		if (N == 0) // если пользователь ввел ноль,
			return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
		else // Во всех остальных случаях
			return N * fact(N - 1); // делаем рекурсию.
	}

	void initArray() // заполнение массива
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				array[i][j] = fact(i + j);
			}
		}
	}

	int at(int i, int j) // получить значение по индексам i и j
	{
		return array[i][j];
	}

	void setAt(int i, int j, int g) // устанавливает значение g по индексам i и j
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

