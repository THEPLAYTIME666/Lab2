// 2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h> // нужно для подключения getch
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Fraction
{
public:

	int numerator; // числитель
	int denominator; // знаменатель

	void reduction() // сокращение дроби
	{
		for (int i = 10; i > 1; i--)
		{
			if (numerator % i == 0)
			{
				if (denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;

					reduction(); // рекурсивно вызываем ф-ю до полного сокращения

					break;
				}
				else{ continue; }		
			}
			else{ continue; }
		}

	}

	Fraction operator + (Fraction &two) // перегрузка +
	{
		Fraction returned = Fraction();

		int g; // общий знаменатель
		g = denominator * two.denominator;

		int tempOne;
		int tempTwo;

		tempOne = g / denominator; // над числительные значения
		tempTwo = g / two.denominator;

		tempOne = numerator * tempOne; // готовые числители
		tempTwo = two.numerator * tempTwo;

		returned.numerator = tempOne + tempTwo; // записали в объект итоговый числитель
		returned.denominator = g; // записали в объект итоговый знаменатель

		return returned;
	}
	Fraction operator - (Fraction &two) // перегрузка -
	{
		Fraction returned = Fraction();

		int g; // общий знаменатель
		g = denominator * two.denominator;

		int tempOne;
		int tempTwo;

		tempOne = g / denominator; // над числительные значения
		tempTwo = g / two.denominator;

		tempOne = numerator * tempOne; // готовые числители
		tempTwo = two.numerator * tempTwo;

		returned.numerator = tempOne - tempTwo; // записали в объект итоговый числитель
		returned.denominator = g; // записали в объект итоговый знаменатель

		return returned;
	}
	Fraction operator * (Fraction &two) // перегрузка *
	{
		Fraction returned = Fraction();

		returned.numerator = numerator * two.numerator; // записали в объект итоговый числитель
		returned.denominator = denominator * two.denominator; // записали в объект итоговый знаменатель

		return returned;
	}
	Fraction operator / (Fraction &two) // перегрузка /
	{
		Fraction returned = Fraction();

		returned.numerator = numerator * two.denominator; // записали в объект итоговый числитель
		returned.denominator = denominator * two.numerator; // записали в объект итоговый знаменатель

		return returned;
	}

	static int gcd(int n, int m) // НОД
	{
		if (n % m == 0)
			return m;
		if (m % n == 0)
			return n;
		if (n > m)
			return gcd(n%m, m);
		return gcd(n, m%n);
	}
	static void printAsFraction(double decimal_fraction) // перевод из неправильной в правильную дробь
	{
		int tata = 10;
		int count = 10;

		while (true)
		{
			decimal_fraction = decimal_fraction * tata;
			if (decimal_fraction - (int)decimal_fraction >= 0.1)
			{
				count = count*10;
				continue;
			}
			else
			{
				break;
			}
		}
		Fraction helper;
		helper.numerator = decimal_fraction;
		helper.denominator = count;
		helper.reduction();

		cout << "Правильная дробь: " << helper.numerator << " % " << helper.denominator << endl;

		cout << "" << endl;
		cout << "=================================================================" << endl;
		cout << "" << endl;
	}
	static void printAsFraction(char* decimal_fraction, int size)
	{
		Fraction helperOne;
		helperOne.denominator = 0;
		//helperOne.numerator = decimal_fraction;

		int coefficient = 1;

		for (int i = 0; i < size; i++)
		{
			if (decimal_fraction[i] == '.')
			{
				for (int j = i+1; j < size; j++)
				{
					helperOne.denominator += atoi(&decimal_fraction[j]) * coefficient;
					cout << "Zashlo" << endl;
					coefficient *= 10;
				}
				break;
			}
			helperOne.numerator = atoi(&decimal_fraction[i]);

		}
		//helperOne.reduction();

		cout << "GGПравильная дробь: " << helperOne.numerator << " % " << helperOne.denominator << endl;

		cout << "" << endl;
		cout << "=================================================================" << endl;
		cout << "" << endl;
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");

	int x;
	int y;


	cout << "Работа с обычными дробями:" << endl;
	cout << "" << endl;

	cout << "Введите числитель..." << endl;
	cin >> x;
	cout << "Введите знаменатель..." << endl;
	cin >> y;

	Fraction first;
	first.numerator = x;
	first.denominator = y;



	Fraction secend;
	secend.numerator = 81;
	secend.denominator = 81;
	secend.reduction();


	cout <<"Полученная дробь: "<< first.numerator << "%" << first.denominator << endl;
	cout << "" << endl;
	cout << "=================================================================" << endl;
	cout << "" << endl;

	cout <<"НОД двух чисел (378 и 441): "<< Fraction::gcd(378, 441) << endl;
	cout << "" << endl;
	cout << "=================================================================" << endl;
	cout << "" << endl;

	Fraction::printAsFraction(0.25);


	string enter;
	cout << "Введите неправильную дробь" << endl;
	cin >> enter;
	int size = enter.length();
	char *arr = new char[size];


	for (int i = 0; i < size; i++)
	{
		arr[i] = enter[i];
	}

	Fraction::printAsFraction(arr, size);

	system("pause");
	return 0;
}

