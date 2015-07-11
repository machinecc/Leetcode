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
    int maxSubArray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();

        int sum_max = INT_MIN;
        int left = 0;
        int right = 0;

        int sum = 0;
        while (i < n && j < n) {
        	sum += nums[j];

        	if (sum > sum_max) {
        		sum_max = sum;
        		left = i;
        		right = j;
        	}

        	if (sum > 0)
        		++ j;
        	else {
        		i = j + 1;
        		j = i;
        		sum = 0;
        	}
        }
        //cout << sum_max << endl;
        return sum_max;
    }
};


int main() {
	vector<int> nums = {-2};

	Solution().maxSubArray(nums);

	return 0;
}