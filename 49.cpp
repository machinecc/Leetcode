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


using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        unordered_map<string, int> dict;
        vector<string> ans;

        for (int i = 0; i < strs.size(); ++ i) {
        	string s = strs[i];
        	sort(s.begin(), s.end());

        	if (dict.find(s) == dict.end()) {
        		dict[s] = i;
        	}
        	else {

        		if (dict[s] >= 0) {
        			ans.push_back(strs[dict[s]]);
        			dict[s] = -1;
        		}
        		ans.push_back(strs[i]);
        	}
        }

        return ans;
    }
};


int main() {
	vector<string> strs = {"", ""};

	vector<string> ans = Solution().anagrams(strs);

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << endl;


	return 0;
}