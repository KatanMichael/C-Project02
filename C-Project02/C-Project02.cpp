// C-Project02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Matrix.h"

#include<iostream>
using namespace std;

void main()
{
	system("color f0");
	Matrix m(2, 2);
	Matrix s(2,2);
	Matrix sum;
	m[0][0] = 2;
	m[1][1] = 2;
	
	s[1][0] = 2;
	s[0][1] = 2;

	sum = s + m;

	cout << m << endl;
	cout << s << endl;
	cout << sum << endl;

}

