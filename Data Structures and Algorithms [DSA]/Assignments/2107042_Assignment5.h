#include <iostream>
using namespace std;

// Node class represents a node in the linked list
template <typename T>
class Node {
public:
    T data;        // Data stored in the node
    Node* next;    // Pointer to the next node
    Node* prev;    // Pointer to the previous node

    // Constructor to initialize a node with a given value
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

// Deque class represents a double-ended queue
template <typename T>
class Deque {
private:
    Node<T>* front;    // Pointer to the front of the deque
    Node<T>* rear;     // Pointer to the rear of the deque

protected:
    // Protected member function to get the front node
    Node<T>* getFront() const {
        return front;
    }

    // Protected member function to get the rear node
    Node<T>* getRear() const {
        return rear;
    }

public:
    // Constructor to initialize the deque
    Deque() : front(nullptr), rear(nullptr) {}

    // Destructor to deallocate memory
    ~Deque() {
        while (!empty()) {
            pop_front();
        }
    }

    // Inserts a node with the given value at the front of the deque
    void push_front(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Inserts a node with the given value at the end of the deque
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (empty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Deletes the node at the front of the deque
    void pop_front() {
        if (!empty()) {
            Node<T>* temp = front;
            front = front->next;
            if (front) {
                front->prev = nullptr;
            } else {
                rear = nullptr;
            }
            delete temp;
        }
    }

    // Deletes the node at the end of the deque
    void pop_back() {
        if (!empty()) {
            Node<T>* temp = rear;
            rear = rear->prev;
            if (rear) {
                rear->next = nullptr;
            } else {
                front = nullptr;
            }
            delete temp;
        }
    }

    // Checks if the deque is empty
    bool empty() const {
        return front == nullptr;
    }

    // Displays the elements of the deque
    void display() const {
        Node<T>* current = front;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Returns the size of the deque
    int size() const {
        int count = 0;
        Node<T>* current = front;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Queue class represents a queue inheriting from the Deque class
template <typename T>
class Queue : private Deque<T> {
private:
    // Using declarations to access protected members from the base class
    using Deque<T>::getFront;
    using Deque<T>::getRear;

public:
    // Constructor to initialize the queue
    Queue() {}

    // Destructor to deallocate memory
    ~Queue() {}

    // Inserts a node with the given value at the end of the queue
    void push(const T& value) {
        this->push_back(value);
    }

    // Deletes the oldest node from the front of the queue
    void pop() {
        Node<T>* front = getFront();
        if (front) {
            this->pop_front();
            delete front;
        }
    }

    // Displays the elements of the queue
    void display() const {
        Node<T>* front = getFront();
        while (front) {
            cout << front->data << " ";
            front = front->next;
        }
        cout << endl;
    }

    // Returns the size of the queue
    int size() const {
        return this->Deque<T>::size();
    }

    bool empty() const {
        return this->Deque<T>::empty();
    }
};

// Stack class represents a stack inheriting from the Deque class
template <typename T>
class Stack : private Deque<T> {
private:
    // Using declarations to access protected members from the base class
    using Deque<T>::getFront;
    using Deque<T>::getRear;

public:
    // Constructor to initialize the stack
    Stack() {}

    // Destructor to deallocate memory
    ~Stack() {}

    // Inserts a node with the given value at the top of the stack
    void push(const T& value) {
        this->push_front(value);
    }

    // Deletes the node from the top of the stack
    void pop() {
        Node<T>* front = getFront();
        if (front) {
            this->pop_front();
            delete front;
        }
    }

    // Displays the elements of the stack
    void display() const {
        Node<T>* front = getFront();
        while (front) {
            cout << front->data << " ";
            front = front->next;
        }
        cout << endl;
    }

    // Returns the size of the stack
    int size() const {
        return this->Deque<T>::size();
    }

    bool empty() const {
        return this->Deque<T>::empty();
    }
};

