#include "FirstNonRepeatingChar.h"

char firstNonRepeatingChar(const string& input_string) {
    unordered_map<int, char> charCounts;

    for (char c: input_string) {
        charCounts[c]++;
    }

    for (char c: input_string) {
        if (charCounts[c] == 1) return c;
    }
    
    return '\0';
}
	//   +======================================================+
	//   |                 WRITE YOUR CODE HERE                 |
	//   | Description:                                         |
	//   | - This function finds the first non-repeating char   |
	//   |   in a given string.                                 |
	//   | - It uses an unordered_map to count char occurrences |
	//   | - Loops through the string to check counts.          |
	//   |                                                      |
	//   | Return type: char                                    |
	//   |                                                      |
	//   | Tips:                                                |
	//   | - 'charCounts' keeps track of each char's count.     |
	//   | - Loops twice: once to count, once to find answer.   |
	//   | - Returns '\0' if no non-repeating char is found.    |
	//   | - Check output from Test.cpp in "User logs".         |
	//   +======================================================+