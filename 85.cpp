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
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        	return 0;


        int n = matrix.size();
        int m = matrix[0].size();


        vector<int> height(m, 0);

        int max_area = 0;

        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < m; ++ j) {
                if (matrix[i][j] == '1')
                    height[j] = height[j] + 1;
                else
                    height[j] = 0;
            }


            max_area = max(max_area, largestRectangleArea(height));
        }

        return max_area;


    }


    int largestRectangleArea(vector<int>& height) {
        int n = height.size();

        if (n == 0)
            return 0;

        height.push_back(-1);

        stack<int> stk;

        int i = 0;
        int maxarea = INT_MIN;

        while (i < height.size()) {
            if (stk.empty() || height[i] >= height[stk.top()]) {
                stk.push(i);
                ++ i;
            }
            else {
                while (!stk.empty() && height[stk.top()] > height[i]) {
                    int top = stk.top();
                    stk.pop();

                    int width = stk.empty()? i : i - stk.top() - 1;
                    maxarea = max(maxarea, height[top] * width);
                }
            }
        }

        return maxarea;
    }
};


int main() {



	return 0;
}