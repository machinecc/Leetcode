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
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    	if (nums.empty())
    		return false;


    	int n = nums.size();

        unordered_map<int,int> counts;


        int i = 0;
        for (i = 0; i < min(n, k+1); ++ i) {
        	if (counts[nums[i]] > 0)
        		return true;
        	counts[nums[i]] = 1;
        }



        int j = i - 1;
        i = 0;

        //cout << "i = " << i << "      j = " << j << endl;

        while (j < n - 1) {
        	counts[nums[i]] -= 1;
        	++ i;


        	++ j;
        	if (counts[nums[j]] > 0) {
        		//cout << j << ' ' << nums[j] << endl;
        		return true;
        	}
        	counts[nums[j]] = 1;
        }


        return false;
    }
};




int main() {
	vector<int> nums = {1,2,3,4,5,3,2,1};
	cout << Solution().containsNearbyDuplicate(nums, 4) << endl;


	return 0;
}