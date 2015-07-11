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
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
        	return INT_MAX;

        if (dividend == 0)
        	return 0;


        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        long long d1 = labs(dividend);
        long long d2 = labs(divisor);

        int ans = 0;

        while (d1 >= d2) {
        	long long temp = d2, m = 1;

        	while (d1 >= (temp << 1)) {
        		temp = temp << 1;
        		m = m << 1;
        	}

        	d1 = d1 - temp;
        	ans += m;
        }

        return ans * sign;
    }
};




int main() {
	cout << Solution().divide(100,1) << endl;



	return 0;
}