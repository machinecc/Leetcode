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
#include <cmath>
#include <queue>
#include "common.h"


using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = { {'I',1},  {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

        int ans = 0;

        for (int i = 0; i < s.length(); ++ i) {
        	if (i > 0 && val[s[i]] > val[s[i-1]]) {
        		ans += val[s[i]] - 2 * val[s[i-1]];
        	}
        	else {
        		ans += val[s[i]];
        	}
        }

        return ans;

    }
};



int main() {
	cout << Solution().romanToInt("DCXXI") << endl;


	return 0;
}