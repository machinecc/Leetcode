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
	int m;
	int n;
	int k;
	string word;
	bool found;

    bool exist(vector<vector<char>>& board, string _word) {
    	if (board.size() == 0 || board[0].size() == 0 || _word.empty())
    		return false;

    	m = board.size();
    	
    	n = board[0].size();

    	word = _word;
    	k = word.size();

    	found = false;


    	for (int i = 0; i < m; ++ i) {
    		for (int j = 0; j < n; ++ j) {
    			//cout << i << ' ' << j << endl;

    			if (traverse(board, i, j, 0) == true)
    				return true;
    		}
    	}

    	return false;
        
    }


    bool traverse(vector<vector<char>>& board, int row, int col, int p) {
    	if (board[row][col] != word[p] || board[row][col] == '\0')
    		return false;

    	if (p == k-1)
    		return true;
    	

    	char ch = board[row][col];
    	board[row][col] = '\0';

    	if (	(row-1 >= 0 && traverse(board, row-1, col, p+1)) ||
    			(row+1 < m  && traverse(board, row+1, col, p+1)) ||
    			(col-1 >= 0 && traverse(board, row, col-1, p+1)) ||
    			(col+1 < n && traverse(board, row, col+1, p+1))
    		) {
    		board[row][col] = ch;
    		return true;
    	}
    	
    	board[row][col] = ch;
    	return false;

    }
};




int main() {
	vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};

	cout << Solution().exist(board, "ABCB") << endl;


	return 0;
}