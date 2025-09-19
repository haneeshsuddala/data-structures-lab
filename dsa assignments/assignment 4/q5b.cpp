#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(10); s.push(20); s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}