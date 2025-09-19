#include <iostream>
#include <queue>
using namespace std;

void interleave(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    queue<int> first;
    for (int i = 0; i < half; i++) {
        first.push(q.front());
        q.pop();
    }
    while (!first.empty()) {
        q.push(first.front()); first.pop();
        q.push(q.front()); q.pop();
    }
}

int main() {
    queue<int> q;
    int arr[] = {4,7,11,20,5,9};
    for (int x : arr) q.push(x);
    interleave(q);
    while (!q.empty()) { cout << q.front() << " "; q.pop(); }
}