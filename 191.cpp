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


void printvector(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++ i)
		cout << nums[i] << ' ';
	cout << endl;
}

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int count = 0;

        while (n > 0) {
        	count += n % 2;
        	n = n / 2;
        }

        return count;
    }
};



int main() {

	cout << Solution().hammingWeight(11) << endl;

	return 0;
}