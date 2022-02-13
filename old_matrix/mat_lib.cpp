#include <iostream>
#include <vector> // im using the vector module mainly for not having to mess around with pointors and arrays. 

using namespace std;

typedef vector< vector<int> > Matrix; // defing matrix "Data type" 

    void print(Matrix result) { // function used to print matrix

        int rows = result.size(); // get items in row 
        int cols = result[0].size(); // get items in column

        for(int i = 0; i < rows; i++) { // loop over until all rows are printed 
            for(int j = 0; j < cols; j++) {  // loop over until all columns are printed 
                cout << result[i][j] << "\t\t"; // output current item in matrix
            }
            cout << endl; // print next line when row over
        }
    }    

    Matrix add(Matrix a, Matrix b) { // function for matrix adition 
        if(a.size() != b.size() || a[0].size() != b[0].size()){ // check if matrix A and matrix B is same size
            throw std::invalid_argument("Arrays have incompatible sizes for this operation."); // throw error if not same size
        }

        int rows = a.size(); 
        int cols = b[0].size();

        vector< vector<int> > result(rows, vector<int> (cols, 0)); // create vector with zeros

        for(int i = 0; i < rows; i++) { //loop until all numbers in A and B are added to result and returned
            for(int j = 0; j < cols; j++) {
                result[i][j] += a[i][j] + b[i][j];
            }
        }
        return result;
    }

    Matrix multiply(Matrix a, Matrix b) { // function for matrix multiplication 

        if(a[0].size() != b.size()){ // if matrix As columns are not the same size as matrix Bs rows throw error
            throw std::invalid_argument("Incorrect dimensions for matrix multiplication.");
        }
        
        int cols = a.size();
        int  rows= b[0].size();
        vector< vector<int> > result(cols, vector<int> (rows, 0)); 

        for(int i = 0; i < a.size(); ++i) { // loop trough A and B, multiply and and to result, then return.
            for(int j = 0; j < a.size()+1; ++j) {
                for(int k = 0; k < b.size(); ++k) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }