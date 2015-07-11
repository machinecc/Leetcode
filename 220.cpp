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
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();

        unordered_map<int, vector<int>> positions;
        vector<int> data;

        for (int i = 0; i < n; ++ i) {
        	if (positions.find(nums[i]) == positions.end()) {
        		positions[nums[i]] = {i};
        		data.push_back(nums[i]);
        	}
        	else {
        		positions[nums[i]].push_back(i);
        	}
        }

        sort(data.begin(), data.end());


        int i = 0, j = 0;

        t = abs(t);

        while (j < data.size()) {
        	while (data[j] - data[i] > t)
        		++ i;

        	vector<int> idx;
        	for (int p = i; p <= j; ++ p) {
        		copy(positions[data[p]].begin(), positions[data[p]].end(), back_inserter(idx));
        	}

        	sort(idx.begin(), idx.end());

        	for (int p = 0; p < idx.size() - 1; ++ p) {
        		if (idx[p+1] - idx[p] <= k)
        			return true;
        	}

        	++j;
        }

        return false;
    }
};



int main() {
	vector<int> nums = {-1, -1};

	cout << Solution().containsNearbyAlmostDuplicate(nums, 1, -1) << endl;


	return 0;
}