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
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        int pos = -1;

        while (left <= right) {
        	int mid = (left + right) / 2;


        	//cout << "left = " << left << "  mid = " << mid << "  right = " << right << endl;
			//cout << "midele value = " << nums[mid] << " " << target << endl << endl;

        	if (nums[mid] < target) {
        		left = mid + 1;
        	}
        	else {
        		right = mid;
        	}

        	//cout << "left = " << left << "  mid = " << mid << "  right = " << right << endl << endl << endl;


        	if (right - left < 2) {
        		if (nums[left] >= target)
        			pos = left;
        		else if (nums[right] >= target)
        			pos = right;
        		else if (nums[right] < target)
        			pos = right + 1;
        		break;
        	}
        }
        return pos;
    }
};


int main() {

	vector<int> nums = {1,2,3,4,5,10};

	cout <<  Solution().searchInsert(nums, 2) << endl;;

	return 0;
}