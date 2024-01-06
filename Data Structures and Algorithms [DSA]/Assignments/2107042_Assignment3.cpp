/*
	Name : Kazi Rifat Al Muin
	Roll : 2107042
	Assignment No : 03
	Topic : Linked List Basic Functions
*/

#include "2107042_Assignment3.h"

int main() {
    LinkedList<int> myList; // Example for integer data type

    // Insert nodes at the front
    myList.insertFront(10);
    myList.insertFront(20);
    myList.insertFront(30);

    // Display the linked list
    cout << "Linked List: ";
    myList.display();

    // Insert nodes at the end
    myList.insertEnd(40);
    myList.insertEnd(50);

    // Display the linked list
    cout << "Linked List after inserting at the end: ";
    myList.display();

    // Insert at a specific position
    myList.insertAtPosition(2, 25);

    // Display the linked list
    cout << "Linked List after inserting at position 2: ";
    myList.display();

    myList.insertAtPosition(4, 35);
    cout << "Linked List after inserting at position 4: ";
    myList.display();

    // Search for a value
    if (myList.search(40)) {
        cout << "Value 40 found in the linked list." << endl;
    } else {
        cout << "Value 40 not found in the linked list." << endl;
    }
    if (myList.search(45)) {
        cout << "Value 45 found in the linked list." << endl;
    } else {
        cout << "Value 45 not found in the linked list." << endl;
    }

    // Get the length of the linked list
    cout << "Length of the linked list: " << myList.getLength() << endl;

    return 0;
}