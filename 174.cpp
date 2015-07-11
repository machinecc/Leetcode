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
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int m = dungeon.size();
		int n = dungeon[0].size();


		int demand[m][n];
		int remain[m][n];

		if (dungeon[0][0] > 0) {
			demand[0][0] = 0;
			remain[0][0] = 
		}


    }



};

int main() {



	return 0;
}