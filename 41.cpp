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
	int n;

    int firstMissingPositive(vector<int>& nums) {
        //int n = nums.size();
    	n = nums.size();

    	nums.push_back(0);


    	int i = 0;
    	int j = 0;

    	while (i < n) {
    		int val = nums[i];
    		if (is_in_range(val) == false)
    			++i;
    		else  if (val == i)
    			++ i;
    		else {
    			if (nums[val] != val)
    				swap(nums[i], nums[val]);
    			else
    				++ i;
    		}
    	}

    	int ans = -1;

    	for (int i = 1; i <= n; ++ i)
    		if (nums[i] != i) {
    			ans = i;
    			break;
    		}

    	if (ans == -1)
    		ans = n + 1;

    	return ans;
    }

    inline bool is_in_range(int k) {
    	if (k < 1 || k > n)
    		return false;
    	else 
    		return true;
    }
};


int main() {
	vector<int> nums = {1,4,2,2};

	cout << Solution().firstMissingPositive(nums) << endl;


	return 0;
}