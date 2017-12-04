
#include "stdafx.h"
#include<iostream>
using namespace std;

#include"Matrix.h"

Matrix::Matrix(const int width,const int height)
{
	if (width <= 0)
	{
		cout << "width cannot be negativ or zero" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		this->width = width;
	}

	if (height <= 0)
	{
		cout << "height cannot be negativ or zero" << endl;
		system("pause");
		exit(1);
	}
	else
	{
		this->height = height;
	}


	int count = 0;
	(mat) = new int*[width];

	for (int i = 0; i < height; i++)
	{
		mat[i] = new int[height];
	}
	
		
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			mat[i][j] = 0;
			
		}
	}
}

Matrix::Matrix()
{
	mat = nullptr;
	width = 0;
	height = 0;
}

Matrix::~Matrix()
{
	for (int i = 0; i < width; i++)
	{
		delete mat[i];
	}
}


int Matrix::getWidth() const
{
	return this->width;
}

int Matrix::getHeight() const
{
	return this->height;
}

int * Matrix::operator[](const int x) const
{
	return mat[x];
}

Matrix& Matrix::operator+(const Matrix& m) const
{

	if (this->getHeight() != m.getHeight())
	{
		cout << "Height Dont Match" << endl;
		system("pause");
		exit(1);
	}

	if (this->getWidth() != m.getWidth())
	{
		cout << "Width Dont Match" << endl;
		system("pause");
		exit(1);
	}

	Matrix temp(m.getHeight(), m.getWidth());
	
		for(int i = 0; i < m.getHeight(); i ++)
		{
			for (int j = 0; j < m.getWidth(); j++)
			{
				temp[i][j] = (this->mat[i][j] + m[i][j]);
			}
		}
	
		return temp;
}

Matrix & Matrix::operator-(const Matrix &m) const
{
	Matrix temp;
	temp.mat = new int*[m.getWidth()];

	for (int i = 0; i < m.getHeight(); i++)
	{
		temp.mat[i] = new int[m.getHeight()];
	}

	temp.height = m.getHeight();
	temp.width = m.getWidth();

	for (int i = 0; i < m.getWidth(); i++)
	{
		for (int j = 0; j < m.getHeight(); j++)
		{
			temp[i][j] = m[i][j] * -1;
		}
	}

	return temp;
}


ostream & operator<<(ostream & out, const Matrix &m)
{
	for (int i = 0; i < m.height; i++)
	{
		for (int j = 0; j < m.width; j++)
		{
			out << m.mat[i][j] << " ";
		}
		out << endl;
	}

	return out;
}



void Matrixh::operator=(const Matrixh&  put)
{
	if (this->lenght == put.lenght)

	{
		if (width != put.width)
		{

			this->width = put.width;            //כדכן רק את הרוחב ותקצה מחדש כל שורה כי מספר השורות שווה ורק הרוחב שונה 

			for (int i = 0; i<lenght; i++)
			{
				delete matrix[i];
				matrix[i] = new int[width];
				if (matrix[i] == NULL)
				{
					cout << "the allocation failed ,the program will close" << endl;
					system("pause");
					exit(1);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i<lenght; i++)      //שחרר כל מה שהיה 
		{
			delete matrix[i];
		}
		delete matrix;

		this->lenght = put.lenght;    //תעדכן אורך ורוחב 
		this->width = put.width;

		matrix = new int*[lenght];  //תקצה מחדש את המקום למטריצה 
		if (matrix == NULL)
		{
			cout << "the allocation failed ,the program will close" << endl;
			system("pause");
			exit(1);
		}
		else
		{
			for (int i = 0; i<lenght; i++)
			{
				matrix[i] = new int[width];
				if (matrix[i] == NULL)
				{
					cout << "the allocation failed ,the program will close" << endl;
					system("pause");
					exit(1);
				}
			}
		}
	}




	for (int i = 0; i<lenght; i++)         //השמת כל המטריצה בכל מקרה  
	{
		for (int j = 0; j<width; j++)
		{
			matrix[i][j] = put[i][j];
		}
	}
}