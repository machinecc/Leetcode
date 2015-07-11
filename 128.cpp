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
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;

        for (int i = 0; i < nums.size(); ++ i)
        	s.insert(nums[i]);


        int max_len = 0;

        for (int i = 0; i < nums.size(); ++ i) {
        	int k = nums[i];
        	int len = 0;

        	if (s.find(k) != s.end()) {
        		++ len;
        		s.erase(k);

        		int prev = k - 1;

        		while (s.find(prev) != s.end()) {
        			++ len;
        			s.erase(prev);
        			prev -= 1;
        		}


        		int next = k + 1;

        		while (s.find(next) != s.end()) {
        			++ len;
        			s.erase(next);
        			next += 1;
        		}
        	}

        	max_len = max(max_len, len);
        }

        return max_len;
    }
};

int main() {

	vector<int> nums = {};

	cout << Solution().longestConsecutive(nums) << endl;

	return 0;
}