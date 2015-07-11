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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ans;

    	if (matrix.empty() || matrix[0].empty())
    		return ans;


    	int m = matrix.size();
    	int n = matrix[0].size();



    	for (int i = 0; i <= min( (m-1)/2, (n-1)/2 ); ++ i) {
    		for (int j = i; j <= n - 1 - i; ++ j)
    			ans.push_back(matrix[i][j]);

    		for (int j = i + 1; j <= m - 1 - i; ++ j)
    			ans.push_back(matrix[j][n-1-i]);

    		if (m - 1 - i != i)
	    		for (int j = n - 1 - i - 1; j >= i; -- j)
    				ans.push_back(matrix[m-1-i][j]);

    		if (n - 1 - i != i)
    			for (int j = m-1-i-1; j > i; -- j)
	    			ans.push_back(matrix[j][i]);
    	}


    	return ans;
    }
};




int main() {

	vector<vector<int>> matrix = {{1},{2},{3},{4}};

	vector<int> ans = Solution().spiralOrder(matrix);

	printvector(ans);

	return 0;
}