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
    string intToRoman(int num) {
        unordered_map<int, char> val = { {1,'I'},  {5,'V'}, {10,'X'}, {50,'L'}, {100,'C'}, {500,'D'}, {1000,'M'}};

        int base = 1000;
        string ans = "";
        int s = num;
        int a;

        while (base > 0) {
        	a = s / base;
        	s = s % base;

        	// cout << "a = " << a << endl;
        	// cout << "s = " << s << endl;
        	

        	if (a == 9) {
        		ans = ans + val[base] + val[10*base];
        	}
        	else if ((a <= 8) && (a >= 5)) {
        		ans = ans + val[10 * base / 2] + string(a % 5, val[base]);
        	}
        	else if (a == 4) {
        		ans = ans + val[base] + val[10*base/2];
        	}
        	else if ((a < 4) && (a >= 1)) {
        		ans = ans + string(a, val[base]);
        	}
        	base = base / 10;
        }

        return ans;
    }
};




int main() {
	cout << Solution().intToRoman(1999) << endl;


	return 0;
}