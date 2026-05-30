#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results

    ------ Test: ReverseBetweenEmptyList ------
    reverseBetween( 0, 2 )
    BEFORE:    empty
    AFTER:     empty
    PASS

    ------ Test: ReverseBetweenSingleElement ------
    reverseBetween( 0, 0 )
    BEFORE:    1
    AFTER:     1
    PASS

    ------ Test: ReverseBetweenBothArgumentsSameNumber ------
    reverseBetween( 1, 1 )
    BEFORE:    1 -> 2 -> 3
    AFTER:     1 -> 2 -> 3
    PASS

    ------ Test: ReverseBetweenMultipleElements ------
    reverseBetween( 1, 5 )
    BEFORE:    1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
    AFTER:     1 -> 7 -> 6 -> 5 -> 4 -> 3 -> 2 -> 8
    PASS

    ------ Test: ReverseBetweenStartAtZero ------
    reverseBetween( 0, 2 )
    BEFORE:    1 -> 2 -> 3 -> 4
    AFTER:     3 -> 2 -> 1 -> 4
    PASS

    ------ Test: ReverseBetweenMiddleToLast ------
    reverseBetween( 1, 2 )
    BEFORE:    1 -> 2 -> 3
    AFTER:     1 -> 3 -> 2
    PASS
*/

static void test() {
    // Helper function to check pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: ReverseBetweenEmptyList
    {
        cout << "\n------ Test: ReverseBetweenEmptyList ------\n";
        cout << "reverseBetween( 0, 2 )\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        checkTestResult(list.getLength() == 0);
    }

    // Test: ReverseBetweenSingleElement
    {
        cout << "\n------ Test: ReverseBetweenSingleElement ------\n";
        cout << "reverseBetween( 0, 0 )\n";
        
        LinkedList list(1);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 0);
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(head && head->value == 1);
    }

    // Test: ReverseBetweenBothArgumentsSameNumber
    {
        cout << "\n------ Test: ReverseBetweenBothArgumentsSameNumber ------\n";
        cout << "reverseBetween( 1, 1 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 1);
        
        cout << "AFTER:     ";
        list.printList();
        
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 && 
          head->next->value == 2 && 
          head->next->next->value == 3
        );
    }

    // Test: ReverseBetweenMultipleElements
    {
        cout << "\n------ Test: ReverseBetweenMultipleElements ------\n";
        cout << "reverseBetween( 1, 5 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        list.append(5);
        list.append(6);
        list.append(7);
        list.append(8);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 6);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 &&
          head->next->value == 7 &&
          head->next->next->value == 6 &&
          head->next->next->next->value == 5 &&
          head->next->next->next->next->value == 4 &&
          head->next->next->next->next->next->value == 3 &&
          head->next->next->next->next->next->next->value == 2 && 
          head->next->next->next->next->next->next->next->value == 8
        );
    }

    // Test: ReverseBetweenStartAtZero
    {
        cout << "\n------ Test: ReverseBetweenStartAtZero ------\n";
        cout << "reverseBetween( 0, 2 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        list.append(4);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(0, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 3 &&
          head->next->value == 2 &&
          head->next->next->value == 1 &&
          head->next->next->next->value == 4
        );
    }

    // Test: ReverseBetweenEndAtLast
    {
        cout << "\n------ Test: ReverseBetweenMiddleToLast ------\n";
        cout << "reverseBetween( 1, 2 )\n";
        
        LinkedList list(1);
        list.append(2);
        list.append(3);
        
        cout << "BEFORE:    ";
        list.printList();
        
        list.reverseBetween(1, 2);
        
        cout << "AFTER:     ";
        list.printList();
        
        // Check condition
        Node* head = list.getHead();
        checkTestResult(
          head && 
          head->value == 1 &&
          head->next->value == 3 &&
          head->next->next->value == 2
        );
    }

    /* Instructor's Algorithm
        void reverseBetween(int m, int n) {
            // 1. Initial Check:
            // If the list is empty, there's nothing to reverse.
            // So, exit the function without doing anything.
            if (head == nullptr) return;
        
            // 2. Dummy Node Creation:
            // We initiate a new 'dummy' node with value 0.
            // This is a trick to simplify the edge cases.
            Node* dummy = new Node(0);
        
            // Connect our actual list right after the dummy node.
            // So, the dummy node temporarily stands before the head.
            dummy->next = head;
        
            // 3. Positioning 'prev':
            // Start with 'prev' pointing to the dummy node.
            Node* prev = dummy;
        
            // Move 'prev' up to the node just before the starting
            // point of the section we want to reverse.
            for (int i = 0; i < m; i++) {
                prev = prev->next;
            }
        
            // 4. Setting up 'current':
            // 'current' is set right after 'prev'.
            // It marks the start of the section to be reversed.
            Node* current = prev->next;
        
            // 5. Main Reversal Logic:
            // We now enter our core reversal loop.
            for (int i = 0; i < n - m; i++) {
                // 'temp' points to the node that's next in line
                // for our reversal process.
                Node* temp = current->next;
        
                // Detach 'temp' from the current sequence by
                // making 'current' skip over 'temp'.
                current->next = temp->next;
        
                // To move 'temp' to the start of our reversed section,
                // we first let 'temp' point to whatever node 'prev' is pointing to.
                temp->next = prev->next;
        
                // Finally, we adjust 'prev' to point to 'temp', thereby
                // moving 'temp' to the front of the reversed section.
                prev->next = temp;
            }

            // 6. Updating Head:
            // If our reversed section included the original head of the list,
            // our list's head would have changed. 
            // So, we need to update the head of our list.
            head = dummy->next;

            // 7. Cleanup:
            // The dummy node has served its purpose.
            // We free up its memory to avoid memory leaks.
            delete dummy;
        }
    
    */
    
}

int main() {
    test();
    return 1;
}
