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
#include <cmath>
#include <queue>
#include "common.h"


using namespace std;

class Solution {
public:
	bool isMatch_dp(string s, string p) {
    	int m = s.length();
    	int n = p.length();

    	if (n == 0)
    		return (m == 0);

    	vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));

    	dp[0][0] = true;
	
		for (int i = 1; i <= m; ++ i) {
			for (int j = 1; j <= n; ++ j) {
				if (p[j-1] == '*') {
					dp[i][j] = dp[i-1][j-1] || dp[i-1][j] || dp[i][j-1];
				}
				else if (p[j-1] == '?') {
					dp[i][j] = dp[i-1][j-1];
				}
				else {
					dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1]);
				}
			}
		} 

        return dp[m][n];
    }


    bool isMatch(string s, string p) {
		int m = s.length();
    	int n = p.length();

    	if (n == 0)
    		return (m == 0);

    	int i = 0, j = 0;
    	int istar = -1, jstar = -1;

    	while (i < m) {
    		if (p[j] == '*') {
    			istar = i;
    			jstar = j;

    			++ j;
    		}
    		else if (p[j] == '?' || s[i] == p[j]) {
    			++ i;
    			++ j;
    		}
    		else if (jstar != -1 ){
    			j = jstar + 1;
    			i = ++ istar;
    		}
    		else
    			return false;
    	}

    	while (j < n && p[j] == '*')
    		++ j;

    	return j == n;
    }

};




int main() {
	cout << Solution().isMatch("aab", "c*a*b") << endl;


	return 0;
}