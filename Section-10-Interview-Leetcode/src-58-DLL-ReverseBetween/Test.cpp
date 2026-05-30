#include <iostream>
#include <string>
#include "DoublyLinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Result

    ========== Test Case 1: Reverse Middle Section Only ==========
    Before: 3 <-> 8 <-> 5 <-> 10 <-> 2 <-> 1
    After:  3 <-> 2 <-> 10 <-> 5 <-> 8 <-> 1

    ========== Test Case 2: Reverse Entire List ==========
    Before: 1 <-> 2 <-> 3 <-> 4 <-> 5
    After:  5 <-> 4 <-> 3 <-> 2 <-> 1

    ========== Test Case 3: Reverse Single Node List ==========
    Before: 9
    After:  9

    ========== Test Case 4: Reverse Small Entire List ==========
    Before: 7 <-> 8 <-> 9
    After:  9 <-> 8 <-> 7

    ========== Test Case 5: Empty List & Early Exit ==========
    Before: empty
    After:  empty
    Length: 0

    ========== Test Case 6: Same Arguments & Early Exit ==========
    Before: 1 <-> 2 <-> 3
    After:  1 <-> 2 <-> 3

*/

static void test() {
    
    cout << "========== Test Case 1: Reverse Middle Section Only ==========\n";
    DoublyLinkedList dll1(3);
    dll1.append(8); dll1.append(5); dll1.append(10); dll1.append(2); dll1.append(1);
    cout << "Before: ";
    dll1.printList();
    dll1.reverseBetween(1, 4);
    cout << "After:  ";
    dll1.printList();

    cout << "\n========== Test Case 2: Reverse Entire List ==========\n";
    DoublyLinkedList dll2(1);
    dll2.append(2); dll2.append(3); dll2.append(4); dll2.append(5);
    cout << "Before: ";
    dll2.printList();
    dll2.reverseBetween(0, 4);
    cout << "After:  ";
    dll2.printList();

    cout << "\n========== Test Case 3: Reverse Single Node List ==========\n";
    DoublyLinkedList dll3(9);
    cout << "Before: ";
    dll3.printList();
    dll3.reverseBetween(0, 0);
    cout << "After:  ";
    dll3.printList();

    cout << "\n========== Test Case 4: Reverse Small Entire List ==========\n";
    DoublyLinkedList dll4(7);
    dll4.append(8); dll4.append(9);
    cout << "Before: ";
    dll4.printList();
    dll4.reverseBetween(0, 2);
    cout << "After:  ";
    dll4.printList();

    cout << "\n========== Test Case 5: Empty List & Early Exit ==========\n";
    DoublyLinkedList dll5(0);
    dll5.makeEmpty();
    cout << "Before: ";
    dll5.printList();
    dll5.reverseBetween(0,1);
    cout << "After:  ";
    dll5.printList();
    cout << "Length: " << dll5.getLength() << endl;
    
    cout << "\n========== Test Case 6: Same Arguments & Early Exit ==========\n";
    DoublyLinkedList dll6(1);
    dll6.append(2); dll6.append(3);
    cout << "Before: ";
    dll6.printList();
    dll6.reverseBetween(2, 2);
    cout << "After:  ";
    dll6.printList();
}

int main() {
    test();
    return 0;
}
