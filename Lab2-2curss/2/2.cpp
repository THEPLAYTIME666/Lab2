// 2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h> // ����� ��� ����������� getch
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class Fraction
{
public:

	int numerator; // ���������
	int denominator; // �����������

	void reduction() // ���������� �����
	{
		for (int i = 10; i > 1; i--)
		{
			if (numerator % i == 0)
			{
				if (denominator % i == 0)
				{
					numerator /= i;
					denominator /= i;

					reduction(); // ���������� �������� �-� �� ������� ����������

					break;
				}
				else{ continue; }		
			}
			else{ continue; }
		}

	}

	Fraction operator + (Fraction &two) // ���������� +
	{
		Fraction returned = Fraction();

		int g; // ����� �����������
		g = denominator * two.denominator;

		int tempOne;
		int tempTwo;

		tempOne = g / denominator; // ��� ������������ ��������
		tempTwo = g / two.denominator;

		tempOne = numerator * tempOne; // ������� ���������
		tempTwo = two.numerator * tempTwo;

		returned.numerator = tempOne + tempTwo; // �������� � ������ �������� ���������
		returned.denominator = g; // �������� � ������ �������� �����������

		return returned;
	}
	Fraction operator - (Fraction &two) // ���������� -
	{
		Fraction returned = Fraction();

		int g; // ����� �����������
		g = denominator * two.denominator;

		int tempOne;
		int tempTwo;

		tempOne = g / denominator; // ��� ������������ ��������
		tempTwo = g / two.denominator;

		tempOne = numerator * tempOne; // ������� ���������
		tempTwo = two.numerator * tempTwo;

		returned.numerator = tempOne - tempTwo; // �������� � ������ �������� ���������
		returned.denominator = g; // �������� � ������ �������� �����������

		return returned;
	}
	Fraction operator * (Fraction &two) // ���������� *
	{
		Fraction returned = Fraction();

		returned.numerator = numerator * two.numerator; // �������� � ������ �������� ���������
		returned.denominator = denominator * two.denominator; // �������� � ������ �������� �����������

		return returned;
	}
	Fraction operator / (Fraction &two) // ���������� /
	{
		Fraction returned = Fraction();

		returned.numerator = numerator * two.denominator; // �������� � ������ �������� ���������
		returned.denominator = denominator * two.numerator; // �������� � ������ �������� �����������

		return returned;
	}

	static int gcd(int n, int m) // ���
	{
		if (n % m == 0)
			return m;
		if (m % n == 0)
			return n;
		if (n > m)
			return gcd(n%m, m);
		return gcd(n, m%n);
	}
	static void printAsFraction(double decimal_fraction) // ������� �� ������������ � ���������� �����
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

		cout << "���������� �����: " << helper.numerator << " % " << helper.denominator << endl;

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

		cout << "GG���������� �����: " << helperOne.numerator << " % " << helperOne.denominator << endl;

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


	cout << "������ � �������� �������:" << endl;
	cout << "" << endl;

	cout << "������� ���������..." << endl;
	cin >> x;
	cout << "������� �����������..." << endl;
	cin >> y;

	Fraction first;
	first.numerator = x;
	first.denominator = y;



	Fraction secend;
	secend.numerator = 81;
	secend.denominator = 81;
	secend.reduction();


	cout <<"���������� �����: "<< first.numerator << "%" << first.denominator << endl;
	cout << "" << endl;
	cout << "=================================================================" << endl;
	cout << "" << endl;

	cout <<"��� ���� ����� (378 � 441): "<< Fraction::gcd(378, 441) << endl;
	cout << "" << endl;
	cout << "=================================================================" << endl;
	cout << "" << endl;

	Fraction::printAsFraction(0.25);


	string enter;
	cout << "������� ������������ �����" << endl;
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

