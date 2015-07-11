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


void printvector(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++ i)
		cout << nums[i] << ' ';
	cout << endl;
}

class Solution {
public:
    int rob0(vector<int>& nums) {
		int n = nums.size();

		if (n == 0)
			return 0;

		int dp[n][2];

		for (int i = 0; i < n; ++ i) {
			if (i == 0) {
				dp[i][0] = 0;
				dp[i][1] = nums[i];
			}
			else if (i == 1) {
				dp[i][0] = dp[0][1];
				dp[i][1] = nums[1];
			}
			else {
				dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
				dp[i][1] = nums[i] + max(dp[i-2][0], dp[i-2][1]);
			}
		}

		return max(dp[n-1][0], dp[n-1][1]);
    }

    int rob(vector<int>& nums) {
    	int n = nums.size();

		if (n == 0)
			return 0;

		if (n == 1)
			return nums[0];

		int dp[n];

		for (int i = 0; i < n; ++ i) {
			if (i <= 1)
				dp[i] = nums[i];
			else if (i == 2)
				dp[2] = nums[2] + nums[0];
			else
				dp[i] = max(dp[i-2], dp[i-3]) + nums[i];
		}

		return max(dp[n-1], dp[n-2]);
    }
};


int main() {
	vector<int> nums = {1,2,3};
	cout << Solution().rob(nums) << endl;

	return 0;
}