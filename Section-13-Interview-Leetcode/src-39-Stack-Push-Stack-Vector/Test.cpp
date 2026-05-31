#include <iostream>
#include "Stack.cpp"

using namespace std;

/* Test Results:
    ----- Test: Push to Empty Stack -----
    Initial state: empty stack
    Pushing value of 10 to an empty stack:
    Peek result: 10 - EXPECTED: 10
    Size: 1 - EXPECTED: 1
    PASS

    ----- Test: Push to Non-Empty Stack -----
    Pushing value of 10 to an empty stack:
    Pushing value of 20 to a stack with one element:
    Peek result: 20 - EXPECTED: 20
    Size: 2 - EXPECTED: 2
    PASS

    ----- Test: Multiple Pushes -----
    Pushing value of 10 to an empty stack:
    Pushing value of 20 to a stack with one element:
    Pushing value of 30 to a stack with two elements:
    Peek result: 30 - EXPECTED: 30
    Size: 3 - EXPECTED: 3
    PASS
*/

static void test() {
    cout << "\n----- Test: Push to Empty Stack -----\n";
    {
        Stack stack;
        cout << "Initial state: empty stack\n";
        cout << "Pushing value of 10 to an empty stack:\n";
        stack.push(10);
        cout << "Peek result: " << stack.peek() << " - EXPECTED: 10\n";
        cout << "Size: " << stack.size() << " - EXPECTED: 1\n";
        cout << (stack.peek() == 10 && stack.size() == 1 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Push to Non-Empty Stack -----\n";
    {
        Stack stack;
        cout << "Pushing value of 10 to an empty stack:\n";
        stack.push(10);
        cout << "Pushing value of 20 to a stack with one element:\n";
        stack.push(20);
        cout << "Peek result: " << stack.peek() << " - EXPECTED: 20\n";
        cout << "Size: " << stack.size() << " - EXPECTED: 2\n";
        cout << (stack.peek() == 20 && stack.size() == 2 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Multiple Pushes -----\n";
    {
        Stack stack;
        cout << "Pushing value of 10 to an empty stack:\n";
        stack.push(10);
        cout << "Pushing value of 20 to a stack with one element:\n";
        stack.push(20);
        cout << "Pushing value of 30 to a stack with two elements:\n";
        stack.push(30);
        cout << "Peek result: " << stack.peek() << " - EXPECTED: 30\n";
        cout << "Size: " << stack.size() << " - EXPECTED: 3\n";
        cout << (stack.peek() == 30 && stack.size() == 3 ? "PASS\n" : "FAIL\n");
    }
    
}

int main() {
    test();
    return 0;
}
