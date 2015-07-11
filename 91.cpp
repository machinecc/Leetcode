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
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
        	return 0;

        int n = s.size();

        vector<int> dp(n+1 , 0);

        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; ++ i) {
        	int val = (s[i-2] - '0') * 10 + (s[i-1] - '0');

        	if (s[i-1] == '0') {
        		dp[i] = dp[i-2];
        	}
        	else if (val > 0 && val <= 26) {
        		dp[i] = dp[i-2] + dp[i-1];
        	}
        	else
        		dp[i] = dp[i-1];

        }

        return dp[n];
    }

};


        	//cout << i << " " << dp[i] << endl;
        	//cout << val << endl << endl;
int main() {
	cout << Solution().numDecodings("100") << endl;


	return 0;
}