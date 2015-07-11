#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = min(height[i], height[j]) * (j - i);

        while (i < j) {
        	int vol = min(height[i], height[j]) * (j - i);
        	
        	if (vol > max) 
        		max = vol;

        	if (height[i] < height[j])
        		++ i;
        	else
        		-- j;
        }

        return max;
    }
};


int main() {



	return 0;
}