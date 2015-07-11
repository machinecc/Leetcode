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

    vector<vector<int>> combinationSum2(vector<int>& candidates, int _target) {
        sort(candidates.begin(), candidates.end());

    	n = candidates.size();

    	target = _target;

    	dfs(candidates, 0, 0);

    	//sort(ans.begin(), ans.end(), islessthan);
    	//ans.erase( unique(ans.begin(), ans.end(), isequal), ans.end() );

    	return ans;
    }




    void dfs(vector<int>& candidates, int level, int sum) {
    	if (level == n)
    		return;

    	int val = candidates[level];


    	if (val > target - sum)
    		return;


    	for (int i = 0; i <= 1; ++ i) {

    		for (int j = 1; j <= i; ++ j)
    			stk.push_back(val);

    		int curr_sum = sum + val * i;

    		if (curr_sum  == target) {
    			bool existing = false;
    			for (int p = 0; p < ans.size(); ++ p)
    				if (isequalto(stk, ans[p])) {
    					existing = true;
    					break;
    				}

    			if (existing == false)
    				ans.push_back(stk);
				// for (int p = 0; p < stk.size(); ++ p)
    // 				cout << stk[p] << ' ';
    // 			cout << endl << curr_sum << endl << endl;
    		}
    		else if (curr_sum < target) {
    			dfs(candidates, level+1, curr_sum);
    		}


    		for (int j = 1; j <= i; ++ j)
    			stk.pop_back();
    	}
    }


    bool isequalto(vector<int>& a, vector<int>& b) {
		if (a.size() != b.size())
			return false;

		for (int i = 0; i < a.size(); ++ i)
			if (a[i] != b[i])
				return false;
	return true;
	}
};



int main() {

	vector<int> nums = {4,4,2,1,4,2,2,1,3};

	vector<vector<int>> ans = Solution().combinationSum2(nums, 6);
	/*

	vector<int> a = {1,2};
	vector<int> b = {1,2};

	vector<vector<int>> ans;
	ans.push_back(a);
	ans.push_back(b);

	cout << isequal(a, b) << endl;

	*/


	for (int i = 0; i < ans.size(); ++ i) {
		for (int j = 0; j < ans[i].size(); ++ j)
			cout << ans[i][j] << ' ';

		cout << endl;
	}


	return 0;
}