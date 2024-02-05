#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void displayList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void insertAtHead(Node*& head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }
    Node* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void insertAtAny(Node*& head, int data, int position) {
    Node* newNode = new Node(data);
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current; ++i) {
        current = current->next;
    }
    if (current) {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteAtHead(Node*& head) {
    if (!head) {
        return;
    }
    Node* newHead = head->next;
    delete head;
    head = newHead;
}

void deleteAtEnd(Node*& head) {
    if (!head) {
        return;
    }
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next->next) {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

void deleteAtAny(Node*& head, int position) {
    if (!head || position < 0) {
        return;
    }
    if (position == 0) {
        Node* newHead = head->next;
        delete head;
        head = newHead;
        return;
    }
    Node* current = head;
    for (int i = 0; i < position - 1 && current->next; ++i) {
        current = current->next;
    }
    if (current->next) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

void deleteByValue(Node*& head, int value) {
    Node* current = head;
    if (current && current->data == value) {
        Node* newHead = current->next;
        delete current;
        head = newHead;
        return;
    }
    while (current->next) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;

    while (current) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head = prev;
}

void findMid(Node* head) {
    if (!head) {
        cout << "Mid of the linked list: nullptr" << endl;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Mid of the linked list: " << slow->data << endl;
}

int main() {
    Node* head = nullptr;

    // Testing insertAtHead
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    cout << "After insertAtHead:" << endl;
    displayList(head);

    // Testing insertAtEnd
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);

    cout << "After insertAtEnd:" << endl;
    displayList(head);

    // Testing insertAtAny
    insertAtAny(head, 6, 2);

    cout << "After insertAtAny:" << endl;
    displayList(head);

    // Testing deleteAtHead
    deleteAtHead(head);

    cout << "After deleteAtHead:" << endl;
    displayList(head);

    // Testing deleteAtEnd
    deleteAtEnd(head);

    cout << "After deleteAtEnd:" << endl;
    displayList(head);

    // Testing deleteAtAny
    deleteAtAny(head, 2);

    cout << "After deleteAtAny:" << endl;
    displayList(head);

    // Testing deleteByValue
    deleteByValue(head, 4);

    cout << "After deleteByValue:" << endl;
    displayList(head);

    // Testing reverseList
    reverseList(head);

    cout << "After reverseList:" << endl;
    displayList(head);

    // Testing findMid
    findMid(head);

    // Don't forget to free memory for the entire list when done
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
