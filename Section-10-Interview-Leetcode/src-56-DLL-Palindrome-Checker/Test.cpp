#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results:

    ----- Test: Is Palindrome with Single Node -----
    DLL:
    1
    Is Palindrome: true - EXPECTED: true
    PASS

    ----- Test: Is Palindrome with Two Nodes -----
    DLL (equal values):
    1 <-> 1
    Is Palindrome: true - EXPECTED: true
    PASS

    DLL (different values):
    1 <-> 2
    Is Palindrome: false - EXPECTED: false
    PASS

    ----- Test: Is Palindrome with Multiple Nodes -----
    DLL (palindrome):
    1 <-> 2 <-> 3 <-> 2 <-> 1
    Is Palindrome: true - EXPECTED: true
    PASS

    DLL (not palindrome):
    1 <-> 2 <-> 3 <-> 3 <-> 2
    Is Palindrome: false - EXPECTED: false
    PASS

*/

static void test() {

    // Test: Is Palindrome with Single Node
    {
        cout << "\n----- Test: Is Palindrome with Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL:\n";
        list.printList();
        bool result = list.isPalindrome();
        cout << "Is Palindrome: " << (result ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result ? "PASS\n" : "FAIL\n");
    }

    // Test: Is Palindrome with Two Nodes
    {
        cout << "\n----- Test: Is Palindrome with Two Nodes -----\n";

        DoublyLinkedList list(1);
        list.append(1);
        cout << "DLL (equal values):\n";
        list.printList();
        bool result1 = list.isPalindrome();
        cout << "Is Palindrome: " << (result1 ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result1 ? "PASS\n" : "FAIL\n");

        DoublyLinkedList list2(1);
        list2.append(2);
        cout << "\nDLL (different values):\n";
        list2.printList();
        bool result2 = list2.isPalindrome();
        cout << "Is Palindrome: " << (result2 ? "true" : "false") << " - EXPECTED: false\n";
        cout << (result2 ? "FAIL\n" : "PASS\n");
    }

    // Test: Is Palindrome with Multiple Nodes
    {
        cout << "\n----- Test: Is Palindrome with Multiple Nodes -----\n";

        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(2);
        list.append(1);
        cout << "DLL (palindrome):\n";
        list.printList();
        bool result1 = list.isPalindrome();
        cout << "Is Palindrome: " << (result1 ? "true" : "false") << " - EXPECTED: true\n";
        cout << (result1 ? "PASS\n" : "FAIL\n");

        DoublyLinkedList list2(1);
        list2.append(2);
        list2.append(3);
        list2.append(3);
        list2.append(2);
        cout << "\nDLL (not palindrome):\n";
        list2.printList();
        bool result2 = list2.isPalindrome();
        cout << "Is Palindrome: " << (result2 ? "true" : "false") << " - EXPECTED: false\n";
        cout << (result2 ? "FAIL\n" : "PASS\n");
    }
    
}

int main() {
    test();
    return 0;
}