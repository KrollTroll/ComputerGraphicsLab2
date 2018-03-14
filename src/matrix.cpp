#include "matrix.h"
#include <string>
#include <cmath>

// Parameterized constructor
matrix::matrix(unsigned int rows, unsigned int cols):rows(rows),cols(cols) 
{  
	if (rows < 1 || cols < 1)
	{
		throw matrixException("p-constructor bad arguments");
	}
	
	// more to do...
	else{
		//following the one array method - makes things easier in the long run
		the_matrix = new double[rows*cols];
		//initialize array to 0
		the_matrix = {0};
	}
}

// Copy constructor
matrix::matrix(const matrix& from):rows(from.rows),cols(from.cols)
{
	//create array
	the_matrix = new double[rows*cols];
	//copy over
	*the_matrix = *from.the_matrix;
}

// Destructor
matrix::~matrix()
{
	if(the_matrix != NULL){
		//ha. delete the matrix. ha.
		delete the_matrix;
	}
}

// Assignment operator
matrix& matrix::operator=(const matrix& rhs)
{
	//reset sizes
	this->rows = rhs.rows;
	this->cols = rhs.cols;
	//delete and reinitialize
	delete this->the_matrix;
	this->the_matrix = new double[rows*cols];
	//copy
	//TODO:check the logic on this, may not work
	*this->the_matrix = *rhs.the_matrix;
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	// use p-constructor
	return matrix(size,size);
}


// Binary operations
matrix matrix::operator+(const matrix& rhs) const
{
	// stub
	matrix retVal(rhs);
	return retVal;
}


matrix matrix::operator*(const matrix& rhs) const
{
	// stub
	matrix retVal(rhs);
	return retVal;
}

matrix matrix::operator*(const double scale) const
{
	// stub
	matrix retVal(*this);
	return retVal;
}


// Unary operations
matrix matrix::operator~() const
{
	// stub
	matrix retVal(*this);
	return retVal;
}
	

void matrix::clear()
{
	// stub
	return;
}

double* matrix::operator[](unsigned int row)
{
	// stub
	return NULL;
}

double* matrix::operator[](unsigned int row) const
{
	// stub
	return NULL;
}


std::ostream& matrix::out(std::ostream& os) const
{
	// stub
	return os;	
}



// Global insertion and operator
std::ostream& operator<<(std::ostream& os, const matrix& rhs)
{
	// stub
	os << "todo";
	return os;
}

// Global scalar multiplication
matrix operator*(const double scale, const matrix& rhs)
{
	// stub
	matrix retval(rhs);
	return retval;
}


