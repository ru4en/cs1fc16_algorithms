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
	int data[256];		// data are stored in row order //** Had to switch from 4 to something over 200 for some reason.**//
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
	myMat res = zeroMat(1, m.numCols);		// create a matrix of 1 row
	for (int col = 0; col < m.numCols; col++)		// for each element in row
		res.data[col] = getElem(m, row, col);		// copy col element to res
	return res;
}
myMat mGetCol(myMat m, int col) {
	myMat res = zeroMat(m.numRows, 1);
	for (int row = 0; row < m.numRows; row++)
		res.data[row] = getElem(m, row, col);
	return res;
}


int dotProd(myMat v1, myMat v2) {
	int prod = 0;
	for (int i = 0; i < v1.numCols; i++){
		prod = prod + getElem(v1,0,i) * getElem(v2,0,i);
	}
	return prod;
}

myMat mTranspose(myMat m) {
	myMat mO = zeroMat(m.numCols, m.numRows);
	for(int i=0; i< m.numRows; ++i) {
		for(int j=0; j< m.numCols; ++j){
			int val = getElem(m, i, j);
			setElem(mO, j, i, val);
		}
	}
	return mO;
}

myMat mAdd(myMat m1, myMat m2) {

	if(m1.numRows != m2.numRows || m1.numCols != m2.numCols){ // check if matrix A and matrix B is same size
        throw std::invalid_argument("Arrays have incompatible sizes for this operation."); // throw error if not same size
    }

	myMat m3 = zeroMat(m1.numRows, m2.numCols);

	for(int i = 0; i < 16; i++) { //loop until all numbers in A and B are added to result and returned
            for(int j = 0; j < 16; j++) {
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
	printMat("MAS", m1);
	printMat("MAS", m2);
	myMat m3;
	if (m1.numRows == 1 && m1.numCols == 1)
	{
		m3 = zeroMat(m2.numRows, m2.numCols);
	}else if (m2.numRows == 1 && m2.numCols == 1) {
		m3 = zeroMat(m1.numRows, m1.numCols);

	}else if(m1.numRows != m2.numRows || m1.numCols != m2.numCols){ // check if matrix A and matrix B is same size
        throw std::invalid_argument("Arrays have incompatible sizes for this operation."); // throw error if not same size
    }else {
		m3 = zeroMat(m1.numRows, m2.numCols);
	}

	int val;
	
	for(int i = 0; i < 16; ++i) { // loop trough A and B, multiply and and to result, then return.
		for(int j = 0; j < 16; ++j) {
			for(int k = 0; k < 16; ++k) {
				val = getElem(m3, i, j) + getElem(m1, i, k) * getElem(m2, k, j);
				setElem(m3, i, j, val);
			}
		}
	}
	return m3;
}

int main()
{
	cout << "Richard's Matrix Example Program\n";
	myMat mA, mB, mC, mD, mE, mF;
	
	return 0;
}

