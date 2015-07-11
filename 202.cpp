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
    bool isHappy(int n) {
    	unordered_set<int> hist;
    	hist.insert(n);

    	bool ans = true;

		while (n != 1) {
			int sum = 0;

			while (n > 0) {
				sum = sum + (n % 10) * (n % 10);
				n = n / 10;
			}

			n = sum;

			if (hist.find(n) == hist.end())
				hist.insert(n);
			else {
				ans = false;
				break;
			}
		}

		return ans;      
    }
};



int main() {

	cout << Solution().isHappy(200) << endl;

	return 0;
}