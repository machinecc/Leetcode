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
    int minSubArrayLen(int s, vector<int>& nums) {
    	int n = nums.size();

    	int total = accumulate(nums.begin(), nums.end(), 0);

    	if (n == 0 || total < s)
    		return 0;

    	int left = 0;
    	int right = 0;
    	int sum = nums[left];
    	int len = INT_MAX;



    	while (true) {
    		while (right < n && sum < s) {
    			++ right;
    			sum += nums[right];
    		}

    		if (right >= n)
    			break;

    		len = min(len, right - left + 1);

    		sum = sum - nums[left];

    		++ left;    		
    	}   

    	return len;
    }

    int minSubArrayLen2(int s, vector<int>& nums) {
    	int n = nums.size();

    	int total = accumulate(nums.begin(), nums.end(), 0);

    	if (n == 0 || total < s)
    		return 0;

    	

    }
};




int main() {
	int s = 100;
	vector<int> nums = {2,3,1,2,4,3};

	cout << Solution().minSubArrayLen(s, nums) << endl;


	return 0;
}