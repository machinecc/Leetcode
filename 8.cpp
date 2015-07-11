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
    int myAtoi(string str) {
    	int i = 0;
    	int n = str.length();

    	while (i < n && isspace(str[i]))
    		++ i;

    	int sign = 1;
    	if (str[i] == '+' || str[i] == '-') {
    		if (str[i] == '-')
    			sign = -1;
    		++ i;
    	}

	  	unsigned long num = 0;

	  	while (i < n) {
	  		if (isdigit(str[i]) == false)
	  			break;

	  		num = num * 10 + str[i] - '0';

	  		if (num >= INT_MAX && sign == 1)
	  			return INT_MAX;

	  		if (num > INT_MAX && sign == -1)
	  			return INT_MIN;

	  		++ i;
	  	}

	  	return sign * num;
    }

    bool isdigit(char ch) {
    	return ('0' <= ch) && (ch <= '9');
    }
};



int main() {
	cout << Solution().myAtoi("-2147483647") << endl;


	return 0;
}