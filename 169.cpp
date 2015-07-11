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
    int majorityElement(vector<int>& nums) {
  		int counter = 0;
  		int val = 0;

  		for (int i = 0; i < nums.size(); ++ i) {
  			if (counter == 0) {
  				val = nums[i];
  				++ counter;
  			}
  			else if (val == nums[i])
  				++ counter;
  			else
  				-- counter;
  		}

  		return val;
    }
};


int main() {

	vector<int> nums = {2,2,3,1,2};
	cout << Solution().majorityElement(nums) << endl;

	return 0;
}