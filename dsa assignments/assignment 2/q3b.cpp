#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int arr[n - 1];
    cout << "Enter " << n - 1 << " sorted elements: ";
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }

    int low = 0, high = n - 2, missing = n;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            missing = mid + 1;
            high = mid - 1;
        }
    }

    cout << "Missing number is " << missing;
    return 0;
}