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
#include <cmath>
#include <queue>
#include "common.h"


using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
    	int n = nums.size();

    	vector<vector<int>> ans;


    	for (int i = 0; i < n; ++ i) {
    		for (int j = i + 1; j < n; ++ j) {
	    		int d = target - nums[i] - nums[j];

	    		int p = j + 1;
	    		int q = n - 1;

	    		while (p < q) {
	    			if (nums[p] + nums[q] == d) {
	    				vector<int> v = {nums[i], nums[j], nums[p], nums[q]};
	    				ans.push_back(v);

	    				++ p;
	    				-- q;

	    				while (p < q && nums[p] == nums[p-1])
	    					++ p;

	    				while (p < q && nums[q] == nums[q+1])
	    					-- q;
	    			}
	    			else if (nums[p] + nums[q] < d) {
	    				++ p;
	    			}
	    			else {
	    				-- q;
	    			}

	    		}

	    		while (j < n - 1 && nums[j] == nums[j+1])
	    			++ j;
    		}

    		while (i < n - 1 && nums[i] == nums[i+1])
    			++ i;
    	}

    	return ans;
    }
};




int main() {
	vector<int> nums = {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

	vector<vector<int>> ans = Solution().fourSum(nums, 0);

	for (int i = 0; i < ans.size(); ++ i) {
		for (int j = 0; j < ans[i].size(); ++ j)
			cout << ans[i][j] << ' ';
		cout << endl;
	}


	return 0;
}