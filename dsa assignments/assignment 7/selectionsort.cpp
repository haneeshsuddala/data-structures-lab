#include <iostream>
using namespace std;

void selection(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[m]) m = j;
        int t = a[i];
        a[i] = a[m];
        a[m] = t;
    }
}

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    selection(a, n);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}