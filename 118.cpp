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
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        if (numRows == 0)
        	return ans;

        vector<int> v = {1};

        ans.push_back(v);

        for (int i = 2; i <= numRows; ++ i) {
        	const vector<int>& b = ans.back();

        	v.clear();

        	v.push_back(1);

        	for (int j = 0; j < b.size() - 1; ++ j)
        		v.push_back(b[j] + b[j+1]);

        	v.push_back(1);

        	ans.push_back(v);
        }

    	return ans;

    }

};


int main() {



	return 0;
}