#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<int> > Matrix; 

void print(Matrix result); //DONE
Matrix dot(Matrix a, Matrix b);
Matrix transpose(Matrix result);
Matrix add(Matrix a, Matrix b); //DONE
Matrix multiply(Matrix a, Matrix b); //DONE
Matrix magic(Matrix a, Matrix b);
Matrix determinant(Matrix a, Matrix b);
