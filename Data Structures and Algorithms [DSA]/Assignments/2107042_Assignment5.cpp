#include <iostream>
#include "2107042_Assignment5.h"

using namespace std;

int main() {
    // Testing Deque
    cout << "Testing Deque:" << endl;
    Deque<int> deque;

    cout << "Is deque empty? " << (deque.empty() ? "Yes" : "No") << endl; // Output: Yes

    deque.push_back(1);
    deque.push_back(2);
    deque.push_front(3);

    cout << "Deque elements: ";
    deque.display(); // Output: 3 1 2

    cout << "Size: " << deque.size() << endl; // Output: 3

    deque.pop_front();
    deque.pop_back();

    cout << "After popping front and back: ";
    deque.display(); // Output: 1

    cout << "Is deque empty? " << (deque.empty() ? "Yes" : "No") << endl; // Output: No
    cout << endl;

    // Testing Queue
    cout << "Testing Queue:" << endl;
    Queue<int> queue;

    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: Yes

    queue.push(4);
    queue.push(5);

    cout << "Queue elements: ";
    queue.display(); // Output: 4 5

    cout << "Size: " << queue.size() << endl; // Output: 2

    queue.pop();

    cout << "After popping from queue: ";
    queue.display(); // Output: 5

    cout << "Is queue empty? " << (queue.empty() ? "Yes" : "No") << endl; // Output: No
    cout << endl;

    // Testing Stack
    cout << "Testing Stack:" << endl;
    Stack<int> stack;

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: Yes

    stack.push(6);
    stack.push(7);

    cout << "Stack elements: ";
    stack.display(); // Output: 7 6

    cout << "Size: " << stack.size() << endl; // Output: 2

    stack.pop();

    cout << "After popping from stack: ";
    stack.display(); // Output: 6

    cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: No
    cout << endl;

    // Additional Testing
    cout << "Additional Testing:" << endl;
    // Testing empty Deque
    Deque<double> emptyDeque;
    cout << "Is empty deque really empty? " << (emptyDeque.empty() ? "Yes" : "No") << endl; // Output: Yes

    // Testing empty Queue
    Queue<char> emptyQueue;
    cout << "Is empty queue really empty? " << (emptyQueue.empty() ? "Yes" : "No") << endl; // Output: Yes

    // Testing empty Stack
    Stack<string> emptyStack;
    cout << "Is empty stack really empty? " << (emptyStack.empty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}

