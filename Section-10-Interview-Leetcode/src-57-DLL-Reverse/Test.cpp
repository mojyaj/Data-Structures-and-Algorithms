
#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"

using namespace std;
using std::to_string;

/*  Test Results:
    ----- Test: Reverse Single Node -----
    DLL before reversing:
    1
    DLL after reversing:
    1
    Head value after reversing: 1 - EXPECTED: 1
    Tail value after reversing: 1 - EXPECTED: 1
    PASS

    ----- Test: Reverse Two Nodes -----
    DLL before reversing:
    1 <-> 2
    DLL after reversing:
    2 <-> 1
    Head value after reversing: 2 - EXPECTED: 2
    Tail value after reversing: 1 - EXPECTED: 1
    PASS

    ----- Test: Reverse Multiple Nodes -----
    DLL before reversing:
    1 <-> 2 <-> 3 <-> 4
    DLL after reversing:
    4 <-> 3 <-> 2 <-> 1
    Head value after reversing: 4 - EXPECTED: 4
    Tail value after reversing: 1 - EXPECTED: 1
    Value after head after reversing: 3 - EXPECTED: 3
    Value before tail after reversing: 2 - EXPECTED: 2
    PASS

    ----- Test: Reverse Multiple with Odd Number of Nodes -----
    DLL before reversing:
    1 <-> 2 <-> 3 <-> 4 <-> 5
    DLL after reversing:
    5 <-> 4 <-> 3 <-> 2 <-> 1
    Head value after reversing: 5 - EXPECTED: 5
    Tail value after reversing: 1 - EXPECTED: 1
    Value after head after reversing: 4 - EXPECTED: 4
    Value before tail after reversing: 2 - EXPECTED: 2
    PASS
*/

static void test() {

    // Test: Reverse Single Node
    {
        cout << "\n----- Test: Reverse Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 1\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 1 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Reverse Two Nodes
    {
        cout << "\n----- Test: Reverse Two Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 2\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << ((headValue == 2 && tailValue == 1) ? "PASS\n" : "FAIL\n");
    }

    // Test: Reverse Multiple Nodes
    {
        cout << "\n----- Test: Reverse Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        int headNextValue = list.getHead()->next->value;
        int tailPrevValue = list.getTail()->prev->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 4\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << "Value after head after reversing: " << headNextValue << " - EXPECTED: 3\n";
        cout << "Value before tail after reversing: " << tailPrevValue << " - EXPECTED: 2\n";
        bool pass = headValue == 4 && tailValue == 1 && headNextValue == 3 && tailPrevValue == 2;
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
    
    // Test: Reverse Multiple with Odd Number of Nodes
    {
        cout << "\n----- Test: Reverse Multiple with Odd Number of Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        cout << "DLL before reversing:\n";
        list.printList();
        list.reverse();
        cout << "DLL after reversing:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int tailValue = list.getTail()->value;
        int headNextValue = list.getHead()->next->value;
        int tailPrevValue = list.getTail()->prev->value;
        cout << "Head value after reversing: " << headValue << " - EXPECTED: 5\n";
        cout << "Tail value after reversing: " << tailValue << " - EXPECTED: 1\n";
        cout << "Value after head after reversing: " << headNextValue << " - EXPECTED: 4\n";
        cout << "Value before tail after reversing: " << tailPrevValue << " - EXPECTED: 2\n";
        bool pass = headValue == 5 && tailValue == 1 && headNextValue == 4 && tailPrevValue == 2;
        cout << (pass ? "PASS\n" : "FAIL\n");
    }
}

int main() {
    test();
    return 0;
}