#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool valid = true;

        int n = 9;

        for (int i = 0; i < board.size(); ++ i) {
        	if (if_contains_duplicates(board[i]) == true)
        		return false;
        }

        for (int i = 0; i < n; ++i) {
        	vector<char> chs;
        	for (int j = 0; j < n; ++ j)
        		chs.push_back(board[j][i]);
        	if (if_contains_duplicates(chs) == true)
        		return false;
        }

        vector<vector<char>> sections;

        for (int i = 0; i < n; ++ i)
        	sections.push_back(vector<char>());

        for (int i = 0; i < n; ++ i)
        	for (int j = 0; j < n; ++ j){
        		int p = i / 3;
        		int q = j / 3;

        		int s = p * 3 + q;
        		sections[s].push_back(board[i][j]);
        	}
        	
        for (int i = 0; i < n; ++ i)
        	if (if_contains_duplicates(sections[i]) == true)
        		return false;

        return true;

    }

    bool if_contains_duplicates(vector<char> v) {
    	unordered_set<char> charset;

    	for (auto it = v.begin(); it != v.end(); ++ it) {
    		if (*it != '.') {
    			if (charset.find(*it) != charset.end())
    				return true;
    			else
    				charset.insert(*it);
    		}
    	}

    	return false;
    }
};


int main() {



	return 0;
}