#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
	int target;
	vector<int> stk;

	vector<vector<int>> ans;

	int n;

    vector<vector<int>> combinationSum(vector<int>& candidates, int _target) {
    	sort(candidates.begin(), candidates.end());
    	candidates.erase( unique(candidates.begin(), candidates.end()), candidates.end());


    	n = candidates.size();

    	target = _target;

    	dfs(candidates, 0, 0);

    	return ans;
    }

    void dfs(vector<int>& candidates, int level, int sum) {
    	if (level == n)
    		return;

    	int val = candidates[level];

    	if (val > target - sum)
    		return;

    	int k = (target - sum) / val;


    	for (int i = 0; i <= k; ++ i) {

    		for (int j = 1; j <= i; ++ j) {
    			stk.push_back(val);
    		}

    		int curr_sum = sum + val * i;


    		


    		if (curr_sum  == target) {
    			ans.push_back(stk);
				//for (int p = 0; p < stk.size(); ++ p)
    			//	cout << stk[p] << ' ';
    			//cout << endl << curr_sum << endl << endl;

    		}
    		else if (curr_sum < target) {
    			dfs(candidates, level+1, curr_sum);
    		}


    		for (int j = 1; j <= i; ++ j)
    			stk.pop_back();
    	}
    }
};


int main() {
	vector<int> nums = {2, 3, 6, 7};

	Solution().combinationSum(nums, 7);




	return 0;
}