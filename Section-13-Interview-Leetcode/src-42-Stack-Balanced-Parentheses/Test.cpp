#include <iostream>
#include "Test.h"

// This #include can be commented out if using g++ to compile
// Only need this available for debugging
#include "BalancedParentheses.cpp"

using namespace std;

// Test Results at page bottom

void test() {
    cout << "\n----- Test: Empty Parentheses -----\n";
    {
        string input = "";
        cout << "Input: \"" << input << "\"\n";
        cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
        cout << (isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
    }

    cout << "\n----- Test: Balanced Parentheses -----\n";
    {
        string inputs[] = {"()", "(())", "(()(()))"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
            cout << (isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Unbalanced Opening Parentheses -----\n";
    {
        string inputs[] = {"(", "(()", "((())"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Unbalanced Closing Parentheses -----\n";
    {
        string inputs[] = {")", "())", "(()))"};
        for (const string &input : inputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }

    cout << "\n----- Test: Mixed Parentheses -----\n";
    {
        string balancedInput = "()()";
        string unbalancedInputs[] = {"()(", "())()"};

        cout << "Input: \"" << balancedInput << "\"\n";
        cout << "Output: " << (isBalancedParentheses(balancedInput) ? "Balanced" : "Unbalanced") << " - EXPECTED: Balanced\n";
        cout << (isBalancedParentheses(balancedInput) ? "PASS\n" : "FAIL\n");

        for (const string &input : unbalancedInputs) {
            cout << "Input: \"" << input << "\"\n";
            cout << "Output: " << (isBalancedParentheses(input) ? "Balanced" : "Unbalanced") << " - EXPECTED: Unbalanced\n";
            cout << (!isBalancedParentheses(input) ? "PASS\n" : "FAIL\n");
        }
    }
}

int main(){
    test();
    return 0;
}

/* Test Results:
    ----- Test: Empty Parentheses -----
    Input: ""
    Output: Balanced - EXPECTED: Balanced
    PASS

    ----- Test: Balanced Parentheses -----
    Input: "()"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "(())"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "(()(()))"
    Output: Balanced - EXPECTED: Balanced
    PASS

    ----- Test: Unbalanced Opening Parentheses -----
    Input: "("
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "(()"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "((())"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS

    ----- Test: Unbalanced Closing Parentheses -----
    Input: ")"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "())"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "(()))"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS

    ----- Test: Mixed Parentheses -----
    Input: "()()"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "()("
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "())()"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS            
*/

/* 
    EXPECTED OUTPUT:
    ----- Test: Empty Parentheses -----
    Input: ""
    Output: Balanced - EXPECTED: Balanced
    PASS
    ----- Test: Balanced Parentheses -----
    Input: "()"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "(())"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "(()(()))"
    Output: Balanced - EXPECTED: Balanced
    PASS
    ----- Test: Unbalanced Opening Parentheses -----
    Input: "("
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "(()"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "((())"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    ----- Test: Unbalanced Closing Parentheses -----
    Input: ")"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "())"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "(()))"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    ----- Test: Mixed Parentheses -----
    Input: "()()"
    Output: Balanced - EXPECTED: Balanced
    PASS
    Input: "()("
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS
    Input: "())()"
    Output: Unbalanced - EXPECTED: Unbalanced
    PASS

*/


