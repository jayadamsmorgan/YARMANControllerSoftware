#ifndef STRINGQUEUE_HPP
#define STRINGQUEUE_HPP

#include "Arduino.h"

// Define a StringNode structure for the linked list
struct StringNode {
    String data;
    StringNode* next;

    StringNode(String d) : data(d), next(nullptr) {}
};

// Define the Queue class
class StringQueue {
private:
    StringNode* front;  // Pointer to the front of the queue
    StringNode* rear;   // Pointer to the rear of the queue

public:
    StringQueue() : front(nullptr), rear(nullptr) {}

    // Check if the queue is empty
    bool isEmpty() const {
        return front == nullptr;
    }

    // Add an element to the queue
    void enqueue(String data) {
        StringNode* newNode = new StringNode(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // Remove an element from the queue
    // Returns false if queue is empty
    bool dequeue() {
        if (isEmpty()) {
            return false;
        }
        StringNode* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        return true;
    }

    // Get the front element
    // Returns false if queue is empty
    bool getFront(String& ptr) const {
        if (isEmpty()) {
            return false;
        }
        ptr = front->data;
        return true;
    }

    // Destructor to clean up memory
    ~StringQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif // STRINGQUEUE_HPP
