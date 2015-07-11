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
#include <regex>
#include "common.h"


using namespace std;


class Solution {
public:
    bool isNumber(string s) {
    	if (s.empty())
    		return false;

    	int pos = 0;

    	while (pos < s.length() && (s[pos] != 'e' && s[pos] != 'E'))
    		++ pos;

    	//cout << pos << endl;

    	if (pos < s.length()) {
    		string s1 = s.substr(0, pos);
    		string s2 = s.substr(pos+1);

    		//cout << "\"" << s1 << "\"" << endl;
    		//cout << s2 << endl;
    		return isFloat(s1) && isFloat(s2);
    	}
    	else
    		return isFloat(s);



        return true;
    }

    bool isFloat(string s) {
        if (s.empty())
        	return false;

        int p = 0, n = s.length();


        while ( p < n && isspace(s[p]) )
        	++p;

        if (p == n || (isdigit(s[p]) == false && issign(s[p] == false)))
        	return false;

        int sign = 0;

        if (issign(s[p]) == true) {
        	sign = (s[p] == '-') ? -1 : 1;
        	++p;
        } 


        bool dot = false;
        bool number_before_dot = false;
        bool number_after_dot = false;


        while (p < n) {
        	//cout << s[p] << endl;
        	if (isdigit(s[p])) {
        		if (dot == false)
        			number_before_dot = true;
        		else
        			number_after_dot = true;
        	}
        	else {
        		if (s[p] == '.' && dot == false)
        			dot = true;
        		else
        			break;
        	}

        	++p;
        }

        //cout << number_before_dot << endl;
        //cout << number_after_dot << endl << endl;
        if (dot == true && (!number_before_dot && !number_after_dot))
        	return false;

        if (sign != 0 && dot == false && number_before_dot == false)
        	return false;

        while (p < n && isspace(s[p]))
        	++ p;

        return p == n;
    }

    bool isblank(string s) {
    	for (int i = 0; i < s.length(); ++ i)
    		if (!isspace(s[i]))
    			return false;
    	return true;
    }

    bool issign(char ch) {
    	return ch == '+' || ch == '-';
    }

	bool isdigit(char ch) {
		return '0' <= ch && ch <= '9';
	}
};


	// bool isNumber0(string s) {
	// 	regex e("[[:blank:]]*[\\+|-]?[0-9]+(.[0-9]+)?(e[\\+|-]?[0-9]+(.[0-9]+)?)?[[:blank:]]*");
	// 	return regex_match(s, e);
	// }


int main() {
	//regex e("[[:blank:]]*(\\+|-)?[0-9]+[.?][[:blank:]]*");
	string s = "  +0e-";
	//cout << Solution().isFloat(s) << endl;
	cout << Solution().isNumber(s) << endl;
	



	return 0;
}