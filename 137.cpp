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
    int singleNumber(vector<int>& nums) {
		int n = nums.size();

		vector<int> bits(32,0);


		for (int i = 0; i < n; ++ i) {

			for (int j = 0; j < 32; ++ j) {
				if (nums[i] >> j == 0)
					break;

				bits[j] += (nums[i] >> j) & 1;
			}
		}        


		int val = 0;

		for (int j = 0; j < 32; ++ j)
			val += (bits[j] % 3) << j;

		if (n % 3 == 2)
			val = val / 2;

		return val;
    }
};



int main() {

	vector<int> nums = {1,1,1,2,2};

	cout << Solution().singleNumber(nums) << endl;

	return 0;
}