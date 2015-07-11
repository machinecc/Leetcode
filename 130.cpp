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

struct Position {
	int x;
	int y;

	Position(int x, int y): x(x), y(y) {}
};

class Solution {
public:
	int m;
	int n;

    void solve(vector<vector<char>>& board) {
    	if (board.size() == 0 || board[0].size() == 0)
    		return;

        m = board.size();
        n = board[0].size();

        bool visited[m][n];

        for (int i = 0; i < m; ++ i) {
        	for (int j = 0; j < n; ++ j) {
        		visited[i][j] = false;
        	}
        }

        vector<Position> v;

        for (int i = 0; i < m; ++ i) {
        	for (int j = 0; j < n; ++ j) {
        		

        		if (board[i][j] != 'O' || visited[i][j] == true)
        			continue;

        		v.clear();

        		v.push_back(Position(i,j));

        		int p = 0;
        		bool surrounded = true;

        		while (p < v.size()) {
        			int x = v[p].x;
        			int y = v[p].y;

        			if (visited[x][y] == false) {
        				visited[x][y] = true;

        				if (is_on_perimeter(x,y))
        					surrounded = false;

        				if ( is_valid(x-1, y) && board[x-1][y] == 'O' && visited[x-1][y] == false )
        					v.push_back(Position(x-1,y));

        				if ( is_valid(x+1, y) && board[x+1][y] == 'O' && visited[x+1][y] == false )
        					v.push_back(Position(x+1,y));

        				if ( is_valid(x, y-1) && board[x][y-1] == 'O' && visited[x][y-1] == false )
        					v.push_back(Position(x,y-1));

        				if ( is_valid(x, y+1) && board[x][y+1] == 'O' && visited[x][y+1] == false )
        					v.push_back(Position(x,y+1));
        			}

        			++p;
        		}

        		if (surrounded == true) {
        			for (auto it = v.begin(); it != v.end(); ++ it) {
        				int x = it->x;
        				int y = it->y;

        				board[x][y] = 'X';
         			}
        		}
        	}
        }
    }


    bool is_on_perimeter(int x, int y) {
    	if (x == 0 || x == m-1 || y == 0 || y == n-1)
    		return true;
    	else
    		return false;
    }

    bool is_valid(int x, int y) {
    	return (0 <= x && x <= m-1 && 0 <= y && y <= n-1);
    }
};


int main() {
	vector<vector<char>> board = {{'X','O','X','O','X','O'},{'O','X','O','X','O','X'},{'X','O','X','O','X','O'},{'O','X','O','X','O','X'}};


	int m = board.size();
	int n = board[0].size();

	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

	cout << endl << endl;

	Solution().solve(board);


	for (int i = 0; i < m; ++ i) {
		for (int j = 0; j < n; ++ j) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}


	return 0;
}