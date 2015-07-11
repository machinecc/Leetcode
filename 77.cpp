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
    vector<vector<int>> combine(int n, int k) {
    	vector<vector<int>> ans;

    	if (n == 0 || k == 0 || n < k)
    		return ans;

  		vector<int> indicators(n-k, 0);

  		for (int i = 1; i <= k; ++ i)
  			indicators.push_back(1);

		vector<int> v;

  		do {
  			

  			for (int i = 1; i <= n; ++ i)
  				if (indicators[i-1] == 1)
  					v.push_back(i);

  			ans.push_back(v);

  			// for (int i = 0; i < v.size(); ++ i)
  			// 	cout << v[i] << ' ';

  			// cout << endl;

  			v.clear();	

  		} while (next_permutation(indicators.begin(), indicators.end()));

  		return ans;

    }
};


int main() {
	vector<vector<int>> ans = Solution().combine(4,2);



	return 0;
}