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

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
        	return 0;

        int p = 0;

        for (p = 0; p < n - 1; ++ p) {
        	if (nums[p] > nums[p+1])
        		break;
        }

        return p;
    }
};


int main() {
	vector<int> nums = {1,3,2};

	cout << Solution().findPeakElement(nums) << endl;


	return 0;
}