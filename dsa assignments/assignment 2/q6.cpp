#include <iostream>
using namespace std;

int main() {
    int r, c, n;
    cout << "Enter rows, cols, non-zero elements: ";
    cin >> r >> c >> n;

    int triplet[n][3];
    cout << "Enter triplet (row col value):\n";
    for (int i = 0; i < n; i++) {
        cin >> triplet[i][0] >> triplet[i][1] >> triplet[i][2];
    }

    cout << "Transpose triplet:\n";
    for (int i = 0; i < n; i++) {
        cout << triplet[i][1] << " " << triplet[i][0] << " " << triplet[i][2] << endl;
    }
    return 0;
}