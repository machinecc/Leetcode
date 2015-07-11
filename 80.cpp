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
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
        	return n;

        int len = 0;

        int mark = 0;

        for (int i = 0; i < n; ++ i) {
        	if (i == 0) {
        		mark = 1;
        		
        		nums[len] = nums[i];
        		++ len;
        	}
        	else if (nums[i] != nums[i-1]) {
        		mark = 1;
        		nums[len] = nums[i];

        		++ len;
        	}
        	else if (mark < 2) {
        		++ mark;
        		nums[len] = nums[i];

        		++ len;
        	}
        }

        return len;
    }
};


int main() {
	vector<int> nums = {1,1,1,2,2,2,3,3,3};
	cout << Solution().removeDuplicates(nums) << endl;

	for (int i = 0; i < nums.size(); ++ i)
		cout << nums[i] << endl;


	return 0;
}