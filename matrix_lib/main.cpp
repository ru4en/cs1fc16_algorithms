#include "mat_lib.h"
#include <iostream>
#include <vector>

using namespace std;
typedef vector< vector<int> > Matrix; 
/* Define matrices using Matrix Object.


to use mat_lib simply call add(Matrix a, Matrix b), print(Matrix) or
multiply(Matrix a, Matrix b) functions.

*/
int main() {
    Matrix matrixA = { 
        {1,2,3,3} ,
        {4,5,6,3} ,
        {7,8,9,3}
        };

    Matrix matrixB = {
        {10, 20, 30} ,
        {40, 50, 60} ,
        {70, 80, 90} ,
        {70, 80, 90}
        };
        
    Matrix matrixC = add(matrixB, matrixB);
    print(matrixC);
    return 0;
}