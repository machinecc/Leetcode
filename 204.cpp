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
#include "common.h"


using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int m = sqrt(n) + 1;

        bool isprime[n+1];
        
        fill(isprime, isprime + sizeof(isprime), true);

        
        
        for (int k = 2; k < m; ++ k) {
        	if (isprime[k] == false)
        		continue;

        	int d = k + k;
        	while (d < n) {
        		isprime[d] = false;
        		d += k;
        	}
        }

        int count = 0;
        for (int i = 2; i < n; ++ i)
        	if (isprime[i])
        		++count;
        	

        return count;
    }
};




int main() {
	cout << Solution().countPrimes(2) << endl;


	return 0;
}