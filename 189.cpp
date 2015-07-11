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
    void rotate0(vector<int>& nums, int k) {
    	int n = nums.size();

    	k = k % n;

    	vector<int> cp;
    	cp.assign(nums.begin() + n - k, nums.end());

    	for (int i = n - 1; i >= k; -- i)
    		nums[i] = nums[i - k];

    	copy(cp.begin(), cp.end(), nums.begin());


    	//printvector(nums);

    }


    void rotate(vector<int>& nums, int k) {
    	int n = nums.size();

    	k = k % n;

    	if (k == 0)
    		return;

    	reverse(nums.begin(), nums.begin() + n - k );
    	reverse(nums.begin() + n - k, nums.end());
    	reverse(nums.begin(), nums.end());

    }


    void printvector(vector<int>& nums) {
    	for (int i = 0; i < nums.size(); ++ i)
    		cout << nums[i] << ' ';
    	cout << endl;
    }
};


int main() {
	vector<int> nums = {1,2,3,4,5,6,7,8,9,10};

	Solution().rotate(nums, 3);


	return 0;
}