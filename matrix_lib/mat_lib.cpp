#include <iostream>

using namespace std;

class matrix{
    public:

    int row = 3;
    int column = 3;


    int print(int *grid, int row, int column) {
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < column; j++) {
                cout << *grid[i][j];
            }
            cout << endl;
        }
    return 0;
    }
};

int main() {
    matrix x;
    int grid[3][3] = {{1 , 2, 3},{4 , 5, 6},{7 , 8, 9}};

    x.print(*grid, 3, 3);
}
