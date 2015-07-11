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
    int maxProfit(vector<int>& prices) {
    	if (prices.size() == 0)
    		return 0;

    	int n = prices.size();

        int min_from_left[n];

        for (int i = 0; i < n; ++ i) {
        	if (i == 0)
        		min_from_left[i] = prices[i];
        	else
        		min_from_left[i] = min(prices[i], min_from_left[i-1]);
        }

        int max_val = INT_MIN;

        for (int i = 0; i < n; ++ i)
        	max_val = max(prices[i] - min_from_left[i], max_val);

        return max_val;

    }
};

int main() {
	vector<int> prices = {1};
	cout << Solution().maxProfit(prices) << endl;

	return 0;
}