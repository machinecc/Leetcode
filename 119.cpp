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
    vector<int> getRow(int rowIndex) {
        int m = rowIndex;

        double val;

        vector<int> ans;

        for (int n = 0; n <= m; ++ n) {
        	if (n == 0)
        		val = 1;
        	else {
        		val = val * (m - (n - 1)) / n;
        	}

        	ans.push_back((int)val);
        }

        // for (int i = 0; i < ans.size(); ++ i)
        // 	cout << ans[i] << ' ';
        // cout << endl;

        return ans;
    }
};


int main() {

	Solution().getRow(32);

	return 0;
}