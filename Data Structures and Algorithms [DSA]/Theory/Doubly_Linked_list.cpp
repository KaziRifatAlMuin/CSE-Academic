#include <iostream>
using namespace std;

// Node class representing a single element in the doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node

    // Constructor to initialize a node with a given value
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to display the entire doubly linked list
void displayList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// Function to insert a node at the head of the doubly linked list
void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);  // Create a new node
    newNode->next = head;            // Link the new node to the current head
    newNode->prev = nullptr;         // New node is now the first element
    if (head) {
        head->prev = newNode;        // Update previous head's prev pointer
    }
    head = newNode;                  // Update the head to the new node
}

// Function to insert a node at the end of the doubly linked list
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
    current->next = newNode;   // Append the new node at the end
    newNode->prev = current;   // Set the previous pointer of the new node
}

// Function to insert a node at any given position in the doubly linked list
void insertAtAny(Node*& head, int data, int position) {
    Node* newNode = new Node(data);  // Create a new node
    // Special case for insertion at the head
    if (position == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (head) {
            head->prev = newNode;
        }
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
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

// Function to delete the head node of the doubly linked list
void deleteAtHead(Node*& head) {
    if (!head) return;  // If the list is empty, do nothing
    Node* temp = head;
    head = head->next;  // Update the head to the next node
    if (head) {
        head->prev = nullptr;  // Update the new head's prev pointer
    }
    delete temp;  // Free the memory of the old head
}

// Function to delete the last node of the doubly linked list
void deleteAtEnd(Node*& head) {
    if (!head) return;  // If the list is empty, do nothing
    // If the list has only one node, delete it
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    // Traverse to the last node
    while (current->next) {
        current = current->next;
    }
    current->prev->next = nullptr;  // Update the second-last node's next pointer
    delete current;  // Delete the last node
}

// Function to delete a node at any given position in the doubly linked list
void deleteAtAny(Node*& head, int position) {
    if (!head || position < 0) return;  // Handle invalid cases
    // Special case for deleting the head node
    if (position == 0) {
        deleteAtHead(head);
        return;
    }
    Node* current = head;
    // Traverse to the node at the given position
    for (int i = 0; i < position && current; ++i) {
        current = current->next;
    }
    // If the position is valid, delete the node
    if (current) {
        if (current->prev) {
            current->prev->next = current->next;
        }
        if (current->next) {
            current->next->prev = current->prev;
        }
        delete current;
    }
}

// Function to delete a node with a specific value
void deleteByValue(Node*& head, int value) {
    Node* current = head;
    // Traverse the list to find the node with the value
    while (current) {
        if (current->data == value) {
            if (current == head) {  // Handle the case where the head node contains the value
                head = current->next;
                if (head) {
                    head->prev = nullptr;
                }
            } else {
                if (current->prev) {
                    current->prev->next = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
            }
            delete current;
            return;
        }
        current = current->next;
    }
}

// Function to reverse the doubly linked list
void reverseList(Node*& head) {
    Node* current = head;
    Node* temp = nullptr;
    // Swap next and prev for each node in the list
    while (current) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;  // Move to the next node (which is previous before swapping)
    }
    // Update head if the list is not empty
    if (temp) {
        head = temp->prev;
    }
}

// Function to find the middle element of the doubly linked list
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

// --------------------- New Swapping Functions -------------------------

// Function to swap the values (data) between two nodes
void swapValues(Node* node1, Node* node2) {
    if (node1 && node2) {
        int temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }
}

// Function to swap two nodes in the doubly linked list by their key values
// This swaps the actual nodes (i.e. adjusts their prev and next pointers), not just the data.
void swapNodesByKey(Node*& head, int key1, int key2) {
    if (key1 == key2)
        return;

    // Find the nodes with key1 and key2.
    Node* nodeX = nullptr;
    Node* nodeY = nullptr;
    Node* current = head;
    while (current) {
        if (current->data == key1)
            nodeX = current;
        if (current->data == key2)
            nodeY = current;
        current = current->next;
    }
    // If either node is not found, do nothing.
    if (!nodeX || !nodeY)
        return;

    // If nodes are adjacent, handle separately.
    if (nodeX->next == nodeY) {
        // nodeX is immediately before nodeY.
        if (nodeX->prev)
            nodeX->prev->next = nodeY;
        else
            head = nodeY;
        if (nodeY->next)
            nodeY->next->prev = nodeX;

        nodeX->next = nodeY->next;
        nodeY->prev = nodeX->prev;

        nodeY->next = nodeX;
        nodeX->prev = nodeY;
    } else if (nodeY->next == nodeX) {
        // nodeY is immediately before nodeX.
        if (nodeY->prev)
            nodeY->prev->next = nodeX;
        else
            head = nodeX;
        if (nodeX->next)
            nodeX->next->prev = nodeY;

        nodeY->next = nodeX->next;
        nodeX->prev = nodeY->prev;

        nodeX->next = nodeY;
        nodeY->prev = nodeX;
    } else {
        // Non-adjacent nodes.
        Node* prevX = nodeX->prev;
        Node* nextX = nodeX->next;
        Node* prevY = nodeY->prev;
        Node* nextY = nodeY->next;

        // Re-link previous nodes
        if (prevX)
            prevX->next = nodeY;
        else
            head = nodeY;
        if (prevY)
            prevY->next = nodeX;
        else
            head = nodeX;

        // Re-link next nodes
        if (nextX)
            nextX->prev = nodeY;
        if (nextY)
            nextY->prev = nodeX;

        // Swap prev and next pointers
        nodeX->prev = prevY;
        nodeX->next = nextY;
        nodeY->prev = prevX;
        nodeY->next = nextX;
    }
}

// --------------------- Main Function -------------------------

int main() {
    Node* head = nullptr;

    cout << "=== Doubly Linked List Operations Demo ===" << endl << endl;

    // Basic Insertion Tests
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

    // Deletion Tests
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

    // Reversal and Middle Element Tests
    cout << "\nOperation: reverseList(head)" << endl;
    reverseList(head);
    cout << "List after reversing: ";
    displayList(head);

    cout << "\nOperation: findMid(head)" << endl;
    findMid(head);

    // Additional Sequence Test
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

    // -------------------- Swapping Functions Testing --------------------
    cout << "\n=== Swapping Functions Test ===" << endl;
    // Create a new list for swapping tests.
    Node* swapList = nullptr;
    insertAtEnd(swapList, 100);
    insertAtEnd(swapList, 200);
    insertAtEnd(swapList, 300);
    insertAtEnd(swapList, 400);
    cout << "List before swapping data (swapValues): ";
    displayList(swapList);
    // Swap the data of the first node and the third node.
    Node* first = swapList;
    Node* third = swapList->next->next;  // third node (index 2)
    swapValues(first, third);
    cout << "List after swapping data of first and third nodes: ";
    displayList(swapList);

    // Test swapping nodes by key (actual pointer swap).
    cout << "\nList before swapping nodes by key (swapNodesByKey): ";
    displayList(swapList);
    // Swap nodes with values 200 and 400.
    swapNodesByKey(swapList, 200, 400);
    cout << "List after swapping nodes with values 200 and 400: ";
    displayList(swapList);

    // Cleanup: Free all nodes in swapList.
    while (swapList) {
        Node* temp = swapList;
        swapList = swapList->next;
        delete temp;
    }

    // Cleanup: Free all nodes in the main list.
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "\nAll nodes deleted. End of operations." << endl;

    return 0;
}
