#pragma once
#include<iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node *next;
    Node *prev;
};

template <class T>
class DoublyLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;

public:
    // Constructor
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destructor
    ~DoublyLinkedList() {
        Node<T> *cur = head, *nextNode;
        // Delete each node in the list
        while (cur != NULL) {
            nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
        head = NULL;
        tail = NULL;
    }

    // Insert a node with the given value at the beginning of the doubly linked list
    void insertBegin(const T& value) {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
            head->prev = newNode;
        if (tail == NULL)
            tail = newNode;
        head = newNode;
    }

    // Insert a node with the given value at the end of the doubly linked list
    void insertEnd(const T& value) {
        if (head == NULL) {
            insertBegin(value);
            return;
        }

        Node<T> *newNode = new Node<T>, *cur = head;
        newNode->data = value;
        newNode->prev = tail;
        newNode->next = NULL;

        if (tail != NULL)
            tail->next = newNode;
        if (head == NULL)
            head = newNode;
        tail = newNode;
    }

    // Insert a node with the given value at the specified position in the doubly linked list
    void insertAtPosition(int position, const T& value) {
        if (position < 0 || position > getLength()) {
            // Handle invalid position
            cout << "Invalid position!" << endl;
            return;
        } else if (position == 0) {
            insertBegin(value);
            return;
        }

        Node<T> *cur = head;
        Node<T> *newNode = new Node<T>;
        newNode->data = value;

        for (; position != 1; cur = cur->next, position--);

        newNode->next = cur->next;
        newNode->prev = cur;

        if (cur->next != NULL)
            cur->next->prev = newNode;
        else
            tail = newNode;

        cur->next = newNode;
    }

    // Delete the node at the beginning of the doubly linked list
    void deleteBegin() {
        if (head == NULL) return;

        Node<T> *cur = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        else
            tail = NULL;

        delete cur;
    }

    // Delete the node at the end of the doubly linked list
    void deleteEnd() {
        if (tail == NULL) return;

        Node<T> *cur = tail;
        tail = tail->prev;
        if (tail != NULL)
            tail->next = NULL;
        else
            head = NULL;

        delete cur;
    }

    // Delete the node at the specified position in the doubly linked list
    void deleteAtPosition(int position) {
        if (head == NULL) return;

        Node<T> *cur = head;

        for (; cur != NULL && position != 0; cur = cur->next, position--);

        if (cur == NULL) {
            // Handle invalid position
            cout << "Deletion not possible." << endl;
            return;
        }

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        delete cur;
    }

    // Delete node(s) with the specified value from the doubly linked list
    void deleteByValue(const T& value) {
        if (head == NULL) return;

        Node<T> *cur = head, *temp;

        while (cur != NULL) {
            if (cur->data == value) {
                temp = cur->next;
                if (cur->prev)
                    cur->prev->next = cur->next;
                else
                    head = head->next;

                if (cur->next)
                    cur->next->prev = cur->prev;
                else
                    tail = tail->prev;

                delete cur;
                cur = temp;
            } else {
                cur = cur->next;
            }
        }
    }

    // Partition the list for QuickSort
    Node<T>* _partition(Node<T> *low, Node<T> *high) {
        T pivot = high->data;
        Node<T> *cur = low->prev;

        for (Node<T> *j = low; j != high; j = j->next) {
            if (j->data <= pivot) {
                cur = (cur == NULL) ? low : cur->next;
                swap(cur->data, j->data);
            }
        }
        cur = (cur == NULL) ? low : cur->next;
        swap(cur->data, high->data);
        return cur;
    }

    // Perform QuickSort on the doubly linked list
    void quickSort() {
        // Call the helper function with head and tail
        _quickSortHelper(head, tail);
    }

    // Helper function for quickSort
    void _quickSortHelper(Node<T>* low, Node<T>* high) {
        if (high != NULL && low != high && low != high->next) {
            Node<T>* p = _partition(low, high);
            _quickSortHelper(low, p->prev);
            _quickSortHelper(p->next, high);
        }
    }

    // Find the middle node of the doubly linked list
    Node<T>* findMid(Node<T> *head) {
        Node<T> *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node<T>* temp = slow->next;
        slow->next = NULL;
        return temp;
    }

    // Merge two sorted linked lists
    Node<T>* _merge(Node<T> *first, Node<T> *last) {
        if (first == NULL) return last;
        if (last == NULL) return first;

        if (first->data < last->data) {
            first->next = _merge(first->next, last);
            first->next->prev = first;
            first->prev = NULL;
            return first;
        } else {
            last->next = _merge(first, last->next);
            last->next->prev = last;
            last->prev = NULL;
            return last;
        }
    }

    // mergeSort using a helper function
    void mergeSort() {
        // Call the helper function with head
        head = _mergeSortHelper(head);
        tail = head;
        while (tail && tail->next) tail = tail->next;
    }

    // Helper function for mergeSort
    Node<T>* _mergeSortHelper(Node<T>* head) {
        if (!head || !head->next)
            return head;

        Node<T>* mid = findMid(head);
        head = _mergeSortHelper(head);
        mid = _mergeSortHelper(mid);

        return _merge(head, mid);
    }

    // Get the length of the doubly linked list
    int getLength() {
        int length = 0;
        for (auto cur = head; cur != NULL; cur = cur->next, length++);
        return length;
    }

    // Display the doubly linked list
    void display() {
        Node<T> *cur = head;
        cout << "Doubly Linked List: ";
        while (cur != NULL) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
