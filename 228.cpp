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
#include <cmath>
#include <queue>
#include "common.h"


using namespace std;


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    	vector<string> ans;

    	if (nums.empty())
    		return ans;


  		int i = 0, j = 0;
  		int n = nums.size();

  		while (j < n) {
  			
  			while (j < n - 1 && nums[j+1] - nums[j] == 1)
  				++ j;

  			if (j == i) {
  				ans.push_back(to_string(nums[i]));
  			}
  			else {
  				string s = to_string(nums[i]) + "->" + to_string(nums[j]);
  				ans.push_back(s);
  			}

  			i = j + 1;
  			j = i;
  		}

  		return ans;

    }
};



int main() {
	vector<int> nums = {0,1,2,4,5,7};

	vector<string> ans = Solution().summaryRanges(nums);

	for (auto it : ans) {
		cout << (it) << endl;
	}



	return 0;
}