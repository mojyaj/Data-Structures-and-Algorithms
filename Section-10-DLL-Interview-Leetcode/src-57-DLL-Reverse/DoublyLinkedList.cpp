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
        Node* tail;
        int length;
    
    public:
        DoublyLinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
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
    
        Node* getTail() {
            return tail;
        }
    
        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            length++;
        }
        
        /********************************************************************/
        
        /**/  // with while loop
              // hard to read - See Instructor's algorithm in 'course-notes.txt'
        void reverse() {

            if (length <= 1) return;
            
            Node* left = head;
            Node* right;

            do {
                // advance ahead of 'left' by 1 node
                right = left->next;         // `temp = current->prev;`

                left->next = left->prev;    // `current->next = temp;`
                left->prev = right;         // `current->next = temp;`
                right->prev = right->next;  // This line & below forced decreased readability
                right->next = left;         //   and forced more swap logic outside of loop

                // advance by 2 nodes from current position
                left = right->prev; 
            } while (left && left->next); // (1)-(2)-(3)-(4)-nullptr
                                          //          l   r
            Node* temp = tail;
            tail = head;

            //Edge case: 'length' == 2,      (1)-(2)-nullptr
            //     where 'left' == nullptr             l                         l
            if (left) {    
                temp->prev = temp->next; // set 'prev' to nullptr
                temp->next = right;
            }
            head = temp;
        }
        /**/

        /** /
        void reverse() {
            Node* current = head;
            Node* temp = nullptr;
        
            while (current != nullptr) {
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;
                current = current->prev;
            }
        
            temp = head;
            head = tail;
            tail = temp;
        } 
        /**/

        //   +=====================================================+
        //   |                 WRITE YOUR CODE HERE                |
        //   | Description:                                        |
        //   | - This is the reverse method.                       |
        //   | - It reverses the entire doubly linked list.        |
        //   | - Return type: void                                 |
        //   |                                                     |
        //   | Tips:                                               |
        //   | - Create two pointers: current and temp.            |
        //   | - Loop through the list swapping next and prev      |
        //   |   for each node.                                    |
        //   | - After loop, swap head and tail pointers.          |
        //   | - Check output from Test.cpp in "User logs".        |
        //   +=====================================================+
        
};


