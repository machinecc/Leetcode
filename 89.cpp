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
#include <bitset>


using namespace std;


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans = {0};

        int t = 1;

        for (int i = 1; i <= n; ++ i) {
        	

        	int len = ans.size();

        	for (int j = len - 1; j >= 0; -- j)
        		ans.push_back(ans[j] + t);

        	t = t << 1;
        }

        return ans;
    }
};

int main() {
	const int n = 3;

	vector<int> ans = Solution().grayCode(n);

	for (int i = 0; i < ans.size(); ++ i)
		cout << bitset<n>(ans[i]) << endl;


	return 0;
}