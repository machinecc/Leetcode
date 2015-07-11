#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        string next = "";

        for (int r = 0; r < n - 1; ++ r) {
        	next = "";

        	int m = s.length();

        	int left = 0;
        	int right = 0;

        	while (right < m) {
        		while ( right < m && s[left] == s[right] )
					++ right;
				
				next = next + to_string(right - left) + string(1, s[left]);

				left = right;
        	}

        	s = next;
        }

        return s;
    }



};


int main() {
	for (int i = 1; i < 10; ++ i)
		cout << Solution().countAndSay(i) << endl;

	return 0;
}