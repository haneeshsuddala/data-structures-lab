#include <iostream>
using namespace std;

#define SIZE 100

class Stack {
    int arr[SIZE];
    int top;
public:
    Stack() { top = -1; }
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << arr[top--] << endl;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == SIZE - 1;
    }
    void peek() {
        if (isEmpty()) cout << "Stack Empty\n";
        else cout << "Top element: " << arr[top] << endl;
    }
    void display() {
        if (isEmpty()) cout << "Stack Empty\n";
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, val;
    while (true) {
        cout << "\n1.Push 2.Pop 3.isEmpty 4.isFull 5.Display 6.Peek 7.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; s.push(val); break;
            case 2: s.pop(); break;
            case 3: cout << (s.isEmpty() ? "Stack Empty\n" : "Not Empty\n"); break;
            case 4: cout << (s.isFull() ? "Stack Full\n" : "Not Full\n"); break;
            case 5: s.display(); break;
            case 6: s.peek(); break;
            case 7: return 0;
            default: cout << "Invalid choice\n";
        }
    }
}