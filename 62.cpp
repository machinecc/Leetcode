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
    int uniquePaths(int m, int n) {
        if (m < n)
        	swap(m, n);

        if (n == 1)
        	return 1;

        long s = 1;

        for (int i = 1; i <= n - 1; ++ i) {
        	s = s * (m + n - 1 -i) / i;
        }

        return (int)s;
    }
};


int main() {
	cout << Solution().uniquePaths(10,1) << endl;


	return 0;
}