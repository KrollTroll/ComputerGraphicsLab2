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
		int size = rows*cols;
		//following the one array method - makes things easier in the long run
		the_matrix = new double[size];
		//initialize array to 0
		for(int i = 0; i < size; i++){
			the_matrix[i] = 0;
		}
	}
}

/**
 * copy constructor
 * @param from : matrix to copy the new one from
 */
matrix::matrix(const matrix& from):rows(from.rows),cols(from.cols)
{
	int size = rows*cols;
	//create array
	the_matrix = new double[size];
	//copy over
	for(int i = 0; i < size; i++){
		the_matrix[i] = from.the_matrix[i];
	}
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
	if(this->the_matrix != NULL){
		//delete
		//delete the_matrix;
	}
	//reset size
	rows = rhs.rows;
	cols = rhs.cols;
	int size = rows*cols;
	the_matrix = new double[size];
	//copy
	for(int i = 0; i < size; i++){
		the_matrix[i] = rhs.the_matrix[i];
	}
	return *this;
}

// Named constructor (static)
matrix matrix::identity(unsigned int size)
{
	if(size < 1){
		throw matrixException("identity constructor bad argument");
	}
	else{
		matrix ident(size, size);

		//logic pattern built
		int side = size;
		for(int i = 0; i < side; i++){
				ident[i][i] = 1;
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
			(retVal.the_matrix)[i] = (retVal.the_matrix)[i] + (the_matrix)[i];
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
		int rows_lhs = this->rows;
		int cols_lhs = this->cols;
		int cols_rhs = rhs.cols;
		matrix product(rows_lhs, cols_rhs);
		matrix dupe(rhs);
		~dupe;
		for(int i = 0; i < rows_lhs; i++){
			for(int j = 0; j < cols_rhs; j++){
				for(int k = 0; k < cols_lhs; k++){
					product[i][j] += (*this)[i][k]*rhs[k][j];
				}
			}
		}
		return product;
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
	int row = retVal.rows;
	int col = retVal.cols;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
				retVal[j][i] = (*this)[i][j];
		}
	}
	retVal.cols = this->rows;
	retVal.rows = this->cols;
	return retVal;
}
	
/**
 * clears a matrix and assigns all values to 0
 */
void matrix::clear()
{
	int size = rows*cols;
	for(int i = 0; i < size; i++){
		the_matrix[i] = 0;
	}
	return;
}

/**
 * operator to return the pointer to the first element of specified row
 * @param row : specified row
 * @return
 */
double* matrix::operator[](unsigned int row)
{
	if(row > this->rows){
		throw matrixException("[] argument invalid");
	}
	else{
		double* ptr = &(this->the_matrix[0 + (row)*this->cols]);
		return ptr;
	}
}

/**
 * same as other [] op, but const for other const methods
 * @param row : specified row
 * @return
 */
double* matrix::operator[](unsigned int row) const
{
	if(row > this->rows){
		throw matrixException("[] argument invalid");
	}
	else{
		double* ptr = &(this->the_matrix[0 + (row)*this->cols]);
		return ptr;
	}
}

/**
 * This is the true print operator, it does the work
 */
std::ostream& matrix::out(std::ostream& os) const
{
	int col = this->cols;
	int row = this->rows;
	int pos = 0;

	for(int i = 0; i < col; i++){
		os << "\t[";
		for(int i = 0; i < row; i++){
			os << " " << this->the_matrix[pos] << " ";
			pos++;
		}
		os << "]\n";
	}
	return os;	
}



/**
 * This is basically the print operator, just make it look pretty and you should be gucci
 * @param os
 * @param rhs
 * @return
 */
std::ostream& operator<<(std::ostream& os, const matrix& rhs)
{
	 rhs.out(os);
	 return os;
}

/**
 * global scalar function
 * @param scale
 * @param rhs
 * @return
 */
matrix operator*(const double scale, const matrix& rhs)
{
	// stub
	matrix retval(rhs);
	return (retval*scale);
}


