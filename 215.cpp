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
    int findKthLargest(vector<int>& nums, int k) {
    	priority_queue<int, vector<int>, greater<int>> minheap;


    	for (int i = 0; i < nums.size(); ++ i) {
    		minheap.push(nums[i]);

    		if (minheap.size() > k)
    			minheap.pop();
    	}    


    	return minheap.top();
    }
};



int main() {
	vector<int> nums = {1,2,3,4,5,6};
	int k = 2;

	cout << Solution().findKthLargest(nums, k) << endl;


	return 0;
}