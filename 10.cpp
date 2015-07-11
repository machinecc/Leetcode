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
	vector<string> patterns;
    vector<int> lengths;
    string s,p;

    int n, m;




    bool isMatch(string _s, string _p) {
    	s = _s;
    	p = _p;

    	m = s.length();
    	n = p.length();

    	return isMatch(0, 0);
    }


    bool isMatch(int i, int j) {
    	if (j == n)
    		return i == m;
    	// p is not of pattern .*/a*
    	if (j + 1 == n || p[j+1] != '*') {
    		return  (i != m) && ( s[i] == p[j] || p[j] == '.' )  && isMatch(i+1, j+1);
    	}

    	// p is of pattern .*/a*
    	while ( (i < m) && ( s[i] == p[j] || p[j] == '.' ) ) {
    		if (isMatch(i, j+2))
    			return true;
    		++i;
    	}

    	return isMatch(i, j + 2);
    }
   
};



int main() {
	cout << Solution().isMatch("bbbba", ".*a*a") << endl;


	return 0;
}