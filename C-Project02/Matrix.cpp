
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

Matrix & Matrix::operator=(const Matrix & copy) const
{
	Matrix ret(copy.getWidth(), copy.getHeight());

	for (int i = 0; i < copy.getWidth(); i++)
	{
		for (int j = 0; j < copy.getHeight(); j++)
		{
			ret[i][j] = copy[i][j];
		}
	}

	return ret;

}

Matrix& Matrix::operator+(const Matrix& m)
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
