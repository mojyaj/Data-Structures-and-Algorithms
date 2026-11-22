#include "ItemInCommon.h"

bool itemInCommon(vector<int> vect1, vector<int> vect2) {
    unordered_map<int,bool> hashtable;
    
    for (int v: vect1) {
        hashtable.insert({v,true});
    }
    for (int w: vect2) {
        if (hashtable[w]) return true;
        // ISSUE: 'hashtable[w]' - if 'w' does not exist, then 'w' is inserted into the 'hashtable' with a default value of 'false'
    }
    
    return false;
}	
    //   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function checks if two vectors have a        |
	//   |   common element.                                   |
	//   | - It uses an unordered_map to store elements from   |
	//   |   the first vector.                                 |
	//   | - Then it checks each element from the second       |
	//   |   vector against the map.                           |
	//   |                                                     |
	//   | Return type: bool                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'myMap' stores elements from 'vect1' as keys.     |
	//   | - Loop through 'vect2' and check against 'myMap'.   |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+