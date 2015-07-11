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
#include <queue>

using namespace std;


void printvector(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++ i)
		cout << nums[i] << ' ';
	cout << endl;
}


class Solution {
public:
	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	int m = 0;
	int n = 0;



    int numIslands(vector<vector<char>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;

		m = grid.size();
		n = grid[0].size();
		int count = 0;

		for (int i = 0; i < m; ++ i) {
			for (int j = 0; j < n; ++ j) {
				if (grid[i][j] == '0')
					continue;

				++ count;

				iterate(grid, i, j);			
			}
		}

		return count;        
    }


    void iterate(vector<vector<char>>& grid, int x, int y) {
    	grid[x][y] = '0';

		for (int direction = 0; direction < 4; ++ direction) {
			int xs = x + dx[direction];
			int ys = y + dy[direction];

			if (0 <= xs && xs < m && 0 <= ys && ys < n && grid[xs][ys] == '1') {
				iterate(grid, xs, ys);
			}
		}

    }
};



int main() {
	vector<vector<char>> grid = {{'1','1','1','1','0'}, {'1','1','0','1','0'}, {'1','1','0','0','0'}, {'0','0','0','0','0'}};
	//vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};

	cout << Solution().numIslands(grid) << endl;


	return 0;
}