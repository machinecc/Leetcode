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
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();

        int left = 0;


        int right = n - 1;



       

        while ( left < right ) {
        	while (left < n && nums[left] != val)
        		++ left;
        	while (right >= 0 && nums[right] == val)
			    --right;   

			if (right < 0)
        		return 0;

        	if (left >= right)
        		break;

        	swap(nums[left], nums[right]);

        	++ left;
    }

        if (left == right && nums[left] != val)
        	return left + 1;
        else
        	return left;
        
    }
};


int main() {

	vector<int> data = {3,3};

	cout << Solution().removeElement(data, 3) << endl;

	return 0;
}