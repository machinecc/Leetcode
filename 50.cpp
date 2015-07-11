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
    double myPow(double x, int n) {
        if (n == 0)
        	return 1;

        if (x == 0)
        	return 0;

        if (n % 2 == 0)
        	return myPow(x * x, n / 2);
        else {
        	if (n > 0)
        		return x * myPow(x, n - 1);
        	else
        		return 1 / x * myPow(x, n + 1);
        }
    }
};


int main() {



	return 0;
}