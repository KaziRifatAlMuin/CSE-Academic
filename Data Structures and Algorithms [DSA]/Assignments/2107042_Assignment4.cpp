#include "2107042_Assignment4.h"
#include <iostream>

using namespace std;

int main() {
    // Create a Doubly Linked List with integers
    DoublyLinkedList<int> myList;

    // Insert values at the beginning of the list
    myList.insertBegin(5);
    myList.insertBegin(10);
    myList.insertBegin(15);
    myList.insertBegin(20);
    myList.insertBegin(20);

    // Display the list after insertBegin
    cout << "List after insertBegin: ";
    myList.display();

    // Insert values at the end of the list

    myList.insertEnd(20);
    myList.insertEnd(25);
    myList.insertEnd(30);


    // Display the list after insertEnd
    cout << "List after insertEnd: ";
    myList.display();

    // Insert a value at a specific position in the list
    myList.insertAtPosition(3, 35);

    // Display the list after insertAtPosition
    cout << "List after insertAtPosition(3, 35): ";
    myList.display();

    // Delete the node at the beginning of the list
    myList.deleteBegin();

    // Display the list after deleteBegin
    cout << "List after deleteBegin: ";
    myList.display();

    // Delete the node at the end of the list
    myList.deleteEnd();

    // Display the list after deleteEnd
    cout << "List after deleteEnd: ";
    myList.display();

    // Delete the node at a specific position in the list
    myList.deleteAtPosition(2);

    // Display the list after deleteAtPosition
    cout << "List after deleteAtPosition(2): ";
    myList.display();

    // Delete nodes with a specific value from the list
    myList.deleteByValue(20);

    // Display the list after deleteByValue
    cout << "List after deleteByValue(20): ";
    myList.display();

    // Perform QuickSort on the list
    myList.quickSort();

    // Display the list after quickSort
    cout << "List after quickSort: ";
    myList.display();

    // Perform MergeSort on the list
    myList.mergeSort();

    // Display the list after mergeSort
    cout << "List after mergeSort: ";
    myList.display();

    // Get the length of the list
    cout << "Length of the List: " << myList.getLength() << endl;

    // Insert more values for additional testing
    myList.insertEnd(8);
    myList.insertBegin(2);

    // Display the list after additional insertions
    cout << "List after additional insertions: ";
    myList.display();

    return 0;
}