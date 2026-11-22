#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results:

    ========================================
    🧪 Test Case 1: Mixed values, x = 5
    ----------------------------------------
    BEFORE: 3 <-> 8 <-> 5 <-> 10 <-> 2 <-> 1
    AFTER:  3 <-> 2 <-> 1 <-> 8 <-> 5 <-> 10

    ========================================
    🧪 Test Case 2: All values < x (x = 5)
    ----------------------------------------
    BEFORE: 1 <-> 2 <-> 3
    AFTER:  1 <-> 2 <-> 3

    ========================================
    🧪 Test Case 3: All values >= x (x = 5)
    ----------------------------------------
    BEFORE: 6 <-> 7 <-> 8
    AFTER:  6 <-> 7 <-> 8

    ========================================
    🧪 Test Case 4: Empty list
    ----------------------------------------
    BEFORE: empty
    AFTER:  empty

    ========================================
    🧪 Test Case 5: One node (x = 5)
    ----------------------------------------
    BEFORE: 1
    AFTER:  1

    ========================================
    🧪 Test Case 6: Ensure 'prev' property is set for 2nd list, x = 5 | 
    ----------------------------------------
    BEFORE: 3 <-> 8 <-> 5 <-> 10 <-> 2 <-> 4 <-> 11
    AFTER:  3 <-> 2 <-> 4 <-> 8 <-> 5 <-> 10 <-> 11
    Expected Middle Node -> 'prev': 4
    Actual Middle Node -> 'prev': 4

*/

static void test() {
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 1: Mixed values, x = 5";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll1(3);
    dll1.append(8);
    dll1.append(5);
    dll1.append(10);
    dll1.append(2);
    dll1.append(1);
    cout << "BEFORE: ";
    dll1.printList();
    dll1.partitionList(5);
    cout << "AFTER:  ";
    dll1.printList();
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 2: All values < x (x = 5)";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll2(1);
    dll2.append(2);
    dll2.append(3);
    cout << "BEFORE: ";
    dll2.printList();
    dll2.partitionList(5);
    cout << "AFTER:  ";
    dll2.printList();
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 3: All values >= x (x = 5)";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll3(6);
    dll3.append(7);
    dll3.append(8);
    cout << "BEFORE: ";
    dll3.printList();
    dll3.partitionList(5);
    cout << "AFTER:  ";
    dll3.printList();
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 4: Empty list";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll4(1);
    dll4.makeEmpty();
    cout << "BEFORE: ";
    dll4.printList();
    dll4.partitionList(5);
    cout << "AFTER:  ";
    dll4.printList();
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 5: One node (x = 5)";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll5(1);
    cout << "BEFORE: ";
    dll5.printList();
    dll5.partitionList(5);
    cout << "AFTER:  ";
    dll5.printList();
    
    cout << "\n========================================";
    cout << "\n🧪 Test Case 6: Ensure 'prev' property is set for 2nd list, x = 5 | ";
    cout << "\n----------------------------------------\n";
    DoublyLinkedList dll6(3);
    dll6.append(8);
    dll6.append(5);
    dll6.append(10);
    dll6.append(2);
    dll6.append(4);
    dll6.append(11);
    cout << "BEFORE: ";
    dll6.printList();
    dll6.partitionList(5);
    cout << "AFTER:  ";
    dll6.printList();
    cout << "Expected Middle Node -> 'prev': 4" << endl;
    cout << "Actual Middle Node -> 'prev': " << dll6.getMiddle()->prev->value << endl;
}

int main() {
    test();
    return 0;
}
