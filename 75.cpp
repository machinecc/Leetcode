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
    void sortColors(vector<int>& nums) {
    	int n = nums.size();

    	if (n <= 1)
    		return;

        int i = 0;
        int p0 = -1;
        int p2 = n;


        while (i < p2) {
        	if (nums[i] == 0) {
        		if (i == p0) {
        			++ i;
        			continue;
        		}

        		++ p0;
        		swap(nums[p0], nums[i]);
        	}
        	else if (nums[i] == 2) {
        		-- p2;
        		swap(nums[p2], nums[i]);
        	}
        	else {
        		++ i;
        	}
        }

    }
};

int main() {

	vector<int> nums = {1,2};

	Solution().sortColors(nums);


	for (int i = 0; i < nums.size(); ++ i)
		cout << nums[i] << ' ';
	cout << endl;

	return 0;
}