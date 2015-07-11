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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;

        int n = nums.size();

        if (n == 0)
        	return ans;

        sort(nums.begin(), nums.end());

        ans.push_back(nums);

        if (n == 1)
        	return ans;


        while (true) {
        	int p = n - 2;

        	while (p >= 0 && nums[p] >= nums[p+1])
        		-- p;

        	if (p == -1)
        		break;

        	int q = n - 1;


        	while (nums[q] <= nums[p])
        		-- q;

        	swap(nums[p], nums[q]);

        	reverse(nums.begin() + p + 1, nums.end());

        	ans.push_back(nums);

        }

        return ans;

    }
};


int main() {
	vector<int> nums = {1,1,2};

	vector<vector<int>> ans = Solution().permuteUnique(nums);

	for (int i = 0; i < ans.size(); ++ i)
		printvector(ans[i]);

	cout << endl;

	cout << ans.size() << endl;


	return 0;
}