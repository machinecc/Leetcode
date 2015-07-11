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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        	return false;

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n - 1;
        int row = -1;

        if (n == 1)
        	row = 0;
        else {
	        while (left <= right) {
	        	int mid = left + (right - left) / 2;
	        	//cout << left << ' ' << mid << ' ' << right << endl;
	        	if (matrix[mid][0] == target) {
	        		row = mid;
	        		break;
	        	}
	        	else if (matrix[mid][0] > target) {
	        		right = mid - 1;
	        	}
	        	else {
	        		if (left != mid)
						left = mid;
					else {
						if (matrix[mid+1][0] <= target)
							row = mid + 1;
						else
							row = mid;
						break;
					}
	        	}
	        }
        }

        if (row < 0)
        	return false;

        left = 0;
        right = m - 1;
        

        while (0 <= left && left <= right && right < m) {
        	int mid = (left + right) / 2;

        	if (matrix[row][mid] == target)
        		return true;
        	else if (matrix[row][mid] < target)
        		left = mid + 1;
        	else
        		right = mid - 1;
        }

        return false;
    }
};

int main() {
	vector<vector<int>> matrix = {{1},{3}};

	cout << Solution().searchMatrix(matrix, 0) << endl;


	return 0;
}