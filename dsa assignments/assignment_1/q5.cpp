#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    int A[r][c];

    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> A[i][j];
        }
    }

    // Sum of rows
    cout << "Sum of each row:\n";
    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i + 1 << " = " << rowSum << endl;
    }

    // Sum of columns
    cout << "Sum of each column:\n";
    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}