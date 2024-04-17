#include <iostream>

using namespace std;

// Node class for Linked List
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

// PriorityQueue class using Linked List
template<typename T, bool ascending = true>
class PriorityQueue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size_;

    // Helper function to insert node into appropriate position
    void insertNode(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            Node<T>* current = head;
            if (ascending) {
                while (current && current->data < value) {
                    current = current->next;
                }
            } else {
                while (current && current->data > value) {
                    current = current->next;
                }
            }
            if (!current) {
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            } else {
                if (current == head) {
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                } else {
                    newNode->prev = current->prev;
                    newNode->next = current;
                    current->prev->next = newNode;
                    current->prev = newNode;
                }
            }
        }
        size_++;
    }

public:
    // Constructor
    PriorityQueue() : head(nullptr), tail(nullptr), size_(0) {}

    // Destructor
    ~PriorityQueue() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Returns the top element
    T top() const {
        if (head) {
            return head->data;
        } else {
            throw out_of_range("PriorityQueue is empty");
        }
    }

    // Checks whether the PriorityQueue is empty
    bool empty() const {
        return size_ == 0;
    }

    // Returns the number of elements
    int size() const {
        return size_;
    }

    // Inserts element and sorts the underlying container
    void push(const T& value) {
        insertNode(value);
    }

    // Removes the top element
    void pop() {
        if (head) {
            Node<T>* temp = head;
            head = head->next;
            if (head)
                head->prev = nullptr;
            delete temp;
            size_--;
        } else {
            throw out_of_range("PriorityQueue is empty");
        }
    }
};


int main() {
    PriorityQueue<int> pq_asc;
    cout << "Testing ascending PriorityQueue:" << endl;

    // Testing empty() and size()
    cout << "Is PriorityQueue empty? " << (pq_asc.empty() ? "Yes" : "No") << endl;
    cout << "PriorityQueue size: " << pq_asc.size() << endl;

    // Testing push()
    pq_asc.push(5);
    pq_asc.push(3);
    pq_asc.push(8);
    pq_asc.push(1);
    pq_asc.push(10);
    cout << "Inserted elements: 5, 3, 8, 1, 10" << endl;

    // Testing top()
    cout << "Top element: " << pq_asc.top() << endl;

    // Testing pop()
    pq_asc.pop();
    cout << "After popping top element" << endl;
    cout << "Top element: " << pq_asc.top() << endl;

    // Testing empty() and size() after operations
    cout << "Is PriorityQueue empty? " << (pq_asc.empty() ? "Yes" : "No") << endl;
    cout << "PriorityQueue size: " << pq_asc.size() << endl;

    // Testing descending PriorityQueue
    PriorityQueue<int, false> pq_desc;
    cout << "Testing descending PriorityQueue:" << endl;

    pq_desc.push(5);
    pq_desc.push(3);
    pq_desc.push(8);
    pq_desc.push(1);
    pq_desc.push(10);
    cout << "Inserted elements: 5, 3, 8, 1, 10" << endl;

    cout << "Top element: " << pq_desc.top() << endl;

    pq_desc.pop();
    cout << "After popping top element" << endl;
    cout << "Top element: " << pq_desc.top() << endl;

    cout << "Is PriorityQueue empty? " << (pq_desc.empty() ? "Yes" : "No") << endl;
    cout << "PriorityQueue size: " << pq_desc.size() << endl;
    return 0;
}
