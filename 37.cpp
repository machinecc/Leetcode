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
	static const int n = 9;
	bool rows[n][n+1];
	bool cols[n][n+1];
	bool sections[n][n+1];

	bool found = false;

	vector<pair<int,int>> positions;
	int m;


    void solveSudoku(vector<string>& board) {
        for (int i = 0; i < n; ++ i) {
        	for (int j = 0; j < n + 1; ++ j) {
        		rows[i][j] = false;
        		cols[i][j] = false;
        		sections[i][j] = false;
        	}
        }

        for (int i = 0; i < n; ++ i) {
        	for (int j = 0; j < n; ++ j) {
        		if (board[i][j] != '.') {
        			int val = board[i][j] - '0';
        			rows[i][val] = true;
        			cols[j][val] = true;
        			sections[i / 3 * 3 + j / 3][val] = true;
        		}
        		else {
        			positions.push_back(make_pair(i,j));
        		}
        	}
        }

        m = positions.size();

        cout << m << endl;

        dfs(board, 0);;
    }

    

    void dfs(vector<string>& board, int idx) {
    	if (idx == m) {
    		found = true;

    		return;
    	}

    	int row = positions[idx].first;
    	int col = positions[idx].second;

    	for (int k = 1; k <= n; ++ k) {
    		if (rows[row][k] == false && cols[col][k] == false && sections[row/3*3+col/3][k] == false) {
    			board[row][col] = k + '0';

    			rows[row][k] = true;
        		cols[col][k] = true;
        		sections[row / 3 * 3 + col / 3][k] = true;

        		dfs(board, idx + 1);

        		if (found == true)
        			return;

				rows[row][k] = false;
        		cols[col][k] = false;
        		sections[row / 3 * 3 + col / 3][k] = false;

    			board[row][col] = '.';
    		}
    	}
    }
};



int main() {
	vector<string> board = {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};

	Solution().solveSudoku(board);


	for (int i = 0; i < board.size(); ++ i)
		cout << board[i] << endl;

	return 0;
}