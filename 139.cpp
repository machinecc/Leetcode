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
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
        	return false;

        int min_len = INT_MAX;
        int max_len = 0;

        for (auto it = wordDict.begin(); it != wordDict.end(); ++ it) {
        	min_len = min(min_len, int((*it).length()));
        	max_len = max(max_len, int((*it).length()));
        }



        int n = s.length();

        vector<bool> dp(n, false);

        for (int i = min_len - 1; i < n; ++ i) {
        	for (int j = max(0, i + 1 - max_len); j <= i + 1 - min_len; ++ j) {
        		string word = s.substr(j, i - j + 1);

        		if (wordDict.find(word) == wordDict.end())
        			continue;

        		bool prev = j - 1 >= 0 ? dp[j-1] : true;
        		dp[i] = dp[i] || prev;

        		if (dp[i] == true)
        			break;
        	}
        }

        //cout << dp[n-1] << endl;
        return dp[n-1];
    }
};


int main() {
	unordered_set<string> wordDict = {"leet", "code"};

	string s = "leetcode";

	cout << Solution().wordBreak(s, wordDict) << endl;


	return 0;
}