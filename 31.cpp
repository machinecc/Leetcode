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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        if (n <= 1)
        	return;

        int p = n - 2;
        while (p >= 0 && nums[p] >= nums[p+1])
        	-- p;

        if (p < 0) {
        	reverse(nums.begin(), nums.end());
        	return;
        }

        int q = n - 1;
        while (nums[q] <= nums[p])
        	-- q;

        swap(nums[p], nums[q]);

        reverse(nums.begin() + p + 1, nums.end());
    }
};



int main() {
	vector<int> nums = {5,4,3,2,1};

	Solution().nextPermutation(nums);

	printvector(nums);


	return 0;
}