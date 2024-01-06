/*
    Name : Kazi Rifat Al Muin
    Roll : 2107042
    Assignment No : 03
    Topic : Linked List Basic Functions
*/

#pragma once        // To ensure it is included only once during the compilation of a source file

#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;     // Templated data member to store the value
        Node* next; // Pointer to the next node

        // Constructor to initialize the node with given data and next pointer
        Node(const T& value, Node* nextNode = nullptr) : data(value), next(nextNode) {}
    };

    Node* head; // Pointer to the head of the linked list

public:
    LinkedList() : head(nullptr) {}                    // Constructor to initialize an empty linked list
    LinkedList(Node* TheHead) : head(TheHead) {}       // Constructor to initialize with a Node as Head

    // Destructor to deallocate memory
    ~LinkedList() {
        clear();
    }

    // Function to insert a new node with the given value at the front of the list
    void insertFront(const T& value) {
        head = new Node(value, head);
    }

    // Function to insert a new node with the given value at the end of the list
    void insertEnd(const T& value) {
        if (!head) {
            head = new Node(value);     // If the head is NULL i.e. empty Linked List
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(value);
    }

    // Function to insert a new node with the given value at the specified position
    void insertAtPosition(int position, const T& value) {
        if (position == 0) {
            insertFront(value);
            return;
        }

        Node* newNode = new Node(value);

        if (!head) {
            head = newNode;     // If the head is NULL i.e. empty Linked List
            return;
        }

        Node* current = head;
        int currentPosition = 1;

        while (currentPosition < position) {
            if(current->next == NULL){
                cout << "The List is not that Long!\n";
                return;
            }
            current = current->next;
            currentPosition++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Function to search for a node with the specified value
    bool search(const T& value) const {
        Node* current = head;

        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // Function to display the elements of the linked list
    void display() const {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // Function to get the length of the linked list
    int getLength() const {
        int length = 0;
        Node* current = head;

        while (current) {
            length++;
            current = current->next;
        }

        return length;
    }

    // Function to clear the entire linked list
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};