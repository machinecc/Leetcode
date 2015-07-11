#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <array>


using namespace std;

class Solution {
public:
	vector<vector<int>> dp;

    bool isScramble(string s1, string s2) {
        bool ans = dfs(s1, s2);
        return ans;
    }








    bool dfs(string s1, string s2) {
    	if (s1 == s2)
			return true;

        if (s1.size() != s2.size())
        	return false;

    	int n = s1.size();

    	if (n == 1 && s1 != s2)
    		return false;

    	if (n == 2 && s1[0] == s2[1] && s1[1] == s2[0]) {
    			return true;
    	}

    	
        int count[26] = {0};

        for (int i = 0; i < n; ++ i) {
        	count[s1[i] - 'a'] += 1;
        	count[s2[i] - 'a'] -= 1;
        }

        for (int i = 0; i < 26; ++ i)
        	if (count[i] != 0)
        		return false;
		

    	for (int len = 1; len < n; ++ len) {
    		if ( (dfs(s1.substr(0, len), s2.substr(n - len, len)) && dfs(s1.substr(len, n - len), s2.substr(0, n - len)))
    			 ||
    			 (dfs(s1.substr(0, len), s2.substr(0, len)) && dfs(s1.substr(len, n - len), s2.substr(len, n - len)))
    			 )
    			return true;
    	}

    	return false;
    }
};


int main() {


	cout << Solution().isScramble("abcdefghijklmnopq","efghijklmnopqcadb") << endl;

	return 0;
}