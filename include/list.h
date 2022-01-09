#ifndef LIST_H
#define LIST_H

// Doubly linked list
template <typename T>
class ListDouble {
public:
    struct Node {
        T value;
        Node *prev;
        Node *next;
        Node(T value):
            value(value), prev(nullptr), next(nullptr) {}
    };
    ListDouble(): front(nullptr), back(nullptr) {}
    void push_front(const T &value) {
        Node *n = new Node(value);
        if (front) {
            n->next = front;
            front->prev = n;
        } else {
            back = n;
        }
        front = n;
    }
    T pop_front() {
        T value = front->value;
        Node *old = front;
        front = old->next;
        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }
        delete old;
        return value;
    }
    void insert(Node *at, T value) {
        Node *n = new Node(value);
        Node *next = at->next;
        at->next = n;
        next->prev = n;
    }
    void remove(Node *n) {
        if(n->prev) {
            n->prev->next = n->next;
        } else {
            front = n->next;
        }
        if(n->next) {
            n->next->prev = n->prev;
        } else {
            back = n->prev;
        }
        delete n;
    }
    void reverse() {
        Node *it = front;
        Node *prev;
        while (it != nullptr) {
            prev = it->prev;
            it->prev = it->next;
            it->next = prev;
            it = it->prev;
        }
        Node *old_back = back;
        back = front;
        front = old_back;
    }
    Node *front;
    Node *back;
};

#endif
