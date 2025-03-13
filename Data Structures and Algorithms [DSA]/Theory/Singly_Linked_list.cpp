#include <iostream>
using namespace std;

// Node class representing a single element in the linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node

    // Constructor to initialize a node with a given value
    Node(int value) : data(value), next(nullptr) {}
};

// --------------------- Basic Operations -------------------------

// Function to display the entire linked list
void displayList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node at the head of the linked list
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);  // Create a new node
    newNode->next = head;            // Link the new node to the current head
    head = newNode;                  // Update the head to the new node
}

// Function to insert a node at the end of the linked list
void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);  // Create a new node
    // If the list is empty, make the new node the head
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    // Traverse to the last node
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;  // Append the new node at the end
}

// Function to insert a node at any given position in the linked list
void insertAtAny(Node*& head, int data, int position) {
    Node* newNode = new Node(data);  // Create a new node
    // Special case for insertion at the head
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    // Traverse to the node just before the given position
    for (int i = 0; i < position - 1 && current; ++i) {
        current = current->next;
    }
    // If the position is valid, insert the new node
    if (current) {
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to delete the head node of the linked list
void deleteAtHead(Node*& head) {
    if (!head) return;  // If the list is empty, do nothing
    Node* newHead = head->next;
    delete head;        // Free the memory of the old head
    head = newHead;     // Update the head to the next node
}

// Function to delete the last node of the linked list
void deleteAtEnd(Node*& head) {
    if (!head) return;  // If the list is empty, do nothing
    // If the list has only one node, delete it
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    // Traverse to the second-last node
    while (current->next->next) {
        current = current->next;
    }
    delete current->next;      // Delete the last node
    current->next = nullptr;   // Set the next pointer to nullptr
}

// Function to delete a node at any given position in the linked list
void deleteAtAny(Node*& head, int position) {
    if (!head || position < 0) return;  // Handle invalid cases
    // Special case for deleting the head node
    if (position == 0) {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return;
    }
    Node* current = head;
    // Traverse to the node just before the given position
    for (int i = 0; i < position - 1 && current->next; ++i) {
        current = current->next;
    }
    // If the position is valid, delete the node
    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

// Function to delete a node with a specific value
void deleteByValue(Node*& head, int value) {
    Node* current = head;
    // Handle the case where the head node contains the value
    if (current && current->data == value) {
        Node* newHead = current->next;
        delete current;
        head = newHead;
        return;
    }
    // Traverse the list to find the node with the value
    while (current && current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    // Reverse the pointers in the list
    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    head = prev;  // Update the head to the new front
}

// Function to find the middle element of the linked list
void findMid(Node* head) {
    if (!head) {
        cout << "Mid of the linked list: nullptr" << endl;
        return;
    }
    Node* slow = head;
    Node* fast = head;

    // Fast pointer moves twice as fast as slow
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Mid of the linked list: " << slow->data << endl;
}

// --------------------- New Functions -------------------------

// Floyd's Cycle Detection: returns the meeting point if a cycle exists, or nullptr if not.
Node* detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;  // Cycle detected
    }
    return nullptr; // No cycle
}

// Function to count the length of the cycle given the meeting point
int countCycleLength(Node* meetingNode) {
    if (!meetingNode) return 0;
    int count = 1;
    Node* current = meetingNode->next;
    while (current != meetingNode) {
        count++;
        current = current->next;
    }
    return count;
}

// Function to swap the values between two nodes (swaps data only)
void swapValues(Node* node1, Node* node2) {
    if (node1 && node2) {
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
}

// Function to swap two nodes in the linked list by their key values.
// This swaps the actual nodes (their pointers in the list) rather than just their data.
void swapNodesByKey(Node*& head, int key1, int key2) {
    if (key1 == key2) return;
    
    Node *prevX = nullptr, *currX = head;
    while (currX && currX->data != key1) {
        prevX = currX;
        currX = currX->next;
    }
    
    Node *prevY = nullptr, *currY = head;
    while (currY && currY->data != key2) {
        prevY = currY;
        currY = currY->next;
    }
    
    // If either key is not present, do nothing
    if (!currX || !currY)
        return;
    
    // If currX is not head, update its previous node's next pointer
    if (prevX)
        prevX->next = currY;
    else
        head = currY;
    
    // If currY is not head, update its previous node's next pointer
    if (prevY)
        prevY->next = currX;
    else
        head = currX;
    
    // Swap next pointers of currX and currY
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;
}

// --------------------- Main Function -------------------------

int main() {
    Node* head = nullptr;

    cout << "=== Linked List Operations Demo ===" << endl << endl;

    // Basic Operations Tests
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

    cout << "\nOperation: insertAtEnd(head, 4)" << endl;
    insertAtEnd(head, 4);
    cout << "List after inserting 4 at end: ";
    displayList(head);

    cout << "Operation: insertAtEnd(head, 5)" << endl;
    insertAtEnd(head, 5);
    cout << "List after inserting 5 at end: ";
    displayList(head);

    cout << "\nOperation: insertAtAny(head, 6, 2)" << endl;
    insertAtAny(head, 6, 2);
    cout << "List after inserting 6 at position 2: ";
    displayList(head);

    cout << "\nOperation: insertAtAny(head, 7, 0) [should act like insertAtHead]" << endl;
    insertAtAny(head, 7, 0);
    cout << "List after inserting 7 at position 0: ";
    displayList(head);

    cout << "\nOperation: insertAtAny(head, 8, 10) [position beyond size, should do nothing]" << endl;
    insertAtAny(head, 8, 10);
    cout << "List after attempting to insert 8 at position 10: ";
    displayList(head);

    cout << "\nOperation: deleteAtHead(head)" << endl;
    deleteAtHead(head);
    cout << "List after deleting head: ";
    displayList(head);

    cout << "\nOperation: deleteAtEnd(head)" << endl;
    deleteAtEnd(head);
    cout << "List after deleting end: ";
    displayList(head);

    cout << "\nOperation: deleteAtAny(head, 2) [deleting node at index 2]" << endl;
    deleteAtAny(head, 2);
    cout << "List after deleting node at position 2: ";
    displayList(head);

    cout << "\nOperation: deleteByValue(head, 4)" << endl;
    deleteByValue(head, 4);
    cout << "List after deleting node with value 4: ";
    displayList(head);

    cout << "\nOperation: deleteByValue(head, 100) [value not in list]" << endl;
    deleteByValue(head, 100);
    cout << "List after attempting to delete node with value 100: ";
    displayList(head);

    cout << "\nOperation: reverseList(head)" << endl;
    reverseList(head);
    cout << "List after reversing: ";
    displayList(head);

    cout << "\nOperation: findMid(head)" << endl;
    findMid(head);

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

    // Free memory for basic list
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nAll nodes deleted. End of basic operations." << endl;

    // -------------------- Cycle Detection & Cycle Length Test --------------------
    cout << "\n=== Cycle Detection and Cycle Length Test ===" << endl;
    Node* cycleHead = nullptr;
    // Create a new list for cycle test
    insertAtEnd(cycleHead, 1);
    insertAtEnd(cycleHead, 2);
    insertAtEnd(cycleHead, 3);
    insertAtEnd(cycleHead, 4);
    insertAtEnd(cycleHead, 5);
    cout << "List before creating cycle: ";
    displayList(cycleHead);

    // Create a cycle: link the last node to the node at index 2
    Node* last = cycleHead;
    while (last->next) {
        last = last->next;
    }
    Node* cycleEntry = cycleHead;
    for (int i = 0; i < 2; i++) {
        cycleEntry = cycleEntry->next;
    }
    last->next = cycleEntry;  // Create cycle

    // Detect cycle using Floyd's algorithm
    Node* meetingPoint = detectCycle(cycleHead);
    if (meetingPoint) {
        cout << "Cycle detected at node with value: " << meetingPoint->data << endl;
        int cycleLen = countCycleLength(meetingPoint);
        cout << "Cycle length is: " << cycleLen << endl;
    } else {
        cout << "No cycle detected." << endl;
    }

    // Break the cycle for cleanup
    last->next = nullptr;
    while (cycleHead) {
        Node* temp = cycleHead;
        cycleHead = cycleHead->next;
        delete temp;
    }

    // -------------------- Value Swapping Test --------------------
    cout << "\n=== Value Swapping Test (Data Swap) ===" << endl;
    Node* swapHead = nullptr;
    insertAtEnd(swapHead, 100);
    insertAtEnd(swapHead, 200);
    insertAtEnd(swapHead, 300);
    insertAtEnd(swapHead, 400);
    cout << "List before swapping values: ";
    displayList(swapHead);
    // Swap the data of the first node and the third node
    Node* first = swapHead;
    Node* third = swapHead->next->next;  // third node (index 2)
    swapValues(first, third);
    cout << "List after swapping data of first and third nodes: ";
    displayList(swapHead);
    while (swapHead) {
        Node* temp = swapHead;
        swapHead = swapHead->next;
        delete temp;
    }

    // -------------------- Node Swapping Test --------------------
    cout << "\n=== Node Swapping Test (Pointer Swap) ===" << endl;
    Node* swapList = nullptr;
    insertAtEnd(swapList, 10);
    insertAtEnd(swapList, 20);
    insertAtEnd(swapList, 30);
    insertAtEnd(swapList, 40);
    cout << "List before swapping nodes: ";
    displayList(swapList);
    // Swap the actual nodes with values 20 and 40 (swapping pointers)
    swapNodesByKey(swapList, 20, 40);
    cout << "List after swapping nodes with values 20 and 40: ";
    displayList(swapList);
    while (swapList) {
        Node* temp = swapList;
        swapList = swapList->next;
        delete temp;
    }

    return 0;
}
