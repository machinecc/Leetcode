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
  		int n = prices.size();
  		if (n == 0)
  			return 0;      

  		int l[n];
  		int r[n];

  		int min_val = INT_MAX;
  		for (int i = 0; i < n; ++ i) {
  			min_val = min(min_val, prices[i]);
  			if (i > 0)
  				l[i] = max(l[i-1], prices[i] - min_val);
  			else 
  				l[i] = 0;
  		}


  		int max_val = INT_MIN;
  		for (int i = n-1; i >= 0; --i) {
  			max_val = max(max_val, prices[i]);
  			if (i == n-1)
  				r[i] = 0;
  			else
  				r[i] = max(r[i+1], max_val - prices[i]);
  		}


  		int max_profit = INT_MIN;
  		for (int i = 0; i < n-1; ++ i)
  			max_profit = max(max_profit, l[i] + r[i+1]);

  		max_profit = max(max_profit, l[n-1]);

  		return max_profit;
  		
    }
};


int main() {
	vector<int> prices = {1};

	cout << Solution().maxProfit(prices) << endl;


	return 0;
}