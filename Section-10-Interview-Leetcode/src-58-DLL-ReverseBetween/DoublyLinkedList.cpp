#include <iostream>

using namespace std;

class Node { 
    public: 
        int value;
        Node* next;
        Node* prev;
    
        Node(int value) {
            this->value = value;
            next = nullptr;
            prev = nullptr;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~DoublyLinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }
    
        void printList() {
            Node* temp = head;
            if (temp == nullptr) {
                cout << "empty" << endl;
                return;
            }
            while (temp->next != nullptr) {
                cout << temp->value << " <-> ";
                temp = temp->next;
            }
            cout << temp->value << endl;
        }
    
        Node* getHead() {
            return head;
        }
    
        int getLength() {
            return length;
        }

        void makeEmpty() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
            length = 0;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->prev = temp;
            }
            length++;
        }
        
        /*********************************************************************/
                        // startIndex,   endIndex
        void reverseBetween(int n, int m) {
            if (!head) return;

            Node* dummy = new Node(0);
            dummy->next = head;
            Node* prev = dummy;

            for (int i=0; i < n; i++){
                prev = prev->next;
            }

            Node* current = prev->next;
            
            for (int i=0; i < m - n; i++) {
                Node* temp = prev->next;   // use 'dummy->prev' as a temporary cache

                // Swap 'next' properties
                prev->next = current->next; 
                current->next = current->next->next;
                prev->next->next = temp;  //*Set to old prev->next

                // Swap 'prev' properties
                if (current->next) {
                    current->next->prev =  current;
                } else {
                     current->next = nullptr; // tail = current; // no 'tail' property for this class
                }
                temp->prev = prev->next;
                prev->next->prev = prev;
            }

            head = dummy->next;
            head->prev = nullptr;
            delete dummy;
        }
        
        //   +===================================================+
        //   |               WRITE YOUR CODE HERE                |
        //   | Description:                                      |
        //   | - Reverses a portion of a doubly linked list      |
        //   |   between startIndex and endIndex (inclusive).    |
        //   | - The rest of the list remains unchanged.         |
        //   |                                                   |
        //   | Behavior:                                         |
        //   | - A dummy node is used to simplify edge cases     |
        //   |   when reversing from the head.                   |
        //   | - `prev` is positioned just before the reversal   |
        //   |   section.                                        |
        //   | - Nodes are extracted one by one and moved to the |
        //   |   front of the sublist, reversing the segment.    |
        //   | - All `.next` and `.prev` pointers are correctly  |
        //   |   updated during each step.                       |
        //   | - Updates the list's head and deletes dummy node. |
        //   +===================================================+
};


