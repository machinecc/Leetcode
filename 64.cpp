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


    int minPathSum(vector<vector<int>>& grid) {
    	if (grid.size() == 0 || grid[0].size() == 0)
    		return 0;

        int m = grid.size();

        int n = grid[0].size();


        int* dp = new int[n];

        for (int j = 0; j < n; ++ j)
            dp[j] = INT_MAX;

        dp[0] = 0;

        for (int i = 0; i < m; ++ i) {
            dp[0] = dp[0] + grid[i][0];

            for (int j = 1; j < n; ++ j) {
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
            }
/*
            for (int j = 0; j < n; ++j)
            {
                cout << dp[j] << ' ';
            }

            cout << endl;
*/
        }



        int ans = dp[n-1];

        delete [] dp;

        return ans;
    }



};


int main() {
	vector<vector<int>> grid = {{2,0}};

	cout << Solution().minPathSum(grid) << endl;

	return 0;
}