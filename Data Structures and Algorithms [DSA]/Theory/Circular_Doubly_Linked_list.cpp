#include <iostream>
using namespace std;

// Node class for circular doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor: initialize node with a given value
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to display the circular doubly linked list
void displayList(Node* head) {
    if (!head) {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = head;
    do {
        cout << curr->data << " <-> ";
        curr = curr->next;
    } while (curr != head);
    cout << "(back to head: " << head->data << ")" << endl;
}

// Helper function to get the length of the circular doubly linked list
int getLength(Node* head) {
    if (!head) return 0;
    int length = 0;
    Node* curr = head;
    do {
        length++;
        curr = curr->next;
    } while (curr != head);
    return length;
}

// Function to insert a node at the head of the list
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        // For an empty list, newNode points to itself
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev;  // tail is the previous node of head
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
        head = newNode;  // Update head pointer
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(Node*& head, int data) {
    if (!head) {
        insertAtHead(head, data);
    } else {
        Node* tail = head->prev;
        Node* newNode = new Node(data);
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
    }
}

// Function to insert a node at any given position (0-indexed)
// If position equals length, the node is inserted at the end.
// If position is out-of-range (greater than length), nothing happens.
void insertAtAny(Node*& head, int data, int position) {
    int length = getLength(head);
    if (position < 0 || position > length)
        return;  // Invalid position
    if (position == 0) {
        insertAtHead(head, data);
    } else if (position == length) {
        insertAtEnd(head, data);
    } else {
        // Traverse to the node currently at the given position
        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        // Insert new node between curr->prev and curr
        Node* prev = curr->prev;
        Node* newNode = new Node(data);
        newNode->next = curr;
        newNode->prev = prev;
        prev->next = newNode;
        curr->prev = newNode;
    }
}

// Function to delete the head node of the list
void deleteAtHead(Node*& head) {
    if (!head)
        return;
    if (head->next == head) { // Only one node in the list
        delete head;
        head = nullptr;
    } else {
        Node* tail = head->prev;
        Node* temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
}

// Function to delete the last node of the list
void deleteAtEnd(Node*& head) {
    if (!head)
        return;
    if (head->next == head) {  // Only one node exists
        delete head;
        head = nullptr;
    } else {
        Node* tail = head->prev;
        Node* newTail = tail->prev;
        newTail->next = head;
        head->prev = newTail;
        delete tail;
    }
}

// Function to delete a node at any given position (0-indexed)
// If the position is invalid, nothing happens.
void deleteAtAny(Node*& head, int position) {
    int length = getLength(head);
    if (!head || position < 0 || position >= length)
        return;
    if (position == 0) {
        deleteAtHead(head);
    } else if (position == length - 1) {
        deleteAtEnd(head);
    } else {
        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        Node* prev = curr->prev;
        Node* next = curr->next;
        prev->next = next;
        next->prev = prev;
        delete curr;
    }
}

// Function to delete the first node with a specific value
void deleteByValue(Node*& head, int value) {
    if (!head)
        return;
    Node* curr = head;
    int length = getLength(head);
    for (int i = 0; i < length; i++) {
        if (curr->data == value) {
            if (curr->next == curr) { // Only one node in the list
                delete curr;
                head = nullptr;
            } else if (curr == head) {
                deleteAtHead(head);
            } else {
                Node* prev = curr->prev;
                Node* next = curr->next;
                prev->next = next;
                next->prev = prev;
                delete curr;
            }
            return;
        }
        curr = curr->next;
    }
}

// Function to reverse the circular doubly linked list
// Swaps the next and prev pointers for every node and updates head.
void reverseList(Node*& head) {
    if (!head)
        return;
    int length = getLength(head);
    Node* curr = head;
    for (int i = 0; i < length; i++) {
        Node* temp = curr->next;
        curr->next = curr->prev;
        curr->prev = temp;
        curr = temp;
    }
    // New head is the old head's previous node (tail)
    head = head->prev;
}

// Function to find the middle element using a two-pointer approach
void findMid(Node* head) {
    if (!head) {
        cout << "Mid of the list: nullptr" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;
    // For circular list, stop when fast reaches head or one node before head
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid of the list: " << slow->data << endl;
}

// Main function to demonstrate circular doubly linked list operations
int main() {
    Node* head = nullptr;
    cout << "=== Circular Doubly Linked List Operations Demo ===" << endl << endl;
    
    // Test insertAtHead with detailed prints
    cout << "Operation: insertAtHead(head, 3)" << endl;
    insertAtHead(head, 3);
    cout << "List after inserting 3 at head: ";
    displayList(head);
    
    cout << "Operation: insertAtHead(head, 2)" << endl;
    insertAtHead(head, 2);
    cout << "List after inserting 2 at head: ";
    displayList(head);
    
    cout << "Operation: insertAtHead(head, 1)" << endl;
    insertAtHead(head, 1);
    cout << "List after inserting 1 at head: ";
    displayList(head);
    
    // Test insertAtEnd with detailed prints
    cout << "\nOperation: insertAtEnd(head, 4)" << endl;
    insertAtEnd(head, 4);
    cout << "List after inserting 4 at end: ";
    displayList(head);
    
    cout << "Operation: insertAtEnd(head, 5)" << endl;
    insertAtEnd(head, 5);
    cout << "List after inserting 5 at end: ";
    displayList(head);
    
    // Test insertAtAny with detailed prints
    cout << "\nOperation: insertAtAny(head, 6, 2)" << endl;
    insertAtAny(head, 6, 2);
    cout << "List after inserting 6 at position 2: ";
    displayList(head);
    
    // Additional test: insert at position 0 (head) using insertAtAny
    cout << "\nOperation: insertAtAny(head, 7, 0) [should act like insertAtHead]" << endl;
    insertAtAny(head, 7, 0);
    cout << "List after inserting 7 at position 0: ";
    displayList(head);
    
    // Additional test: insert at end using insertAtAny (position equal to length)
    int len = getLength(head);
    cout << "\nOperation: insertAtAny(head, 8, " << len << ") [should act like insertAtEnd]" << endl;
    insertAtAny(head, 8, len);
    cout << "List after inserting 8 at position " << len << ": ";
    displayList(head);
    
    // Test deleteAtHead with detailed prints
    cout << "\nOperation: deleteAtHead(head)" << endl;
    deleteAtHead(head);
    cout << "List after deleting head: ";
    displayList(head);
    
    // Test deleteAtEnd with detailed prints
    cout << "\nOperation: deleteAtEnd(head)" << endl;
    deleteAtEnd(head);
    cout << "List after deleting end: ";
    displayList(head);
    
    // Test deleteAtAny with detailed prints
    cout << "\nOperation: deleteAtAny(head, 2) [deleting element at index 2]" << endl;
    deleteAtAny(head, 2);
    cout << "List after deleting node at position 2: ";
    displayList(head);
    
    // Test deleteByValue with detailed prints
    cout << "\nOperation: deleteByValue(head, 4)" << endl;
    deleteByValue(head, 4);
    cout << "List after deleting node with value 4: ";
    displayList(head);
    
    // Additional test: delete by a non-existing value
    cout << "\nOperation: deleteByValue(head, 100) [value not in list]" << endl;
    deleteByValue(head, 100);
    cout << "List after attempting to delete node with value 100: ";
    displayList(head);
    
    // Test reverseList with detailed prints
    cout << "\nOperation: reverseList(head)" << endl;
    reverseList(head);
    cout << "List after reversing: ";
    displayList(head);
    
    // Test findMid with detailed prints
    cout << "\nOperation: findMid(head)" << endl;
    findMid(head);
    
    // Final test: perform a sequence of operations
    cout << "\n=== Additional Sequence Test ===" << endl;
    cout << "Inserting elements 9 and 10 at end:" << endl;
    insertAtEnd(head, 9);
    insertAtEnd(head, 10);
    cout << "List now: ";
    displayList(head);
    
    cout << "Inserting element 11 at head:" << endl;
    insertAtHead(head, 11);
    cout << "List now: ";
    displayList(head);
    
    cout << "Deleting the head node:" << endl;
    deleteAtHead(head);
    cout << "List now: ";
    displayList(head);
    
    cout << "Deleting node at position 3:" << endl;
    deleteAtAny(head, 3);
    cout << "List now: ";
    displayList(head);
    
    // Free memory by deleting all nodes
    while (head) {
        deleteAtHead(head);
    }
    
    cout << "\nAll nodes deleted. End of operations." << endl;
    
    return 0;
}
