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
	string s;

    string shortestPalindrome(string _s) {
    	s = _s;

    	if (s.empty() || s.length() == 1)
    		return s;



    	int n = s.length();
    	int min_edit = INT_MAX;
    	string ans = "";

    	for (double c = 0.5; c < n; c += 0.5) {
    		int i,j;
    		string res = "";

    		if (c - (int)c > 0.1) {
    			i = (int)c;
    			j = i + 1;
    		}
    		else {
    			i = (int)(c - 1);
    			j = (int)(c + 1);
    			res = res + s[(int)c];
    		}

    		string s1 = s.substr(0, i + 1);
    		
    		string s2 = s.substr(j);

    		int distance = edit(s1, s2, res);
    		if (distance < min_edit) {
    			min_edit = distance;
    			ans= res;
    		}
    	}

    	return ans;
    }


    int edit(string s1, string s2, string& res) {
		reverse(s1.begin(), s1.end());

		
    }
};





int main() {
	string s = "abcde";
	//cout << Solution().shortestPalindrome(s) << endl;
	double c = 1.5;

	cout <<  c - (int)c << endl;


	return 0;
}