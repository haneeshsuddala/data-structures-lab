#include <iostream>
using namespace std;
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if (rear == SIZE - 1) cout << "Queue is Full\n";
    else {
        if (front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if (front == -1 || front > rear) cout << "Queue is Empty\n";
    else cout << "Dequeued: " << queue[front++] << endl;
}

void display() {
    if (front == -1 || front > rear) cout << "Queue is Empty\n";
    else {
        for (int i = front; i <= rear; i++) cout << queue[i] << " ";
        cout << endl;
    }
}

void peek() {
    if (front == -1 || front > rear) cout << "Queue is Empty\n";
    else cout << "Front: " << queue[front] << endl;
}

int main() {
    int choice, val;
    while (1) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cin >> choice;
        if (choice == 1) { cin >> val; enqueue(val); }
        else if (choice == 2) dequeue();
        else if (choice == 3) display();
        else if (choice == 4) peek();
        else break;
    }
}