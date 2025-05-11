#include <iostream>
#include <exception>

using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template <typename T>
class Queue {
    int capacity;
    T* data;
    int front, rear, size;

public:
    Queue(int cap) : capacity(cap), front(0), rear(0), size(0) {
        data = new T[capacity];
    }

    ~Queue() {
        delete[] data;
    }

    void enqueue(const T& value) {
        if (size == capacity)
            throw QueueOverflowException();
        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++size;
    }

    T dequeue() {
        if (size == 0)
            throw QueueUnderflowException();
        T temp = data[front];
        front = (front + 1) % capacity;
        --size;
        return temp;
    }
};

int main() {
    Queue<int> q(2);

    try {
        cout << "Attempting to enqueue to a full queue...\n";
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30); 
    } catch (QueueOverflowException& e) {
        cout << "Caught QueueOverflowException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to dequeue from an empty queue...\n";
        q.dequeue(); 
        q.dequeue();
        q.dequeue(); 
    } catch (QueueUnderflowException& e) {
        cout << "Caught QueueUnderflowException - what(): " << e.what() << endl;
    }

    return 0;
}
