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
    int maxProduct(vector<int>& nums) {
    	int n = nums.size();

    	if (n == 0)
    		return 0;

    	if (n == 1)
    		return nums[0];


        int zeros[n];
        int minus[n];


        for (int i = 0; i < n; ++ i)
        	if (i == 0) {
        		zeros[i] = (nums[i] == 0) ? 1 : 0;
        		minus[i] = (nums[i] < 0) ? 1 : 0;
        	}
        	else {
        		zeros[i] = (nums[i] == 0) ? 1 + zeros[i-1] : 0 + zeros[i-1];
        		minus[i] = (nums[i] < 0) ? 1 + minus[i-1] : 0 + minus[i-1];	
        	}


        int i = 0;
        int j = 0;

        int max_product = INT_MIN;


        for (int i = 0; i < n; ++ i) {
        	int product = 1;
        	
        }

    }
};


int main() {



	return 0;
}