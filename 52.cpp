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
	vector<string> board;
	vector<bool> l1;
	vector<bool> l2;
	vector<bool> cols;
	int n;
	int count;

    
   	int totalNQueens(int _n) {
    	n = _n;
    	count = 0;

        string line(n, '.');

        board = vector<string>(n, line);
        l1 = vector<bool>(n+n-1, false);
        l2 = vector<bool>(n+n-1, false);
        cols = vector<bool>(n, false);

        dfs(0);

        return count;
    }


    void dfs(int row) {
    	if (row == n) {
    		++ count;
    		return;
    	}

    	for (int col = 0; col < n; ++ col) {
    		if (cols[col] == false && l1[row+col] == false && l2[row-col+n-1] == false) {
    			board[row][col] = 'Q';
    			cols[col] = true;
    			l1[row+col] = true;
    			l2[row-col+n-1] = true;

    			dfs(row+1);

    			cols[col] = false;
    			l1[row+col] = false;
    			l2[row-col+n-1] = false;
    			board[row][col] = '.';
    		}
    	}
    }
};



int main() {
	//vector<vector<string>> ans = Solution().solveNQueens(8);

	// for (int i = 0; i < ans.size(); ++ i) {
	// 	for (int j = 0; j < ans[i].size(); ++ j)
	// 		cout << ans[i][j] << endl;

	// 	cout << endl << endl;
	// }

	//cout << ans.size() << endl;

	cout << Solution().totalNQueens(8) << endl;

	return 0;
}