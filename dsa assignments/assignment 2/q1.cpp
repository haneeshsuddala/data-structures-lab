#include <iostream>
using namespace std;

int main() {
    int n, key;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            pos = i;
            break;
        }
    }
    if (pos == -1)
        cout << "Linear Search: Element not found" << endl;
    else
        cout << "Linear Search: Element found at position " << pos + 1 << endl;

    int low = 0, high = n - 1;
    pos = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            pos = mid;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (pos == -1)
        cout << "Binary Search: Element not found";
    else
        cout << "Binary Search: Element found at position " << pos + 1;

    return 0;
}