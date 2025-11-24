#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int a[] = {4,5,1,2,0,4};
    int n = 6;
    unordered_map<int,int> mp;

    for(int i=0;i<n;i++) mp[a[i]]++;

    for(int i=0;i<n;i++){
        if(mp[a[i]]==1){
            cout << a[i];
            break;
        }
    }
    return 0;
}