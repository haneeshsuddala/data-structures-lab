#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int A[] = {1,2,3,4};
    int B[] = {3,4,5,6};
    int n1 = 4, n2 = 4;

    unordered_set<int> s;
    for(int i=0;i<n1;i++) s.insert(A[i]);

    for(int i=0;i<n2;i++){
        if(s.find(B[i])!=s.end()) cout << B[i] << " ";
    }
    return 0;
}