#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <climits>
#include <stack>

using namespace std;


class Solution {
public:
    int longestValidParentheses0(string s) {
    	stack<int> stk;
    	int n = s.length();
    	int maxL = 0;

    	for (int i = 0; i < n; ++ i) {
    		if (stk.empty() == false && s[stk.top()] == '(' && s[i] == ')') {
    			stk.pop();

    			if (!stk.empty()) {
    				maxL = max(maxL, i - stk.top());
    			}
    			else 
    				maxL = max(maxL, i + 1);
    		}
    		else {
    			stk.push(i);
    		}
    	}

    	return maxL;
    }


    int longestValidParentheses(string s) {
    	int n = s.length();
    	int* d = new int[n];
    	d[n-1] = 0;
    	int maxL = 0;

    	for (int i = n - 2; i >= 0; -- i) {
    		//cout << i << endl;
    		if (s[i] == ')')
    			d[i] = 0;
    		else {
    			int j = i + 1 + d[i+1];
    			//cout << "i+1 = " << i+1 << endl;
    			//cout << "d[i+1] = " << d[i+1] << endl;
    			//cout << "j = " << j << endl;
    			if (j < n && s[j] == ')') {
    				d[i] = 2 + d[i+1];

    				if (j+1 < n && s[j+1] == '(')
    					d[i] += d[j+1];
    			}
    			else
    				d[i] = 0;

    			maxL = max(maxL, d[i]);
    		}

    	}

    	
    	delete [] d;

    	return maxL;
    }


};

int main() {
	cout << Solution().longestValidParentheses("(((()") << endl;


	return 0;
}