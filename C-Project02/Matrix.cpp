
#include "stdafx.h"
#include<iostream>
using namespace std;

#include"Matrix.h"

Matrix::Matrix(const int width,const int height)
{
	this->width = width;
	this->height = height;


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
			mat[i][j] = count;
			count++;
		}
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < width; i++)
	{
		delete mat[i];
	}
}

int * Matrix::operator[](const int x) const
{
	return mat[x];
}

int Matrix::getWidth() const
{
	return this->width;
}

int Matrix::getHeight() const
{
	return this->height;
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
