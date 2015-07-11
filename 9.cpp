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
    bool isPalindrome(int _x) {
    	long long int x = _x;

    	if (x < 0)
    		return false;

        long long int n = 1;

        while (n < x) {
        	n = n * 10;
        }

        n = n / 10;

        if (n == 0)
        	return true;


        while (x > 0) {
        	int c1 = x / n;
        	int c2 = x % 10;

        	if (c1 != c2)
        		return false;

        	x = x - c1 * n;
        	x = x / 10;
        	n = n / 100;
        }

        return true;
    }
};




int main() {

	cout << Solution().isPalindrome(-2147447412) << endl;

	return 0;
}