#include <iostream>
#include <unordered_set>

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
        
        /******************************************************************/
        
        // My algorithm with nested loop
        void removeDuplicates() {
            
            if (length <= 1) return;
            
            Node* current = head;
            Node* runner = head;
            
            for (int i = 1; i <= length-1; i++) {
                
                for (int j = i; j <= length-1; j++) {
                    if (current->value == runner->next->value){
                        Node* temp = runner->next;          // prep Node to be deleted
                        runner->next = runner->next->next;  // swap duplicate node out
                        delete temp;                        // delete duplicate node
                        j = (j == i) ? j-1 : j;             // compensate j index for position change
                        length--;                           // decrement length
                    } else {
                        runner = runner->next;
                    }
                }

                current = current->next;
                runner = current;
            }
        }

/*      // Instructor's algorithm with nested loop
        void removeDuplicates() {
            Node* current = head;
            while (current != nullptr) {
                Node* runner = current;
                while (runner->next != nullptr) {
                    if (runner->next->value == current->value) {
                        Node* temp = runner->next;
                        runner->next = runner->next->next;
                        delete temp;
                        length -= 1;
                    } else {
                        runner = runner->next;
                    }
                }
                current = current->next;
            }
        }

        // With set data structure
        void removeDuplicates() {
            unordered_set<int> values;
            Node* previous = nullptr;
            Node* current = head;
            while (current != nullptr) {
                if (values.find(current->value) != values.end()) {
                    previous->next = current->next;
                    delete current;
                    current = previous->next;
                    length -= 1;
                } else {
                    values.insert(current->value);
                    previous = current;
                    current = current->next;
                }
            }
        }
*/

};


