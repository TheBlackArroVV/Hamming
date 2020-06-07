#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;
int main()
{
	/*input1 = 15: 1 0 0 1 0 0 1 0 1 1 1 0 0 0 1*/
	/*input2 = 16: 0 1 0 0 0 1 0 0 0 0 1 1 1 1 0 1*/
	int a, b, c[30], d, r = 0, d1; //Max bits here i kept is 30

	cout << " Enter the No of Data Bits you want to Enter : ";
	cin >> a;

	while (a + r + 1 > pow(2, r))
	{
		r++;
	}
	cout << "No of data bits to be added " << r << " : Total Bits :" << a + r << endl;

	cout << "Enter the Data Bits One by One :" << endl;
	for (int i = 1; i <= a; ++i)
		cin >> c[i];

	cout << endl;
	int * data = new int[a + r];
	d = 0;
	d1 = 1;
	for (int i = 1; i <= a + r; ++i)
	{
		if ((i) == pow(2, d))
		{
			data[i] = 0;
			++d;
		}
		else
		{
			data[i] = c[d1];
			++d1;
		}
	}

	cout << "Data Bits are Encoded with Parity bits(0): ";
	for (int i = 1; i <= a + r; ++i)
		cout << data[i] << " ";

	d1 = 0;
	int min, max = 0, parity, s, j;
	/*Parity Bit Calculation */
	for (int i = 1; i <= a + r; i = pow(2, d1))
	{
		++d1;
		parity = 0;
		j = i;
		s = i;
		min = 1;
		max = i;
		for (j; j <= a + r;)
		{
			for (s = j; max >= min && s <= a + r; ++min, ++s)
			{
				if (data[s] == 1)
					parity++;
			}
			j = s + i;
			min = 1;
		}
		if (parity % 2 == 0) // Even Parity
			data[i] = 0;
		else
			data[i] = 1;
	}

	cout << endl << "Hamming codeword bits for even parity are : ";
	for (int i = 1; i <= a + r; ++i)
		cout << data[i] << " ";
	cout << endl << endl;


	/*Mistake implementation */
	cout << "Enter position of mistake : ";
	int mis;
	cin >> mis;
	data[mis] = abs(data[mis] - 1);
	int * data_mis = new int[a + r];
	for (int i = 1; i <= a + r; ++i)
		data_mis[i] = data[i];
	cout << endl;

	cout << "Codeword bits with mistake : " << endl;
	for (int i = 1; i <= a + r; ++i)
		cout << data_mis[i] << " ";

	cout << endl;
	d1 = 0;
		/*Parity Bit Calculation */
	for (int i = 1; i <= a + r; i = pow(2, d1))
	{
		++d1;
		parity = 0;
		j = i;
		s = i;
		min = 1;
		max = i;
		
		for (j; j <= a + r;)
		{
			for (s = j; max >= min && s <= a + r; ++min, ++s)
			{
				if (data_mis[s] == 1 && s != i)
					parity++;
			}
			j = s + i;
			min = 1;
		}
		cout << parity << endl;
		if (parity % 2 == 0) // Even Parity
			data_mis[i] = 0;
		else
			data_mis[i] = 1;
	}
	cout << endl << "Codeword after parity bit calculation : " << endl;
	for (int i = 1; i <= a + r; ++i)
		cout << data_mis[i] << " ";
	cout << endl;

	cout << "Your mistake position is : " << endl;
	int ans = 0;
	for (int i = 1; i <= a + r; ++i)
		if (data[i] != data_mis[i] )
		{
			cout << i << " ";
			ans += i;
		}
	cout << " = " << ans << endl;
	/*-*/
}
//End
