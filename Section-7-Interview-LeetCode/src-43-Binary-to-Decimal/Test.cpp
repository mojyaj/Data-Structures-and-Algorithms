#include <iostream>
#include <string>
#include "LinkedList.cpp"

using namespace std;
using std::to_string;

/* Test Results


*/

static void test() {
    // Helper function for pass/fail
    auto checkTestResult = [](bool condition) {
        cout << (condition ? "PASS" : "FAIL") << endl;
    };

    // Test: BinaryToDecimalEmptyList
    {
        cout << "\n------ Test: BinaryToDecimalEmptyList ------\n";
        
        LinkedList list(1);
        list.makeEmpty();
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 0);
    }

    // Test: BinaryToDecimalSingleElement
    {
        cout << "\n------ Test: BinaryToDecimalSingleElement ------\n";
        
        LinkedList list(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 1);
    }

    // Test: BinaryToDecimalMultipleElements
    {
        cout << "\n------ Test: BinaryToDecimalMultipleElements ------\n";
        
        LinkedList list(1);
        list.append(0);
        list.append(1);
        list.append(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 11);
    }

    // Test: BinaryToDecimalAllZeros
    {
        cout << "\n------ Test: BinaryToDecimalAllZeros ------\n";
        
        LinkedList list(0);
        list.append(0);
        list.append(0);
        list.append(0);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 0);
    }

    // Test: BinaryToDecimalAllOnes
    {
        cout << "\n------ Test: BinaryToDecimalAllOnes ------\n";
        
        LinkedList list(1);
        list.append(1);
        list.append(1);
        list.append(1);
        
        cout << "BINARY:    ";
        list.printList();
        
        int decimal = list.binaryToDecimal();
        
        cout << "DECIMAL:   " << decimal << endl;
        
        checkTestResult(decimal == 15);   // 1111  = 15
        //checkTestResult(decimal == 31);     // 11111 = 31
        // checkTestResult(decimal == 30);     // 11111 = 30
    }
}

int main() {
    test();
    return 0;
}
