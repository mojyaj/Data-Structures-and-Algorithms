#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results

    ------ Test: PartitionEmptyList ------
    BEFORE:    empty
    partitionList(3)
    EXPECTED:  empty
    ACTUAL:    empty
    PASS

    ------ Test: PartitionSingleElement ------
    BEFORE:    1
    partitionList(3)
    EXPECTED:  1
    ACTUAL:    1
    PASS

    ------ Test: PartitionAllLessThanX ------
    BEFORE:    1 -> 2 -> 3
    partitionList(4)
    EXPECTED:  1 -> 2 -> 3
    ACTUAL:    1 -> 2 -> 3
    PASS

    ------ Test: PartitionAllGreaterThanX ------
    BEFORE:    1 -> 2 -> 3 -> 4
    partitionList(0)
    EXPECTED:  1 -> 2 -> 3 -> 4
    ACTUAL:    1 -> 2 -> 3 -> 4
    PASS

    ------ Test: PartitionMixedNumbers ------
    BEFORE:    1 -> 4 -> 3 -> 2 -> 5 -> 2
    partitionList(3)
    EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5
    ACTUAL:    1 -> 2 -> 2 -> 4 -> 3 -> 5
    PASS

*/

static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: PartitionEmptyList
    {
        cout << "\n------ Test: PartitionEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  empty\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head == nullptr);
    }

    // Test: PartitionSingleElement
    {
        cout << "\n------ Test: PartitionSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionAllLessThanX
    {
        cout << "\n------ Test: PartitionAllLessThanX ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(0)\n";
        cout << "EXPECTED:  1 -> 2 -> 3\n";
        
        list.partitionList(4);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionAllLessThanX
    {
        cout << "\n------ Test: PartitionAllGreaterThanX ------\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(4)\n";
        cout << "EXPECTED:  1 -> 2 -> 3 -> 4\n";
        
        list.partitionList(2);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: PartitionMixedNumbers
    {
        cout << "\n------ Test: PartitionMixedNumbers ------\n";
        
        LinkedList list(1);
        list.append(4);
        list.append(3);
        list.append(2);
        list.append(5);
        list.append(2);
        
        cout << "BEFORE:    ";
        list.printList();
        
        cout << "partitionList(3)\n";
        cout << "EXPECTED:  1 -> 2 -> 2 -> 4 -> 3 -> 5\n";
        
        list.partitionList(3);
        
        cout << "ACTUAL:    ";
        list.printList();
        
        // Check if the list is partitioned correctly
        Node* current = list.getHead();
        bool isPartitioned = true;
        bool crossedPartitionValue = false;
        
        while (current && current->next) {
            if (current->value >= 3) {
                crossedPartitionValue = true;
            }
            if (crossedPartitionValue && current->value < 3) {
                isPartitioned = false;
                break;
            }
            current = current->next;
        }

        
        checkTestResult(isPartitioned);
    }
}

int main() {
    test();
    return 0;
}


