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
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        if (m == 0)
        	return 0;

        if (n == 0)
        	return 1;


        int dp[m+1][n+1];

        for (int i = 0; i <= m; ++ i) {
        	for (int  j = 0; j <= n; ++ j) {
        		if (i == 0 && j == 0) {
        			dp[i][j] = 1;
        		}
        		else if (i == 0) {
        			dp[i][j] = 0;
        		}
        		else if (j == 0) {
        			dp[i][j] = 1;
        		}
        		else {
        			dp[i][j] = dp[i-1][j];
        			if (s[i-1] == t[j-1])
        				dp[i][j] += dp[i-1][j-1];
        		}

        		//cout << dp[i][j] << ' ';
        	}
        	//cout << endl;
        }

        //cout << endl;

        return dp[m][n];
    }
};


int main() {
	cout << Solution().numDistinct("rabbbit", "rabbit") << endl;


	return 0;
}