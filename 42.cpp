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

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size();
    	int* max_from_right = new int[n];

    	max_from_right[n-1] = 0;

    	for (int i = n-2; i >= 0; -- i)
    		max_from_right[i] = max(max_from_right[i+1], height[i+1]);


    	int i = 0;
    	
    	while (i < n && height[i] == 0)
    		++ i;

    	if (i == n)
    		return 0;

    	int j = 0;
    	int sum = 0;

    	while ( i < n - 1 ) {
    		if (max_from_right[i] == 0)
    			break;

    		j = i + 1;

    		if (max_from_right[i] <= height[i]) {
    			while (height[j] != max_from_right[i])
    				++ j;	
    		}
    		else {
    			while (height[j] < height[i])
    				++j;
    		}

    		// calculate water trap in section (i, j)
    		int h = min(height[i], height[j]);
    		
    		int p = 0;
    		for (int k = i + 1; k <= j - 1; ++ k) {
    			p += min(h, height[k]);
    		}

    		sum += (j - i - 1) * min(height[i], height[j]) - p;

    		i = j; 
    	}

    	return sum;
    }
};


int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout << Solution().trap(height) << endl;


	return 0;
}