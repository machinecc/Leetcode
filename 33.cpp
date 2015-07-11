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
	int target;

	int position;

	int n;

    int search(vector<int>& nums, int _target) {
    	n = nums.size();

    	target = _target;

    	position = -1;

    	bsearch(nums, 0, n - 1);

    	return position;
    }

    void bsearch(vector<int>& nums, int left, int right) {
    	if (left < 0 || right >= n || left > right)
    		return;

    	if (left == right) {
    		if (nums[left] == target) {
    			position = left;
    			return;
    		}
    		else
    			return;
    	}

    	int mid = (left + right) / 2;


    	if (contains(nums, left, mid))
    		bsearch(nums, left, mid);

    	if (contains(nums, mid+1, right))
    		bsearch(nums, mid+1, right);
    }


	bool contains(vector<int>& nums, int left, int right) {
		if (left < 0 || right >= n)
			return false;

		if (nums[left] < nums[right]) {
			if (nums[left] <= target && target <= nums[right])
				return true;
			else 
				return false;
		}
		else {
			if (nums[left] <= target || target <= nums[right])
				return true;
			else
				return false;
		}
	}
};




int main() {

	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

	cout << Solution().search(nums, 2) << endl;

	return 0;
}