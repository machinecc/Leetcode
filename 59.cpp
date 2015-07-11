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
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>> matrix(n, vector<int>(n,0));


		int k = 1;

		for (int i = 0; i <= (n-1)/2; ++ i) {
    		for (int j = i; j <= n - 1 - i; ++ j)
    			matrix[i][j] = k++;

    		for (int j = i + 1; j <= n - 1 - i; ++ j)
    			matrix[j][n-1-i] = k++;

    		if (n - 1 - i != i)
	    		for (int j = n - 1 - i - 1; j >= i; -- j)
    				matrix[n-1-i][j] = k ++;

    		if (n - 1 - i != i)
    			for (int j = n-1-i-1; j > i; -- j)
	    			matrix[j][i] = k++;
    	}        

    	//cout << matrix.size() << endl;
    	return matrix;
    }

};



int main() {
	vector<vector<int>> matrix = Solution().generateMatrix(3);

	for (int i = 0; i < matrix.size(); ++ i) {
		for (int j = 0; j < matrix[i].size(); ++ j) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}


	return 0;
}