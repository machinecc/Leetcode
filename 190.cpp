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
    uint32_t reverseBits(uint32_t n) {
    	uint32_t result = 0;
    	uint32_t b = 0;

        for (int i = 0; i < 32; ++ i) {
        	b = n % 2;
        	n = n / 2;

        	result = result * 2 + b;
        }

        return result;
    }
};


int main() {

	cout << Solution().reverseBits(0) << endl;


	return 0;
}