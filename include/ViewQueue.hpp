#ifndef VIEWQUEUE_HPP
#define VIEWQUEUE_HPP

#include "View.hpp"

struct ViewNode {
    View data;
    ViewNode* next;

    ViewNode(View d) : data(d), next(nullptr) {}
};

class ViewQueue {
private:
    ViewNode* front;
    ViewNode* rear;

public:
    ViewQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() const {
        return front == nullptr;
    }

    void enqueue(View data) {
        ViewNode* newNode = new ViewNode(data);
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
        ViewNode* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }
        
        delete temp;
        return true;
    }

    bool getFront(View& ptr) const {
        if (isEmpty()) {
            return false;
        }
        ptr = front->data;
        return true;
    }

    ~ViewQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

#endif // VIEWQUEUE_HPP
