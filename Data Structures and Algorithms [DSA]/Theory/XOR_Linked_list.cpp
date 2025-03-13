#include <iostream>
#include <cstdint>   // for uintptr_t

using namespace std;

// Node class for XOR linked list: one pointer stores XOR(prev, next)
class Node {
public:
    int data;       // Data stored in the node
    Node* npx;      // XOR of next and previous node pointers

    // Constructor: initialize node with value and npx = nullptr
    Node(int value) : data(value), npx(nullptr) {}
};

// Utility function to XOR two node pointers
Node* XOR(Node* a, Node* b) {
    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t>(a) ^ reinterpret_cast<uintptr_t>(b)
    );
}

// Function to display the entire XOR linked list
void displayList(Node* head) {
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while (curr) {
        cout << curr->data << " -> ";
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node at the head of the XOR linked list
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    // new node's npx is XOR(NULL, head)
    newNode->npx = XOR(nullptr, head);
    if (head) {
        // For the old head, its npx was: XOR(nullptr, next)
        // Update it: new npx becomes XOR(newNode, next)
        head->npx = XOR(newNode, XOR(nullptr, head->npx));
    }
    head = newNode;
}

// Function to insert a node at the end of the XOR linked list
void insertAtEnd(Node*& head, int data) {
    if (!head) {
        insertAtHead(head, data);
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    // Traverse until the tail (where next is nullptr)
    while (true) {
        next = XOR(prev, curr->npx);
        if (!next)
            break;
        prev = curr;
        curr = next;
    }
    // curr is now the tail.
    Node* newNode = new Node(data);
    newNode->npx = XOR(curr, nullptr); // new node: XOR(curr, NULL)
    // Update tail's npx: previously it was XOR(prev, nullptr)
    curr->npx = XOR(prev, newNode);
}

// Function to insert a node at a given position in the XOR linked list
void insertAtAny(Node*& head, int data, int position) {
    if (position == 0) {
        insertAtHead(head, data);
        return;
    }
    // Traverse to node at index (position - 1)
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    int index = 0;
    while (curr && index < position - 1) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
        index++;
    }
    // If curr is nullptr, position is out-of-range.
    // Alternatively, if position equals list length, insert at end.
    if (!curr) {
        if (index == position - 1) {
            insertAtEnd(head, data);
        }
        return;
    }
    // curr is the node at (position - 1)
    next = XOR(prev, curr->npx); // node currently at position
    Node* newNode = new Node(data);
    // New node points to curr and next
    newNode->npx = XOR(curr, next);
    // Update curr's npx: originally curr->npx = XOR(prev, next)
    // New value becomes XOR(prev, newNode)
    curr->npx = XOR(prev, newNode);
    // If next exists, update its npx
    if (next) {
        // next->npx originally = XOR(curr, nextNext)
        Node* nextNext = XOR(curr, next->npx);
        // Now next's previous becomes newNode instead of curr
        next->npx = XOR(newNode, nextNext);
    }
}

// Function to delete the head node of the XOR linked list
void deleteAtHead(Node*& head) {
    if (!head) return;
    Node* next = XOR(nullptr, head->npx);
    if (next) {
        // next->npx originally = XOR(head, nextNext)
        Node* nextNext = XOR(head, next->npx);
        // Update next->npx: new previous is NULL instead of head
        next->npx = XOR(nullptr, nextNext);
    }
    delete head;
    head = next;
}

// Function to delete the last node of the XOR linked list
void deleteAtEnd(Node*& head) {
    if (!head) return;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    // Traverse until tail (next == nullptr)
    while (true) {
        next = XOR(prev, curr->npx);
        if (!next)
            break;
        prev = curr;
        curr = next;
    }
    // curr is the tail; update its previous node (if exists)
    if (prev) {
        // For prev, originally: prev->npx = XOR(prevPrev, curr)
        Node* prevPrev = XOR(curr, prev->npx);
        prev->npx = XOR(prevPrev, nullptr);
    } else {
        // Only one element existed
        head = nullptr;
    }
    delete curr;
}

// Function to delete a node at a given position in the XOR linked list
void deleteAtAny(Node*& head, int position) {
    if (!head || position < 0) return;
    if (position == 0) {
        deleteAtHead(head);
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    int index = 0;
    // Traverse to the node at the given position
    while (curr && index < position) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
        index++;
    }
    if (!curr) return; // Position invalid
    next = XOR(prev, curr->npx);
    // Update prev's npx: prev->npx was XOR(prevPrev, curr)
    Node* prevPrev = XOR(curr, prev->npx);
    prev->npx = XOR(prevPrev, next);
    if (next) {
        // For next: originally next->npx = XOR(curr, nextNext)
        Node* nextNext = XOR(curr, next->npx);
        next->npx = XOR(prev, nextNext);
    }
    delete curr;
}

// Function to delete a node with a specific value in the XOR linked list
void deleteByValue(Node*& head, int value) {
    if (!head) return;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while (curr) {
        next = XOR(prev, curr->npx);
        if (curr->data == value) {
            if (!prev) {
                // Deleting head
                if (next) {
                    Node* nextNext = XOR(curr, next->npx);
                    next->npx = XOR(nullptr, nextNext);
                }
                delete curr;
                head = next;
            } else {
                // Deleting a middle or tail node
                Node* prevPrev = XOR(curr, prev->npx);
                prev->npx = XOR(prevPrev, next);
                if (next) {
                    Node* nextNext = XOR(curr, next->npx);
                    next->npx = XOR(prev, nextNext);
                }
                delete curr;
            }
            return;
        }
        prev = curr;
        curr = next;
    }
}

// Function to reverse the XOR linked list
// For an XOR list, simply setting head to the tail reverses the traversal order.
void reverseList(Node*& head) {
    if (!head) return;
    Node* curr = head;
    Node* prev = nullptr;
    Node* next;
    while (curr) {
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }
    // prev now points to the tail, which becomes the new head.
    head = prev;
}

// Function to find the middle element of the XOR linked list using a two-pointer approach
void findMid(Node* head) {
    if (!head) {
        cout << "Mid of the linked list: nullptr" << endl;
        return;
    }
    // For XOR lists, we can simulate the two-pointer technique by keeping track of previous pointers.
    Node* slow = head;
    Node* slowPrev = nullptr;
    Node* fast = head;
    Node* fastPrev = nullptr;
    Node* fastNext;
    while (fast) {
        // Move fast one step:
        fastNext = XOR(fastPrev, fast->npx);
        if (!fastNext)
            break;
        // Move fast second step:
        Node* fastNextNext = XOR(fast, fastNext->npx);
        fastPrev = fastNext;
        fast = fastNextNext;
        // Move slow one step:
        Node* slowNext = XOR(slowPrev, slow->npx);
        slowPrev = slow;
        slow = slowNext;
    }
    if (slow)
        cout << "Mid of the linked list: " << slow->data << endl;
    else
        cout << "Mid of the linked list: nullptr" << endl;
}

// Main function demonstrating XOR linked list operations with detailed output
int main() {
    Node* head = nullptr;
    
    cout << "=== XOR Linked List Operations Demo ===" << endl << endl;
    
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
    
    // Additional test: attempt to insert at position beyond current size
    cout << "\nOperation: insertAtAny(head, 8, 10) [position beyond size, should do nothing]" << endl;
    insertAtAny(head, 8, 10);
    cout << "List after attempting to insert 8 at position 10: ";
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
