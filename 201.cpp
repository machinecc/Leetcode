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
#include "common.h"

using namespace std;


class Solution {
public:
    int rangeBitwiseAnd0(int m, int n) {
    	int val = m;
        for (int i = val + 1; i <= n; ++ i)
        	val = val & i;

        return val;
    }


    int rangeBitwiseAnd(int m, int n) {
    	

    	int val = m;
        for (int i = val + 1; i <= n; ++ i)
        	val = val & i;

        return val;
    }
};


int main() {


	cout << Solution().rangeBitwiseAnd(5, 7) << endl;
	return 0;
}