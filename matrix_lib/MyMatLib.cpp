// MyMatLb.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <string>
#include <iostream>
using namespace std;


// matlib.cpp : A simple matrix library program.
// Written by Prof Richard Mitchell    7/1/22
//

struct myMat {			// allows for matrices up to size 4*4
	int numRows;		// number of rows
	int numCols;
	int data[16];		// data are stored in row order
};

myMat zeroMat(int r, int c) {
	// create a matrix with r rows and c columns, filled with zeros
	myMat m;			// define matrix
	m.numRows = r;		// set size
	m.numCols = c;
	for (int ct = 0; ct < 16; ct++) m.data[ct] = 0;	// set elems to 0
	return m;			// return matrix
}

int getElem(myMat m, int r, int c) {
	// return the item at m[r,c]   where r is 0..m.numRows-1 etc
	return m.data[r * m.numCols + c];
}

void setElem(myMat& m, int r, int c, int val) {
	// set element m[r,c] to val
	m.data[r * m.numCols + c] = val;
}

myMat mFromStr(string s) {
	// create a matrix from string s
	// string of form "1,2;3,4;5,6"   ; separates rows and , separates columns ... No error check
	int ms;
	if (s.length() > 0) ms = 1; else ms = 0;
	myMat m = zeroMat(ms, ms);						// is s empty create 0*0 matrix, else start with 1*1 matrix
	int mndx = 0;									// used to index into array
	string sub = "";								// sub string - numbers between , or ; set empty
	for (int ct = 0; ct < s.length(); ct++) {		// each char in turn
		if ((s[ct] == ',') || (s[ct] == ';')) {	// if , or ; then sub contains number
			m.data[mndx++] = stoi(sub);				// convert number to integer, put in data array
			sub = "";								// clear sub string
			if (s[ct] == ';') m.numRows++;			// if found ; indicates an extra row
			else if (m.numRows == 1) m.numCols++;	// if , then (if in row 1) increase count of columns
		}
		else sub = sub + s[ct];						// add character to sub string
	}
	if (sub.length() > 0) m.data[mndx++] = stoi(sub);// add last sub string
	return m;
}

myMat mGetRow(myMat m, int row) {
	// create a matrix from m, having one row
	myMat res = zeroMat(1, m.numCols);				// create a matrix of 1 row
	for (int col = 0; col < m.numCols; col++)		// for each element in row
		res.data[col] = getElem(m, row, col);		// copy col element to res
	return res;
}
myMat mGetCol(myMat m, int col) {
	myMat res = zeroMat(m.numRows, 1); 				// create new matrix with 1 column
	for (int row = 0; row < m.numRows; row++)		// for each element in column
		res.data[row] = getElem(m, row, col);		// copy row element to res
	return res;
}


int dotProd(myMat v1, myMat v2) {
	int prod = 0;									// initiate prod varable
	for (int i = 0; i < v1.numCols; i++){			// for each column in vector add prod plus the multuple of both the vectors
		prod = prod + getElem(v1,0,i) * getElem(v2,0,i);
	}
	return prod;
}

myMat mTranspose(myMat m) {
	myMat mO = zeroMat(m.numCols, m.numRows);		// create a matrix mO with the same number of rows and columns as the input matrix.
	for(int i=0; i< m.numRows; ++i) {				// for each item in rom and for each column in row flip the values that reffer to  i and j.
		for(int j=0; j< m.numCols; ++j){
			int val = getElem(m, i, j);
			setElem(mO, j, i, val);
		}
	}
	return mO;
}

myMat mAdd(myMat m1, myMat m2) {
	myMat m3 = zeroMat(m1.numRows, m2.numCols); 	// create a matrix with the same number of rows as the matrix1 and the same number of columns as the matrix2.
	for(int i = 0; i < m1.numRows; i++) {			//loop until all numbers in matrix1 and matrix1 are added to matrix3 and returned the matrix.
            for(int j = 0; j < m2.numCols; j++) {
				int val = getElem(m1, i, j) + getElem(m2, i, j);
                setElem(m3, i, j, val);
            }
        }
		return m3;
}

