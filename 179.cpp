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

bool comp(string& s1, string& s2) {
	if (s1 + s2 > s2 + s1)
		return true;
	else
		return false;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
    	if (accumulate(nums.begin(), nums.end(), 0) == 0)
    		return "0";

        vector<string> strs;

        for (int i = 0; i < nums.size(); ++ i) 
        	strs.push_back(to_string(nums[i]));
        

        sort(strs.begin(), strs.end(), comp);

        string ans = "";

        for (int i = 0; i < strs.size(); ++ i)
        	ans = ans + strs[i];

        return ans;
    }
};


int main() {
	vector<int> nums = {0, 0};

	cout << Solution().largestNumber(nums) << endl;


	return 0;
}