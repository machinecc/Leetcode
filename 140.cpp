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
	vector<string> ans;
	vector<int> stk;
	string s;

    vector<string> wordBreak(string _s, unordered_set<string>& wordDict) {
        if (_s.empty() || wordDict.empty())
        	return ans;

        s = _s;

        int min_len = INT_MAX;
        int max_len = 0;

        for (auto it = wordDict.begin(); it != wordDict.end(); ++ it) {
        	min_len = min(min_len, int((*it).length()));
        	max_len = max(max_len, int((*it).length()));
        }


        int n = s.length();

        vector<bool> dp(n, false);
        vector<vector<int>> links(n, vector<int>());

        for (int i = min_len - 1; i < n; ++ i) {
        	for (int j = max(0, i + 1 - max_len); j <= i + 1 - min_len; ++ j) {
        		string word = s.substr(j, i - j + 1);

        		if (wordDict.find(word) == wordDict.end())
        			continue;

        		bool prev = j - 1 >= 0 ? dp[j-1] : true;
        		dp[i] = dp[i] || prev;

        		if (prev == true)
        			links[i].push_back(j-1);
        	}
        }

        if (dp[n-1] == false)
        	return ans;

        // for (int i = 0; i < n; ++ i) {
        // 	cout << i << ":   ";
        // 	for (auto it = links[i].begin(); it != links[i].end(); ++ it)
        // 		cout << *it << " , ";
        // 	cout << endl;
        // }

        stk.push_back(n-1);
        dfs(links);

        return ans;
    }


    void dfs(vector<vector<int>>& links) {
    	int k = stk.back();


    	if (k == -1) {
    		// for (int i = 0; i < stk.size(); ++ i)
    		// 	cout << stk[i] << " -> ";
    		// cout << endl;

    		string result = "";
    		for (int i = 0; i < stk.size() - 1; ++ i) {
    			if (i > 0)
    				result = " " + result;


    			result = s.substr(stk[i+1] + 1, stk[i] - stk[i+1]) + result;
    		}



    		// for (int i = stk.size() - 1; i >= 0; -- i) {
    		// 	if (i == stk.size() -1)
    		// 		result = result + s.substr(stk[i-1] + 1, stk[i] - stk[i-1]);
    		// 	else
    		// 		result = result + s.substr(0, stk[i] + 1);

    		// 	if (i > 0)
    		// 		result = result + " ";
    		// }

    		ans.push_back(result);

    		return;

    	}


    	for (auto it = links[k].begin(); it != links[k].end(); ++ it) {
    		stk.push_back(*it);

    		dfs(links);

    		stk.pop_back();
    	}
    }
};

int main() {
	unordered_set<string> wordDict = {"aaaa", "aa", "a"};

	string s = "aaaaaaa";

	vector<string> ans = Solution().wordBreak(s, wordDict);
	for (auto it = ans.begin(); it != ans.end(); ++ it)
		cout << "\""<< *it << "\"" << endl;


	return 0;
}