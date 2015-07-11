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
    int findMin(vector<int>& nums) {
    	int n = nums.size();
    	if (n == 1)
    		return nums[0];

    	int left = 0;
    	int right = n - 1;

    	while (left < right) {
    		int mid = (left + right) / 2;

    		if (nums[left] < nums[mid]) {
    			left = mid;
    		}
    		else {
    			
    		}
    	}

        
    }



};


int main() {



	return 0;
}