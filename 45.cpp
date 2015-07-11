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
    int jump(vector<int>& nums) {
        int i = 0, j = 0, step = 0;
        int n = nums.size();

        while (j < n - 1) {
        	int next = 0;

        	for (int k = i; k <= j; ++ k) {
        		if (k >= n)
        			break;
        		next = max(next, k + nums[k]);
        	}

        	i = j + 1;
        	j = next;
        	++ step;

        }

        return step;
    }
};



int main() {

	vector<int> nums = {2,3,1,1,4};

	cout << Solution().jump(nums) << endl;


	return 0;
}