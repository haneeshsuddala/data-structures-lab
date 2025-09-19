#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c;
    cout << "Enter uppercase character: ";
    cin >> c;

    char lower = tolower(c);
    cout << "Lowercase: " << lower;
    return 0;
}