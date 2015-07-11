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
#include "common.h"


using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;
        else if (n == 1)
            return nums[0];

        int dp[n];
        int prev_max = 0;


        // case 1: house 0 is not selected
        for (int i = 0; i < n; ++ i) {
            if (i == 0) {
                dp[i] = 0;
            }
            else if (i == 1) {
                dp[1] = nums[1];
            }
            else {
                prev_max = max(prev_max, dp[i-2]);
                dp[i] = prev_max + nums[i];
            }
        }

        int ans1 = max(dp[n-1], dp[n-2]);


        // case 2: house 0 is selected
        prev_max = 0;
        for (int i = 0; i < n - 1; ++ i) {
            if (i == 0) {
                dp[0] = nums[0];
            }
            else if (i == 1) {
                dp[1] = 0;
            }
            else {
                prev_max = max(prev_max, dp[i-2]);
                dp[i] = prev_max + nums[i];
            }
        }

        int ans2;
        if (n >= 3)
            ans2 = max(dp[n-2], dp[n-3]);
        else
            ans2 = dp[n-2];


        int ans = max(ans1, ans2);



        return ans;
    }
};




int main() {
    vector<int> nums = {1,1,1};

    cout << Solution().rob(nums) << endl;


	return 0;
}