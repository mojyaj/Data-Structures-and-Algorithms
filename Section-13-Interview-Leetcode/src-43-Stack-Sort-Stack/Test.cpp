#include <iostream>
#include "Test.h"
#include "SortStack.cpp" // need this to debug in visual studio code

using namespace std;

// Test Results at page bottom

void test() {
    cout << "\n----- Test: Empty Stack -----\n";
    {
        stack<int> s;
        sortStack(s);
        cout << "Stack is " << (s.empty() ? "empty" : "not empty") << " - EXPECTED: empty\n";
        cout << (s.empty() ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Single Element -----\n";
    {
        stack<int> s;
        s.push(42);
        sortStack(s);
        cout << "Top element: " << s.top() << " - EXPECTED: 42\n";
        printstack(s);
        cout << (s.top() == 42 ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Already Sorted -----\n";
    {
        stack<int> s;
        s.push(3);
        s.push(2);
        s.push(1);
        sortStack(s);
        printstack(s);
        int expected[] = {1, 2, 3};
        bool pass = true;
        for (int i : expected) {
            if (s.top() != i) {
                pass = false;
                break;
            }
            s.pop();
        }
        printstack(s);
        cout << (pass ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Unsorted Stack -----\n";
    {
        stack<int> s;
        s.push(1);
        s.push(3);
        s.push(2);
        s.push(4);
        s.push(6);
        s.push(7);
        s.push(5);
        s.push(8);
        sortStack(s);
        printstack(s);
        int expected[] = {1, 2, 3,4,5,6,7,8};
        bool pass = true;
        for (int i : expected) {
            if (s.top() != i) {
                pass = false;
                break;
            }
            s.pop();
        }
        cout << (pass ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: All Equal Elements -----\n";
    {
        stack<int> s;
        s.push(5);
        s.push(5);
        s.push(5);
        sortStack(s);
        bool pass = true;
        while (!s.empty() && pass) {
            if (s.top() != 5) {
                pass = false;
            }
            s.pop();
        }
        printstack(s);
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
    return 0;
}

/* Test Results:

    ----- Test: Empty Stack -----
    Stack is empty - EXPECTED: empty
    PASS

    ----- Test: Single Element -----
    Top element: 42 - EXPECTED: 42
    42
    PASS

    ----- Test: Already Sorted -----
    1
    2
    3
    PASS

    ----- Test: Unsorted Stack -----
    1
    2
    3
    4
    5
    6
    7
    8
    PASS

    ----- Test: All Equal Elements -----
    PASS
*/

/* 
    EXPECTED OUTPUT:
    ----- Test: Empty Stack -----
    Stack is empty - EXPECTED: empty
    PASS
    ----- Test: Single Element -----
    Top element: 42 - EXPECTED: 42
    PASS
    ----- Test: Already Sorted -----
    PASS
    ----- Test: Unsorted Stack -----
    PASS
    ----- Test: All Equal Elements -----
    PASS

*/
