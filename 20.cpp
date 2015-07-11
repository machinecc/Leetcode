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
    bool isValid(string s) {
        int n = s.length(); 
        stack<int> data;

        for (int i = 0; i < n; ++ i) {
        	int val = convert(s[i]);

        	//cout << val << endl;

        	if (data.size() == 0) {
        		data.push(val);
        		continue;
        	}

        	int top = data.top();
        	//cout << val * top << ' ';
        	//cout << val + top << endl;
        	if (val * top > 0)
        		data.push(val);
        	else if (val * top < 0) {
        		if (val + top == 0) {
        			data.pop();
        		}
        		else
        			return false;
        	}
        }


        if (data.size() == 0)
        	return true;
        else
        	return false;
    }

    int convert(char ch) {
    	int ans = 0;
    	switch (ch) {
    		case '[':
    			ans = 1;
    			break;
    		case ']':
				ans = -1;
				break;
			case '(':
				ans = 2;
				break;
			case ')':
				ans = -2;
				break;
			case '{':
				ans = 3;
				break;
			case '}':
				ans = -3;
				break;
			default:
				break; 
    	}

    	return ans;
    }
};


int main() {

	cout << Solution().isValid("([]){}") << endl;

	return 0;
}