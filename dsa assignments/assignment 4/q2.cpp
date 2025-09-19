#include <iostream>
using namespace std;
#define SIZE 5

int cq[SIZE], front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % SIZE == front) cout << "Queue is Full\n";
    else {
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        cq[rear] = x;
    }
}

void dequeue() {
    if (front == -1) cout << "Queue is Empty\n";
    else {
        cout << "Dequeued: " << cq[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) cout << "Queue is Empty\n";
    else {
        int i = front;
        while (true) {
            cout << cq[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
}

void peek() {
    if (front == -1) cout << "Queue is Empty\n";
    else cout << "Front: " << cq[front] << endl;
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