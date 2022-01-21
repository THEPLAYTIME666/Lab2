// testProj.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <conio.h> // нужно для подключения getch
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(0, ""); // Включаем кириллицу

	//string enter = "0.325";
	//int size = enter.length();
	char a_str[] = "hellouyt";
	//char *arr = new char[size];
	char *arr_ptr = &a_str[0];

	/*for (int i = 0; i < size; i++)
	{
		arr[i] = enter[i];
	}*/

	cout << "=========" << strlen(arr_ptr) << endl;
	
	system("pause");
	return 0;
}

