#include "SortStack.h"
#include <array>
#include <vector>
#include <iostream>

using namespace std;

// Strategy: move lower value stack elements to the bottom of a second stack
//           once that is completed then, move all elements from 'tempStack' 
//           to 'inputStack'.

/**/  // My solution:
void sortStack(stack<int>& inputStack) {
    if (inputStack.size() <= 1) return;

    stack<int> tempStack{};
    int temp = inputStack.top(); // INT_MIN means "no value to swap"
    inputStack.pop();

    while (!inputStack.empty()) {
        if (tempStack.empty()) {
            tempStack.push(temp);
            temp = inputStack.top();
            inputStack.pop();
        }

        if (temp >= tempStack.top()) {
            tempStack.push(temp);
            temp = inputStack.top();
            inputStack.pop();
        } 
        
        if (temp < tempStack.top()) {
            inputStack.push(tempStack.top());
            tempStack.pop();
        }

        if (inputStack.empty()) {
            tempStack.push(temp);
            temp = INT_MIN;
        }
    }

    while (!tempStack.empty()) {
        int move = tempStack.top();
        inputStack.push(move);
        tempStack.pop();
    }
}
/**/

/* // Instructor's solution. faster and cleaner
void sortStack(stack<int>& inputStack) {
    stack<int> additionalStack;
 
    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();
 
        while (!additionalStack.empty() && additionalStack.top() > temp) {
            inputStack.push(additionalStack.top());
            additionalStack.pop();
        }
 
        additionalStack.push(temp);
    }
 
    while (!additionalStack.empty()) {
        inputStack.push(additionalStack.top());
        additionalStack.pop();
    }
}
*/

void printstack(stack<int> stack) {
    while(!stack.empty()) {
        int value = stack.top();
        stack.pop();
        std::cout << value << std::endl;
    }
}

    //   +======================================================+
    //   |                 WRITE YOUR CODE HERE                 |
    //   | Description:                                         |
    //   | - This function sorts the input stack 'inputStack'.  |
    //   | - Uses an additional stack for sorting.              |
    //   | - Return type: void                                  |
    //   |                                                      |
    //   | Tips:                                                |
    //   | - Create an additional stack.                        |
    //   | - Pop elements from 'inputStack' and push them       |
    //   |   into 'additionalStack' in sorted order.            |
    //   | - Use a temporary variable to hold the top element   |
    //   |   of 'inputStack'.                                   |
    //   | - Move elements back to 'additionalStack' if needed. |
    //   | - Finally, move all elements back to 'inputStack'.   |
    //   | - Check output from Test.cpp in "User logs".         |
    //   +======================================================+

