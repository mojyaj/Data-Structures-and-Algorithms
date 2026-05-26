#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;
using std::to_string;

/*

*/

static void test() {
    
    cout << "\n=======================================\n";
    cout << "Test Case 1: Even Number of Nodes\n";
    cout << "swapPairs()\n";
    cout << "---------------------------------------\n";
    LinkedList ll1(1);
    ll1.append(2);
    ll1.append(3);
    ll1.append(4);
    cout << "BEFORE: ";
    ll1.printList();
    ll1.swapPairs();
    cout << "AFTER:  ";
    ll1.printList();

    cout << "\n=======================================\n";
    cout << "Test Case 2: Odd Number of Nodes\n";
    cout << "swapPairs()\n";
    cout << "---------------------------------------\n";
    LinkedList ll2(1);
    ll2.append(2);
    ll2.append(3);
    cout << "BEFORE: ";
    ll2.printList();
    ll2.swapPairs();
    cout << "AFTER:  ";
    ll2.printList();

    cout << "\n=======================================\n";
    cout << "Test Case 3: Single Node\n";
    cout << "swapPairs()\n";
    cout << "---------------------------------------\n";
    LinkedList ll3(1);
    cout << "BEFORE: ";
    ll3.printList();
    ll3.swapPairs();
    cout << "AFTER:  ";
    ll3.printList();

    cout << "\n=======================================\n";
    cout << "Test Case 4: Empty List\n";
    cout << "swapPairs()\n";
    cout << "---------------------------------------\n";
    LinkedList ll4(1);
    ll4.makeEmpty();
    cout << "BEFORE: ";
    ll4.printList();
    ll4.swapPairs();
    cout << "AFTER:  ";
    ll4.printList();
    cout << "\n=======================================\n";
    
}

int main() {
    test();
    return 0;
}