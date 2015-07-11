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
	int n;
	int target;


    vector<int> searchRange(vector<int>& nums, int _target) {
    	n = nums.size();
    	target = _target;
		
		int left = 0;
		int right = n - 1;

		int left_pos = -1;

		while ( left <= right ) {
			int mid = (left + right) / 2;

			if (nums[mid] < target) {
				left = mid + 1;
			}
			else {
				right = mid;
			}

			if (right - left < 2) {
				if (nums[left] == target)
					left_pos = left;
				else if (nums[right] == target)
					left_pos = right;
				break;
			}
		}    	

		//cout << "left position = " << left_pos << endl << endl;

		left = 0;
		right = n - 1;
		int right_pos = -1;

		while (left <= right) {
			int mid = (left + right) / 2;

			//cout << "left = " << left << "  mid = " << mid << "  right = " << right << endl;
			//cout << "midele value = " << nums[mid] << " " << target << endl << endl;



			if (nums[mid] > target) {
				right = mid - 1;
			}
			else {
				left = mid;
			}

			if (right - left < 2) {
				if (nums[right] == target)
					right_pos = right;
				else if (nums[left] == target)
					right_pos = left;
				break;
			}
		}

		//cout << "right position = " << right_pos << endl << endl;


		vector<int> ans;
		ans.push_back(left_pos);
		ans.push_back(right_pos);


        return ans;

    }


    
};




int main() {

	vector<int> nums = {4};

	vector<int> ans = Solution().searchRange(nums, 5);

	//for (int i = 0; i < ans.size(); ++ i)
	//	cout << ans[i] << endl;

	return 0;
}