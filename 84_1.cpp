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



        int maxarea = INT_MIN;

        for (int i = 0; i < n; ++ i) {
        	int mh = height[i];
        	for (int j = i; j < n; ++ j) {
        		mh = min(mh, height[j]);
        		maxarea = max(maxarea, mh * (j-i+1));
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