#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node(int value) {
            this->value = value;
            next = nullptr;
        }
};

class LinkedList {
    private:
        Node* head;
        int length;
        
    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            length = 1;
        }
    
        ~LinkedList() {
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
                cout << "empty";
            } else {
                while (temp != nullptr) {
                    cout << temp->value;
                    temp = temp->next;
                    if (temp != nullptr) {
                        cout << " -> ";
                    }
                }
            }
            cout << endl;
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
            if (head == nullptr) {
                head = newNode;
            } else {
                Node* currentNode = head;
                while (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                }
                currentNode->next = newNode;
            }
            length++;
        }
    
        void deleteFirst() {
            if (length == 0) return;
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
            } else {
                head = head->next;
            }
            delete temp;
            length--;
        }
    
        /*********************************************************************/
        
        void reverseBetween(int m, int n) {

            if (length <= 1) return;
            if (m == n) return;

            Node* dummy = new Node(0);
            dummy->next = head;

            Node* prev = head;
            Node* current = nullptr;
            
            if (m == 0) { 
                prev = dummy; 
            } 
            
            // find m-th node
            int i = 0; 
            for (; i < m - 1; i++) { 
                prev = prev->next; 
            } 

            current = prev->next; 

            // How many iterations to reach 'n'? 
            int j = n - m; 
            int k = j; 

            while (k > 0) {
                Node* tomove = current->next; 
                if (k == j) { 
                    current->next = tomove->next; 
                    tomove->next = current;
                    prev->next = tomove; 
                } 
                else { 
                    // Post-Review: These 3 lines below are all that are needed for this loop
                    // the extra code in above if block can be deleted
                    current->next = tomove->next; 
                    tomove->next = prev->next; 
                    prev->next = tomove; 
                } 
                k--; 
            } 

            if (m==0) head = prev->next;

            delete dummy;
        } 

        //   +======================================================+
        //   |                 WRITE YOUR CODE HERE                 |
        //   | Description:                                         |
        //   | - Reverse nodes between positions m and n            |
        //   | - Return type: void                                  |
        //   |                                                      |
        //   | Tips:                                                |
        //   | - Create a dummy node and set its next to head       |
        //   | - Use 'prev' pointer to go to m-th node              |
        //   | - Use 'current' pointer for m+1 to n nodes           |
        //   | - Loop to reverse m+1 to n nodes                     |
        //   | - Update original list's head                        |
        //   | - Free dummy node memory                             |
        //   +======================================================+
    
};


