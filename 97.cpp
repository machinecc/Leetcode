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
	int m;
	int n;

    bool isInterleave(string s1, string s2, string s3) {
        m = s1.size();
        n = s2.size();


        if ( m + n != s3.size() )
        	return false;

        if ( n == 0 )
        	return s1 == s3;

        if ( m == 0 )
        	return s2 == s3;



        int count[26] = {0};
        for (int i = 0; i < m; ++ i)
        	count[s1[i] - 'a'] += 1;
        for (int i = 0; i < n; ++ i)
        	count[s2[i] - 'a'] += 1;

        for (int i = 0; i < s3.size(); ++ i)
        	count[s3[i] - 'a'] -= 1;

        for (int i = 0; i < 26; ++ i)
        	if (count[i] != 0)
        		return false;


        bool dp[m+1][n+1];


        for (int i = 0; i <= m; ++ i) {
        	for (int j = 0; j <= n; ++ j) {

        		if (i == 0 && j == 0) {
        			dp[i][j] = true;
        		}
        		else if (i == 0) {
					dp[i][j] =  (s2[j-1] == s3[i+j-1]) && dp[i][j-1];        			
        		}
        		else if (j == 0) {
					dp[i][j] =  (s1[i-1] == s3[i+j-1]) && dp[i-1][j];	        			
        		}
        		else{
        			dp[i][j] =  ( (s1[i-1] == s3[i+j-1]) && dp[i-1][j] ) || ( (s2[j-1] == s3[i+j-1]) && dp[i][j-1]) ;
        		}
        	}
        }

        return dp[m][n];
    }
};

int main() {
	cout << Solution().isInterleave("aabcc","dbbca","aadbbbaccc") << endl;


	return 0;
}