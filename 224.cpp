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
    int calculate(string s) {
        stack<string> stk;

        for (int i = 0; i < s.size(); ++ i) {
        	if (isdigit(s[i])) {
        		string number(1, s[i]);
        		while 

        	}
        	else if (s[i] == ')') {
        		string expression = "";

        		while (stk.top() != '(') {
        			expression = stk.top() + expression;
        			stk.pop();
        		}

        		stk.pop();

        		int 
        	}
        	else 
        		stk.push(s[i]);
        }


    }

    int eval(string expression) {

    }

    inline bool isdigit(char ch) {
    	return (ch >= '0' && ch <= '9');
    }
};



int main() {



	return 0;
}