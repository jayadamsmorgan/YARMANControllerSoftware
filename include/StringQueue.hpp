#ifndef STRINGQUEUE_HPP
#define STRINGQUEUE_HPP

#include "Arduino.h"

struct StringNode {
    String data;
    StringNode* next;

    StringNode(String d) : data(d), next(nullptr) {}
};

class StringQueue {
private:
    StringNode* front;
    StringNode* rear;

public:
    StringQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(String data) {
        StringNode* newNode = new StringNode(data);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

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

    bool getFront(String& ptr) const {
        if (isEmpty()) {
            return false;
        }
        ptr = front->data;
        return true;
    }

    ~StringQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif // !STRINGQUEUE_HPP
