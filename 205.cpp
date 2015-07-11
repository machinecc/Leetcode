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
#include "common.h"


using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
        	return false;

        convert(s);
        convert(t);


        return s == t;
    }

    void convert(string& s) {
    	int k = 0;

    	unordered_map<char, int> mapping;

    	for (int i = 0; i < s.length(); ++ i) {
    		if (mapping.find(s[i]) == mapping.end()) {
    			mapping[s[i]] = k;
    			++ k;
    		}

    		s[i] = char('0' + mapping[s[i]]);
    	}
    }
};



int main() {
	cout << Solution().isIsomorphic("paper", "title") << endl;


	return 0;
}