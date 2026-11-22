#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results:

    ----- Test: Swap Pairs with Single Node -----
    DLL before swapping pairs:
    1

    DLL after swapping pairs:
    1
    Head value after swapping pairs: 1 - EXPECTED: 1
    PASS

    ----- Test: Swap Pairs with Two Nodes -----
    DLL before swapping pairs:
    1 <-> 2

    DLL after swapping pairs:
    2 <-> 1
    Head value after swapping pairs: 2 - EXPECTED: 2
    Next value after swapping pairs: 1 - EXPECTED: 1
    PASS

    ----- Test: Swap Pairs with Multiple Nodes -----
    DLL before swapping pairs:
    1 <-> 2 <-> 3 <-> 4 <-> 5

    DLL after swapping pairs:
    2 <-> 1 <-> 4 <-> 3 <-> 5
    PASS

*/

static void test() {

    // Test: Swap Pairs with Single Node
    {
        cout << "\n----- Test: Swap Pairs with Single Node -----\n";
        DoublyLinkedList list(1);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        int value = list.getHead()->value;
        cout << "Head value after swapping pairs: " << value << " - EXPECTED: 1\n";
        cout << (value == 1 ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap Pairs with Two Nodes
    {
        cout << "\n----- Test: Swap Pairs with Two Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        int headValue = list.getHead()->value;
        int nextValue = list.getHead()->next->value;
        cout << "Head value after swapping pairs: " << headValue << " - EXPECTED: 2\n";
        cout << "Next value after swapping pairs: " << nextValue << " - EXPECTED: 1\n";
        cout << (headValue == 2 && nextValue == 1 ? "PASS\n" : "FAIL\n");
    }

    // Test: Swap Pairs with Multiple Nodes
    {
        cout << "\n----- Test: Swap Pairs with Multiple Nodes -----\n";
        DoublyLinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        cout << "DLL before swapping pairs:\n";
        list.printList();
        list.swapPairs();
        cout << "\nDLL after swapping pairs:\n";
        list.printList();
        //cout << "PASS/FAIL test: "; 
        cout << (list.getHead()->value == 2 && 
                 list.getHead()->next->value == 1 && 
                 list.getHead()->next->next->value == 4 && 
                 list.getHead()->next->next->next->value == 3 && 
                 list.getHead()->next->next->next->next->value == 5 ? "PASS\n" : "FAIL\n"); 
    }
}

int main() {
    test();
    return 0;
}

