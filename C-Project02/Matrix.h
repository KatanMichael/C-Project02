

#include <ostream>
using namespace std;

class Matrix
{

private:
	int** mat;
	int width;
	int height;


public:

	Matrix(int width, int height); //Constructor
	Matrix(const Matrix& m); //Copy Constructor
	Matrix(); // Empty Constructor
	~Matrix(); // Destructor

	//Operators Overloading
	int* operator[](const int x) const;
	void operator=(const Matrix& copy) const;
	Matrix& operator+(const Matrix&)const ;
	Matrix& operator-(const Matrix&)const ;

	//I/O
	friend ostream& operator <<(ostream& out, const Matrix&);
	


	//Setter And Getters
	int getWidth() const;
	int getHeight() const;



};
