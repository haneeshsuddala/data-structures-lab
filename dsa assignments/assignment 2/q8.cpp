#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) count++;
    }

    cout << "Total distinct elements: " << count;
    return 0;
}