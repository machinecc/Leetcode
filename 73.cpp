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

    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        	return;

        m = matrix.size();
        n = matrix[0].size();





        bool first_row_zero = false;
        bool first_column_zero = false;

        for (int j = 0; j < n; ++ j)
        	if (matrix[0][j] == 0) {
        		first_row_zero = true;
        		break;
        	}

        for (int i = 0; i < m; ++ i)
        	if (matrix[i][0] == 0) {
        		first_column_zero = true;
        		break;
        	}

        for (int i = 0; i < m; ++ i) {
        	for (int j = 0; j < n; ++ j) {
        		if (matrix[i][j] == 0) {
        			matrix[i][0] = 0;
        			matrix[0][j] = 0;
        		}
        	}
        }







        for (int i = 1; i < m; ++ i)
        	if (matrix[i][0] == 0) {
        		for (int j = 0; j < n; ++ j)
        			matrix[i][j] = 0;
        	}


        for (int j = 1; j < n; ++ j)
        	if (matrix[0][j] == 0) {
        		for (int i = 0; i < m; ++ i)
        			matrix[i][j] = 0;
        	}




        if (first_row_zero == true) {
        	for (int j = 0; j < n; ++ j)
        		matrix[0][j] = 0;
        }

        if (first_column_zero == true) {
        	for (int i = 0; i < m; ++ i)
        		matrix[i][0] = 0;
        }


/*
        for (int i = 0; i < m; ++ i) {
        	for (int j = 0; j < n; ++ j)
        		cout << matrix[i][j] << ' ';
        	cout << endl;
        }

        cout << endl << endl;
*/
    }
};


int main() {
	vector<vector<int>> matrix = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};

	Solution().setZeroes(matrix);


	return 0;
}