void printMat(const char* mess, myMat m) {
	// mess is string to be printed, followed by matrix m
	cout << mess << " = " << "\n";				// print message
	for (int r = 0; r < m.numRows; r++) {		// do each row
		for (int c = 0; c < m.numCols; c++)		// do each column
			cout << getElem(m, r, c) << "\t";	// outputing the element then tab
		cout << "\n";							// output new line at end of row
	}
	cout << "\n";								// and end of Matrix
}

myMat mMult(myMat m1, myMat m2) {
	myMat m3;									// initiate matrix m3
	if (m1.numRows == 1 && m1.numCols == 1)		// if single row, column matrix inputted use the number of rows and columns as the other matrix.
	{
		m3 = zeroMat(m2.numRows, m2.numCols);
	}else if (m2.numRows == 1 && m2.numCols == 1) {
		m3 = zeroMat(m1.numRows, m1.numCols);

	}else {										// else set the number of rows the same size as the first matrix and column as the second matrix.
		m3 = zeroMat(m1.numRows, m2.numCols);
	}

	int val;									// varable ot store values when loopes
	
	for(int i = 0; i < m1.numRows; ++i) { 		// loop trough A and B, multiply and and to result, then return.
		for(int j = 0; j < m2.numCols; ++j) {
			for(int k = 0; k < m2.numRows; ++k) {
				int val = getElem(m3, i, j) + getElem(m1, i, k) * getElem(m2, k, j);
				setElem(m3, i, j, val);			// save the value of val to m3 and output when done
			}
		}
	}
	return m3;
}

int main()
{
	cout << "Richard's Matrix Example Program\n";

	cout << "Question 1. Matrix Calculation\n"; // Question 1 ----------------------------
	
	myMat Q1A = mFromStr("1,9,7;9,5,9"); 		// Matrix A
	printMat("A", Q1A);

	myMat Q1B = mFromStr("9,5,10;1,9,8"); 		// Matrix B
	printMat("B", Q1B);

	myMat Q1C = mFromStr("8,7;10,10;1,9"); 		// Matrix C
	printMat("C", Q1C);

	cout << "Calculate 1A + 10B\n";

	myMat Q1_1_mat = mFromStr("1");				// create 1x1 matrix of 1 (ik its unecessary but its used to check if it works)
	myMat Q1_10_mat = mFromStr("10");			// create 1x1 matrix of 10
	myMat Q1_1A = mMult(Q1_1_mat, Q1A);			// Multiply 1 by Matrix A
	printMat("1A", Q1_1A);
	myMat Q1_10B = mMult(Q1_10_mat ,Q1B);		// Multiply 10 by Matrix B
	printMat("10B", Q1_10B);

	myMat Q1Ans1 = mAdd(Q1_1A, Q1_10B);			// Multiply 1A with Matrix 10B
	printMat("1A + 10B", Q1Ans1);				// print out the matrix


	cout << "Calculate 9A + 5C`\n";
	
	myMat Q1_9_mat = mFromStr("9");				// create 1x1 matrix of 9
	myMat Q1_5_mat = mFromStr("5");				// create 1x1 matrix of 5
	myMat Q1_9A = mMult(Q1_9_mat, Q1A);			// Multiply 9 by Matrix A
	myMat Q1_5C = mMult(Q1_5_mat, Q1C);			// Multiply 5 by Matrix C
	myMat Q1_5Ct = mTranspose(Q1_5C);			// get the transpose of the matrix 5C
	myMat Q1Ans2 = mAdd(Q1_9A, Q1_5Ct);			// Multiply 9A with Matrix 5C'
	printMat("9A + 5C`", Q1Ans2);				// print out the matrix
	
	cout << "Calculate C x B\n";

	myMat Q1Ans3 = mMult(Q1C, Q1B);				// Multiply Matrix C with Matrix B
	printMat("C x B", Q1Ans3);
	return 0;
}