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
    int climbStairs(int n) {
        int* f = new int[n + 1];

        f[0] = 1;
        f[1] = 1;

        for (int i = 2; i <= n; ++ i)
        	f[i] = f[i-1] + f[i-2];

        int ans = f[n];
        
        delete [] f;

        return ans;
    }
};


int main() {



	return 0;
}