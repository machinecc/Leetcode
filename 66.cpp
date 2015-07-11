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
    vector<int> plusOne(vector<int>& digits) {
		int n = digits.size();

		int p = n - 1;

		digits[p] += 1;

		while (p > 0) {
			if (digits[p] > 9) {
				digits[p] -= 10;
				digits[p-1] += 1;
				--p;
			}
			else
				break;
		}	      

		if (digits[0] > 9) {
			digits[0] -= 10;
			digits.insert(digits.begin(), 1);
		}

		return digits;
    }

};



int main() {
	vector<int> digits = {0};

	vector<int> ans = Solution().plusOne(digits);

	for (int i = 0; i < ans.size(); ++ i)
		cout << ans[i] << ' ';
	cout << endl;


	return 0;
}