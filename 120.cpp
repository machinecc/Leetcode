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
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();

        if (n == 0)
        	return 0;


        for (int i = 1; i < n; ++ i) {
        	for (int j = 0; j < i+1; ++ j) {
        		if (j == 0)
        			triangle[i][j] = triangle[i-1][j] + triangle[i][j];
        		else if (j == i)
        			triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
        		else
        			triangle[i][j] = min(triangle[i-1][j], triangle[i-1][j-1]) + triangle[i][j];
        	}
        }

        int minval = *min_element(triangle[n-1].begin(), triangle[n-1].end());

        return minval;
    }
};

int main() {
	vector<vector<int>> triangle = {{2}, {3,4}, {6,5,7}, {4,1,8,3}};

	cout << Solution().minimumTotal(triangle) << endl;


	return 0;
}