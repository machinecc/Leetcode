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
    bool canJump(vector<int>& nums) {
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n - 1) {
        	int next = 0;

        	for (int k = i; k <= j; ++ k) {
        		if (k >= n)
        			break;
        		next = max(next, k + nums[k]);
        	}

        	i = j + 1;

        	if (j < next)
        		j = next;
        	else
        		return false;
        }

        return true;
    }
};




int main() {
	vector<int> nums = {3,2,1,0,4};

	cout << Solution().canJump(nums) << endl;

	return 0;
}