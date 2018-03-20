#include "matrix.h"
#include <iostream>
 
using namespace std;

int main(void)
{
	// test our matrix
	
	matrix m1(3,3);
	//test basic initialization
	cout << "m1 - should be all zeros" << endl;
	cout << m1 << endl;
	
	matrix m2 = matrix::identity(3);
	//test identity initializer
	cout << "m2 - should be 3 x 3 identity matrix" << endl;
	cout << m2 << endl;

	matrix m3 = m1 + m2;
	//test addition and assignment operators
	cout << "m3 - should be 3 x 3 identity matrix" << endl;
	cout << m3 << endl;
	
	//error checking for matrix that is too small
	try
	{
		matrix m4(0,0);	// should throw
		cout << "m4 - exception not thrown (but should have)" << endl;
	}
	catch (matrixException me)
	{
		cout << "m4 - exception expected and thrown\n" << endl;
	}
	
	//initalize two matrices to be tested in multiplication
	matrix m4(3,2);
	matrix m5(2,3);

	//assign random values for each matrix
	int pos = 1;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 2; j++){
			m4[i][j] = pos;
			pos++;
		}
	}
	for(int k = 0; k < 2; k++){
		for(int l = 0; l < 3; l++){
			m5[k][l] = pos;
			pos++;
		}
	}

	//print out both matrices
	cout << "m4 - should be 3 x 2 matrix" << endl;
	cout << m4 << endl;

	cout << "m5 - should be 2 x 3 matrix" << endl;
	cout << m5 << endl;

	//try multiplication between incompatible matrices
	try{
		matrix m6 = m4*m2;
		cout << "m6 - exception not thrown (but should have)" << endl;
	}
	catch (matrixException me){
		cout << "m6 - exception expected and thrown\n" << endl;
	}

	//test scalar multiplication
	matrix m6 = m4*2;
	cout << "m6 - should be 2*m4" << endl;
	cout << m6 << endl;

	//more scalar testing
	matrix m7 = m5*2;
	cout << "m7 - should be 2*m5" << endl;
	cout << m7 << endl;

	//test transposition
	matrix m8 = ~m4;
	cout << "m8 - should be the transpose of m4" << endl;
	cout << m8 << endl;

	//test double transposition
	m8 = ~(~m4);
	cout << "m8 - should now be m4 (double transposition)" << endl;
	cout << m8 << endl;

	//test one way of multiplication
	matrix m9 = m4*m5;
	cout << "m9 - should be m4*m5" << endl;
	cout << m9 << endl;

	//test other way of multiplication
	matrix m10 = m5*m4;
	cout << "m10 - should be m5*m4" << endl;
	cout << m10 << endl;

	//test clear
	m10.clear();
	cout << "m10 - should now be empty" << endl;
	cout << m10 << endl;

	return 0;
}		
