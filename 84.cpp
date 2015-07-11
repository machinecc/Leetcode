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
	vector<int> height = {2,1,5,6,2,3};

	cout << Solution().largestRectangleArea(height) << endl;

	return 0;
}