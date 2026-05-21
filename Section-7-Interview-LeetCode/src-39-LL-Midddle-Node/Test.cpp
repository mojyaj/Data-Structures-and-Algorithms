#include <iostream>
#include "LinkedList.cpp"

using namespace std;

/*  Test Results:

    ------ LinkedList Test: EmptyList ------
    empty
    Middle node: 0 (nullptr)
    PASS
    ------ LinkedList Test: SingleElement ------
    1
    Middle node: 1
    PASS
    ------ LinkedList Test: EvenNumberOfElements ------
    1 -> 2 -> 3 -> 4
    Middle node: 3
    PASS
    ------ LinkedList Test: OddNumberOfElements ------
    1 -> 2 -> 3
    Middle node: 2
    PASS
*/

/*
    LL: Find Middle Node ( ** Interview Question)
    Implement a member function, findMiddleNode(), which finds and returns the middle node of the linked list.

    Note: this LinkedList implementation does not have a length member variable.

    Function Signature:

    Node* findMiddleNode();

    Input:

    The linked list can have any number of nodes (0 to n).
    Node values are integers.

    Output:
    Return a pointer to the middle node of the linked list.
    If the list has an even number of nodes, return the second middle node (the one closer to the end).

    Constraints:
    You are not allowed to use any additional data structures (such as arrays) or modify the existing data structure.
    You can only traverse the linked list once.

    Example:
    Suppose you have a LinkedList object, list, with the following values:
    1 -> 2 -> 3 -> 4 -> 5


    After calling the findMiddleNode() function:
    Node* middle = list.findMiddleNode();

    The middle pointer should point to the node with value 3.

    Now suppose you have a LinkedList object, list, with the following values:
    1 -> 2 -> 3 -> 4 -> 5 -> 6

    After calling the findMiddleNode() function:

    Node* middle = list.findMiddleNode();

    The middle pointer should point to the node with value 4.
*/

static void test() {
    // Function to convert nullptr to "0 (nullptr)"
    auto ptrToNum = [](Node* ptr) -> string {
        return (ptr == nullptr) ? "0 (nullptr)" : to_string(ptr->value);
    };

    // Helper function to check test result
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: EmptyList
    {
        cout << "\n------ LinkedList Test: EmptyList ------\n";

        LinkedList list(1);
        list.makeEmpty();
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle == nullptr);
    }

    // Test: SingleElement
    {
        cout << "\n------ LinkedList Test: SingleElement ------\n";
        
        LinkedList list(1);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle == list.getHead());
    }

    // Test: EvenNumberOfElements
    {
        cout << "\n------ LinkedList Test: EvenNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;

        checkTestResult(middle->value == 3);
    }

    // Test: OddNumberOfElements
    {
        cout << "\n------ LinkedList Test: OddNumberOfElements ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        list.printList();
        
        Node* middle = list.findMiddleNode();
        
        cout << "Middle node: " << ptrToNum(middle) << endl;
        
        checkTestResult(middle->value == 2);
    }
}


