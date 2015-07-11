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
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

  	    vector<int> v;
        ans.push_back(v);

        int num;

        for (int i = 0; i < n; ++ i) {
        	int num = nums[i];

        	int m = ans.size();

        	for (int j = 0; j < m; ++ j) {
        		v = ans[j];
        		v.push_back(num);

        		bool is_duplicate = false;

        		for (int k = 0; k < m; ++ k) {
        			if (vector_equal(v, ans[k])) {
        				is_duplicate = true;
        				break;
        			}
        		}

        		if (is_duplicate == false) {
					ans.push_back(v);
        		}

        	}


        }

        return ans;

    }

    bool vector_equal(vector<int>& a, vector<int>& b) {
    	if (a.size() != b.size())
    		return false;

    	for (int i = 0; i < a.size(); ++ i)
    		if (a[i] != b[i])
    			return false;

    	return true;
    }
};

int main() {
	vector<int> nums = {4,1,0};
	vector<vector<int>> ans = Solution().subsetsWithDup(nums);

	for (int i = 0; i < ans.size(); ++i) {
		vector<int>& v = ans[i];

		for (int j = 0; j < v.size(); ++ j)
			cout << v[j] << ' ';

		cout << endl;
	}

	return 0;
}