#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int nums[] = {1,2,3,1};
    int n = 4;
    unordered_set<int> s;
    bool f = false;

    for(int i=0;i<n;i++){
        if(s.find(nums[i])!=s.end()){
            f = true;
            break;
        }
        s.insert(nums[i]);
    }

    cout << (f ? "true" : "false");
    return 0;
}