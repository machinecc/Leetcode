#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 1;
        int count = s.length();
		unordered_set<char> alphabets;

		if (count == 0) {
			return 0;
		}

        int maxlength = 1;
        alphabets.insert(s[0]);

        while (right < count) {
        	char c = s[right];
        	if ( alphabets.find(c) == alphabets.end() ) {
        		alphabets.insert(c);

        		if (right - left + 1 > maxlength) {
        			maxlength = right - left + 1;
        			//cout << "left = " << left << "   " << "right = " << right << endl;
        		}
        	}
        	else {
        		while (s[left] != c) {
        			alphabets.erase(s[left]);
        			++ left;
        		}
        		++ left;
        	}

        	++right;
        }

        if (right - left > maxlength) {
        	maxlength = right - left ;
        }



        return maxlength;
    }
};



int main() {
	cout << Solution().lengthOfLongestSubstring("tmmzuxt") << endl;
}