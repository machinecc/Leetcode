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
    bool containsDuplicate(vector<int>& nums) {
    	if (nums.empty())
    		return false;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; ++ i)
        	if (nums[i] == nums[i+1])
        		return true;

        return false;
    }
};


int main() {



	return 0;
}