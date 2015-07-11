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


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    	if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1)
    		return 0;

        int m = obstacleGrid.size();

        int n = obstacleGrid[0].size();

        
        int ** dp = new int*[m+1];	
        
        for (int i = 0; i < m+1; ++ i)
        	dp[i] = new int[n+1];


        for (int i = 0; i < m+1; ++ i)
        	for (int j = 0; j < n+1; ++ j)
        		dp[i][j] = 0;

        dp[1][1] = 1;

        for (int i = 1; i <= m; ++ i) {
        	for (int j = 1; j <= n; ++ j) {
        		if (i == 1 && j == 1)
        			continue;
        		if (obstacleGrid[i-1][j-1] == 1)
        			dp[i][j] = 0;
        		else
        			dp[i][j] = dp[i-1][j] + dp[i][j-1];
        	}
        }


        int ans = dp[m][n];

        //cout << "ans = " << ans << endl;
		for (int i = 0; i < m; ++ i)
        	delete [] dp[i];

        delete [] dp;

        return ans;
    }



};


int main() {
	vector<vector<int>> obstacleGrid = {{0,0}};

	cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;

	return 0;
}