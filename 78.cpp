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


using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;

        if (nums.size() == 0)
        	return ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> v;

        ans.push_back(v);

        for (int i = 0; i < nums.size(); ++ i) {
        	int num = nums[i];

        	int m = ans.size();
        	for (int j = 0; j < m; ++ j) {
        		v = ans[j];
        		v.push_back(num);
        		ans.push_back(v);
        	}
        }

        return ans;
    }
};


int main() {

	vector<int> nums = {1,2,3};

	vector<vector<int>> ans = Solution().subsets(nums);

	for (int i = 0; i < ans.size(); ++ i) {
		vector<int>& v = ans[i];

		for (int j = 0; j < v.size(); ++ j)
			cout << v[j] << ' ';

		cout << endl;
	}

	return 0;
}