#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, result = "";
    cout << "Enter a string: ";
    cin >> s;

    for (char c : s) {
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
              c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')) {
            result += c;
        }
    }

    cout << "String without vowels: " << result;
    return 0;
}