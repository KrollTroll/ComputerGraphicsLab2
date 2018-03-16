#include "matrix.h"
#include <string>
#include <cmath>

/**
 * This is the "standard" prioritized constructor
 * @param rows : number of rows in a matrix
 * @param cols : number of columns in a matrix
 */
matrix::matrix(unsigned int rows, unsigned int cols):rows(rows),cols(cols) 
{  
	if (rows < 1 || cols < 1)
	{
		throw matrixException("p-constructor bad arguments");
	}
	else{
		//following the one array method - makes things easier in the long run
		the_matrix = new double[rows*cols];
		//initialize array to 0
		the_matrix = {0};
	}
}

/**
 * copy constructor
 * @param from : matrix to copy the new one from
 */
matrix::matrix(const matrix& from):rows(from.rows),cols(from.cols)
{
	//create array
	the_matrix = new double[rows*cols];
	//copy over
	*the_matrix = *from.the_matrix;
}

/**
 * destructor
 */
matrix::~matrix()
{
	if(the_matrix != NULL){
		//ha. delete the matrix. ha.
		delete the_matrix;
	}
}

/**
 * assignment operator -- makes one matrix a copy of another
 * @param rhs : the right hand side matrix to copy
 * @return    : the new array copied over
 */
matrix& matrix::operator=(const matrix& rhs)
{
	//delete
	delete the_matrix;
	//reset sizes
	rows = rhs.rows;
	cols = rhs.cols;
	the_matrix = new double[rows*cols];
	//copy
	//TODO:check the logic on this, may not work
	the_matrix = rhs.the_matrix;
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	if(size < 1){
		throw matrixException("identity constructor bad argument");
	}
	else{
		matrix ident = matrix(size, size);

		//logic pattern built
		int pos = 0;
		int the_rows = ident.rows;
		int the_cols = ident.cols;
		for(int i = 0; i < the_rows; i++){
			for(int j = 0; j < the_cols; j++){
				if(i==j){
					ident.the_matrix[pos] = 1;
				}
				pos++;
			}
		}

		return ident;
	}
}


/**
 * binary operator -- adds two marices together
 * @param rhs : right hand side matrix to add to the left
 * @return    : the new combined matrix
 */
matrix matrix::operator+(const matrix& rhs) const
{
	//throw exception if matrices are no the same size
	if(cols != rhs.cols || rows!= rhs.rows){
		throw matrixException("addition matrix sizes different!");
	}
	//do linear add operation if they are -- this is the way that they are stored
	else{
		matrix retVal(rhs);
		int size = rhs.cols * rhs.rows;
		for(int i = 0; i < size; i++){
			retVal.the_matrix[i] = retVal.the_matrix[i] + the_matrix[i];
		}

		return retVal;
	}
}

/**
 * multiplication operator -- matrix by matrix, multiplies two matrices together
 * 		throws exception if the two matrices are not compatible
 * @param rhs : right hand matrix to multiply left by
 * @return    : the new product matrix
 */
matrix matrix::operator*(const matrix& rhs) const
{
	if(cols != rhs.rows){
		throw matrixException("left matrix and right matrix not compatible!");
	}
	else{
		//TODO: figure out an efficient algorithm
		matrix retVal(rhs);
		return retVal;
	}
}

/**
 * multiplication operator -- matrix by scalar, multiplies a matrix by a scalar
 * @param scale : scalar to multiply matrix by
 * @return		: the new product matrix
 */
matrix matrix::operator*(const double scale) const
{
	matrix retVal(*this);
	int pos = rows*cols;
	for(int i = 0; i < pos; i++){
		retVal.the_matrix[i] *= scale;
	}
	return retVal;
}


/**
 * unary operator -- transposes a given matrix
 * @return : the new transposed matrix
 */
matrix matrix::operator~() const
{
	//TODO: this is going to take a bit, rows become columns and vv
	// stub
	matrix retVal(*this);
	return retVal;
}
	
/**
 * clears a matrix and assigns all values to 0
 */
void matrix::clear()
{
	the_matrix = {0};
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



/**
 * This is basically the print operator, just make it look pretty and you should be gucci
 * @param os
 * @param rhs
 * @return
 */std::ostream& operator<<(std::ostream& os, const matrix& rhs)
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


