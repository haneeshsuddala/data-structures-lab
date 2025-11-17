#include <iostream>
using namespace std;

class PriorityQueue {
    int arr[100];
    int size;

    void heapifyUp(int i) {
        while (i > 0 && arr[(i-1)/2] < arr[i]) {
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = 2*i + 1;
        int r = 2*i + 2;

        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapifyDown(largest);
        }
    }

public:
    PriorityQueue() { size = 0; }

    void insert(int value) {
        arr[size] = value;
        heapifyUp(size);
        size++;
    }

    int getMax() {
        return size == 0 ? -1 : arr[0];
    }

    int extractMax() {
        if (size == 0) return -1;
        int maxVal = arr[0];
        arr[0] = arr[size-1];
        size--;
        heapifyDown(0);
        return maxVal;
    }

    void increaseKey(int index, int newValue) {
        if (index < 0 || index >= size) return;
        arr[index] = newValue;
        heapifyUp(index);
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    
    pq.insert(30);
    pq.insert(10);
    pq.insert(50);
    pq.insert(40);
    pq.insert(20);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Maximum Element: " << pq.getMax() << endl;

    cout << "Extracted Max: " << pq.extractMax() << endl;

    cout << "After Extraction: ";
    pq.display();

    pq.increaseKey(2, 60);

    cout << "After Increase Key: ";
    pq.display();

    return 0;
}