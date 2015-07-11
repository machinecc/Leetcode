#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int n = nums.size();

    	if (n <= 1)
    		return n;

    	int left = 0;
    	int right = 1;

    	while ( right < n ){
    		while (right < n && nums[right] <= nums[left])
    			++ right;

    		//cout << "left = " << left << "     " << "right = " << right << endl;
    		
    		if (right >= n)
    			return left + 1;

    		++ left;
    		swap(nums[left], nums[right]);

    		++ right;
    	}

    	return left + 1;
    }
};


int main() {
	vector<int> data = {0, 1, 1, 2, 2, 2, 3};

	cout << Solution().removeDuplicates(data) << endl;


	return 0;
}