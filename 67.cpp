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


using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
    	if (a.empty())
    		return b;

    	if (b.empty())
    		return a;


        if (a.length() > b.length())
        	swap(a, b);

        // n is smaller than m;
        int n = a.length();
        int m = b.length();

        string padding = "";

        for (int i = 0; i < m - n; ++ i)
        	padding = "0" + padding;

        a = padding + a;


        int p = 0;
        int q = 0;
        string s = "";

        for (int i = 0; i < m; ++ i) {
        	p = q + a[m-1-i] - '0' + b[m-1-i] - '0';

        	if (p >= 2) {
        		p -= 2;
        		q = 1;
        	}
        	else {
        		q = 0;
        	}

        	s = string(1, p + '0') + s;
        }

        if (q > 0) 
        	s = "1" + s;

        return s;
    }
};



int main() {
	string s = Solution().addBinary("11", "1");

	cout << s << endl;


	return 0;
}