#include "FindDuplicates.h"

vector<int> findDuplicates(const vector<int>& nums) {
    unordered_map<int, int> numCounts;
    
    for (int n: nums) {
        
        numCounts[n]++;
    }

    vector<int> duplicates; // 'duplicateValues' would be more clear
    for (const auto& entry: numCounts)
    {
        if (entry.second > 1)
        {
            duplicates.push_back(entry.first);
        }
    }
        
    return duplicates;
}
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function finds duplicate integers in a given |
	//   |   vector.                                           |
	//   | - It uses an unordered_map to count each integer's  |
	//   |   occurrences.                                      |
	//   | - Loops through the map to find duplicates.         |
	//   |                                                     |
	//   | Return type: vector<int>                            |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'numCounts' keeps track of each integer's count.  |
	//   | - 'duplicates' stores duplicate integers found.     |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+